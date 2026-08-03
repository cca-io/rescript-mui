open NodeJs

let getComponentsWithClasses = path => {
  let components = Fs.readdirSync(path)

  let muiNames = []

  let classKeys =
    components
    ->Array.filterMap(filename =>
      if filename->String.endsWith(".res") {
        let fileContent = Fs.readFileSync(Path.join([path, filename]), {encoding: "utf8"})
        let fileByLines = fileContent->String.split("\n")

        let classesBegin =
          fileByLines->Array.findIndexOpt(line => line->String.startsWith("type classes = {"))

        switch classesBegin {
        | None => None
        | Some(begin) =>
          let beginSlice = fileByLines->Array.slice(~start=begin)
          let classesEnd = beginSlice->Array.findIndexOpt(line => line->String.startsWith("}"))

          switch classesEnd {
          | None => None
          | Some(end) =>
            let classes =
              beginSlice
              ->Array.slice(~start=1, ~end)
              ->Array.map(String.trim)
              ->Array.filterMap(line =>
                line->String.startsWith("//") ||
                line->String.startsWith("/*") ||
                line->String.startsWith("*") ||
                line->String.startsWith("...")
                  ? None
                  : Some({
                      let newLine =
                        line->String.startsWith("color")
                          ? line
                          : line->String.replaceRegExp(
                              RegExp.fromString("string"),
                              "ReactDOM.Style.t",
                            )
                      "  " ++ newLine
                    })
              )
            let typeName =
              filename->String.substring(~start=0, ~end=filename->String.length - 4)

            let typeNameLowercaseFirst =
              typeName->String.charAt(0)->String.toLowerCase ++
              typeName->String.slice(~start=1) ++ "ClassKey"

            let havePropsTypeParameter =
              fileByLines->Array.find(line => line->String.startsWith("type props"))

            // Emit the right number of `unknown` type arguments based on the props type parameters.
            let typeArgs = switch havePropsTypeParameter {
            | None => ""
            | Some(line) =>
              let beforeEq = switch line->String.indexOf(" = ") {
              | -1 => line
              | idx => line->String.substring(~start=0, ~end=idx)
              }
              switch (beforeEq->String.indexOf("<"), beforeEq->String.indexOf(">")) {
              | (lt, gt) if lt >= 0 && gt > lt =>
                let count =
                  beforeEq
                  ->String.substring(~start=lt + 1, ~end=gt)
                  ->String.split(",")
                  ->Array.length
                "<" ++ Array.make(~length=count, "unknown")->Array.join(", ") ++ ">"
              | _ => ""
              }
            }

            let muiName = `  @as("Mui${typeName}") mui${typeName}?: component<${typeNameLowercaseFirst}, ${typeName}.props${typeArgs}>,`

            let classesBody = " = {\n" ++ classes->Array.join("\n") ++ "\n}\n"

            muiNames->Array.push(muiName)

            Some("type " ++ typeNameLowercaseFirst ++ classesBody)
          }
        }
      } else {
        None
      }
    )
    ->Array.join("\n")

  `// This file is generated automatically by helpers/src/GenerateOverrides.res. Do not edit manually!

type component<'classKey, 'props> = {
  defaultProps?: 'props,
  styleOverrides?: 'classKey,
}

${classKeys}
type t = {
${muiNames->Array.join("\n")}
}
`
}

let muiOverrides = getComponentsWithClasses("./packages/rescript-mui-material/src/components")
let labOverrides = getComponentsWithClasses("./packages/rescript-mui-lab/src")

Fs.writeFileSync(
  "./packages/rescript-mui-material/src/types/Overrides.res",
  muiOverrides,
  {encoding: "utf8"},
)

Fs.writeFileSync("./packages/rescript-mui-lab/src/Overrides.res", labOverrides, {encoding: "utf8"})
