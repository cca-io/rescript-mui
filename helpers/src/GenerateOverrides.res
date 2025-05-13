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

            let propsTypeLine =
              fileByLines->Belt.Array.getBy(line =>
                line->Js.String2.match_(Js.Re.fromString("^type props<.*> = {")) != None
              )

            let muiName = switch propsTypeLine {
            | Some(line) => {
                let typeParamsMatchOpt =
                  line->Js.String2.match_(Js.Re.fromString("^type props<([^>]*)> = {"))
                switch typeParamsMatchOpt {
                | Some(typeParamsMatch) =>
                  switch typeParamsMatch {
                  | [_, params] => {
                      let paramsStr: string = Obj.magic(params)
                      let paramCount = if Js.String2.length(paramsStr) == 0 {
                        0
                      } else {
                        paramsStr->Js.String2.split(",")->Array.length
                      }
                      let unknowns = if paramCount > 0 {
                        Array.make(paramCount, "unknown")->Js.Array2.joinWith(", ")
                      } else {
                        ""
                      }
                      if paramCount > 0 {
                        `  @as("Mui${typeName}") mui${typeName}?: component<${typeNameLowercaseFirst}, ${typeName}.props<${unknowns}>>,`
                      } else {
                        `  @as("Mui${typeName}") mui${typeName}?: component<${typeNameLowercaseFirst}, ${typeName}.props>,`
                      }
                    }
                  | _ =>
                    `  @as("Mui${typeName}") mui${typeName}?: component<${typeNameLowercaseFirst}, ${typeName}.props>,`
                  }
                | None =>
                  `  @as("Mui${typeName}") mui${typeName}?: component<${typeNameLowercaseFirst}, ${typeName}.props>,`
                }
              }
            | None =>
              `  @as("Mui${typeName}") mui${typeName}?: component<${typeNameLowercaseFirst}, ${typeName}.props>,`
            }

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

  `// This file is generated automatically by helpers/src/GenerateOverrides.res. Do not edit manually!

type component<'classKey, 'props> = {
  defaultProps?: 'props,
  styleOverrides?: 'classKey,
}

${classKeys}
type t = {
${muiNames->Js.Array2.joinWith("\n")}
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
