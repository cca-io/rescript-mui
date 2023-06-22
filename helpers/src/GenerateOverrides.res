open Belt
open NodeJs

let getComponentsWithClasses = path => {
  let components = Fs.readdirSync(path)

  let muiNames = []

  let classKeys =
    components
    ->Array.keepMap(filename =>
      if filename->Js.String2.endsWith(".res") {
        let fileContent = Fs.readFileSync(Path.join([path, filename]), {encoding: "utf8"})
        let fileByLines = fileContent->Js.String2.split("\n")

        let classesBegin =
          fileByLines->Array.getIndexBy(line => line->Js.String2.startsWith("type classes = {"))

        switch classesBegin {
        | None => None
        | Some(begin) =>
          let beginSlice = fileByLines->Array.sliceToEnd(begin)
          let classesEnd = beginSlice->Array.getIndexBy(line => line->Js.String2.startsWith("}"))

          switch classesEnd {
          | None => None
          | Some(end) =>
            let classes =
              beginSlice
              ->Array.slice(~offset=1, ~len=end - 1)
              ->Array.map(Js.String.trim)
              ->Array.keepMap(line =>
                line->Js.String2.startsWith("//") ||
                line->Js.String2.startsWith("/*") ||
                line->Js.String2.startsWith("*") ||
                line->Js.String2.startsWith("...")
                  ? None
                  : Some({
                      let newLine =
                        line->Js.String2.startsWith("color")
                          ? line
                          : line->Js.String2.replaceByRe(
                              Js.Re.fromString("string"),
                              "ReactDOM.Style.t",
                            )
                      "  " ++ newLine
                    })
              )
            let typeName =
              filename->Js.String2.substring(~from=0, ~to_=filename->Js.String2.length - 4)

            let typeNameLowercaseFirst =
              typeName->Js.String2.charAt(0)->Js.String2.toLowerCase ++
              typeName->Js.String2.sliceToEnd(~from=1) ++ "ClassKey"

            let muiName = `  @as("Mui${typeName}") mui${typeName}?: ${typeNameLowercaseFirst},`

            let classesBody = " = {\n" ++ classes->Js.Array2.joinWith("\n") ++ "\n}\n"

            muiNames->Js.Array2.push(muiName)->ignore

            Some("type " ++ typeNameLowercaseFirst ++ classesBody)
          }
        }
      } else {
        None
      }
    )
    ->Js.Array2.joinWith("\n")

  "// This file is generated automatically by helpers/src/GenerateOverrides.res. Do not edit manually!\n\n" ++
  classKeys ++
  "\n\n" ++
  "type t = {\n" ++
  muiNames->Js.Array2.joinWith("\n") ++ "\n}\n"
}

let muiOverrides = getComponentsWithClasses("./packages/rescript-mui-material/src/components")
let labOverrides = getComponentsWithClasses("./packages/rescript-mui-lab/src")

Fs.writeFileSync(
  "./packages/rescript-mui-material/src/types/Overrides.res",
  muiOverrides,
  {encoding: "utf8"},
)

Fs.writeFileSync("./packages/rescript-mui-lab/src/Overrides.res", labOverrides, {encoding: "utf8"})
