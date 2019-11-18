open Ast_402;
open Asttypes;
open Parsetree;

let raiseError = (loc: Location.t, message: option(string)) =>
  raise(
    Location.Error(
      Location.error(
        ~loc,
        switch (message) {
        | Some(m) => m
        | None => "[%mui.withStyles] accepts a string with a record / theme => record"
        },
      ),
    ),
  );

type ret =
  | Record(string, list((loc(Longident.t), expression)))
  | Func(string, expression, list((loc(Longident.t), expression)))
  | Error(Location.t);

let analyse = tpl => {
  let (pstr, loc) = tpl;
  let replace =
    switch (List.length(pstr), pstr) {
    | (1, [{pstr_desc: Pstr_eval(expr, _), pstr_loc}]) =>
      switch (expr) {
      | {pexp_desc: Pexp_apply(expr, args)} =>
        switch (expr) {
        | {pexp_desc: Pexp_constant(Const_string(moduleName, None))} =>
          switch (List.length(args), args) {
          | (1, [(_label, {pexp_desc: Pexp_record(entries, _)})]) =>
            Record(moduleName, entries)
          | (1, [(_label, exp)]) =>
            switch (exp) {
            | {pexp_desc: Pexp_fun(_, None, _, body)} =>
              switch (Get.getLastExpression(body)) {
              | {pexp_desc: Pexp_record(entries, _)} =>
                Func(moduleName, exp, entries)
              | _ => Error(pstr_loc)
              }

            | _ => Error(pstr_loc)
            }
          | _ => Error(pstr_loc)
          }
        | _ => Error(pstr_loc)
        }
      | _ => Error(pstr_loc)
      }
    | _ => Error(loc)
    };
  switch (replace) {
  | Record(moduleName, entries) =>
    let typeModuleName = [@warning "-3"] String.uncapitalize(moduleName);
    let keys =
      entries
      |> List.map(entry => {
           let (name, _) = entry;
           switch (name.txt) {
           | Longident.Lident(s) => s
           | _ => "none"
           };
         });
    [
      Generate.genRecordType(
        typeModuleName ++ "Crs",
        keys |> List.map(k => (k, "string")),
        [],
      ),
      Generate.genModuleTemplate(
        moduleName ++ "Defs",
        typeModuleName ++ "Crs",
        [
          Generate.genRecordType(
            "classRecord",
            keys |> List.map(k => (k, "ReactDOMRe.Style.t")),
            [
              (
                Location.mknoloc("bs.deriving"),
                PStr([
                  Ast_helper.Str.eval(
                    Ast_helper.Exp.ident(
                      Location.mknoloc(Longident.Lident("jsConverter")),
                    ),
                  ),
                ]),
              ),
            ],
          ),
          Generate.genJsType(
            "classRecordJs",
            keys |> List.map(k => (k, "ReactDOMRe.Style.t")),
          ),
          Generate.genValueBinding(
            "classes",
            Ast_helper.Exp.construct(
              Location.mknoloc(
                Longident.parse("MaterialUi_WithStyles.Record"),
              ),
              Some(Ast_helper.Exp.record(entries, None)),
            ),
          ),
          Generate.genTypeFromType(
            "classRecordStrings",
            typeModuleName ++ "Crs",
          ),
          Generate.genJsType(
            "classRecordStringsJs",
            keys |> List.map(k => (k, "string")),
          ),
          Generate.genJsRecordConverter("classRecordStringsFromJs", keys),
        ],
      ),
      Generate.genModuleApply(moduleName, moduleName ++ "Defs"),
    ];
  | Func(moduleName, func, entries) =>
    let typeModuleName = [@warning "-3"] String.uncapitalize(moduleName);
    let keys =
      entries
      |> List.map(entry => {
           let (name, _) = entry;
           switch (name.txt) {
           | Longident.Lident(s) => s
           | _ => "none"
           };
         });
    [
      Generate.genRecordType(
        typeModuleName ++ "Crs",
        keys |> List.map(k => (k, "string")),
        [],
      ),
      Generate.genModuleTemplate(
        moduleName ++ "Defs",
        typeModuleName ++ "Crs",
        [
          Generate.genRecordType(
            "classRecord",
            keys |> List.map(k => (k, "ReactDOMRe.Style.t")),
            [
              (
                Location.mknoloc("bs.deriving"),
                PStr([
                  Ast_helper.Str.eval(
                    Ast_helper.Exp.ident(
                      Location.mknoloc(Longident.Lident("jsConverter")),
                    ),
                  ),
                ]),
              ),
            ],
          ),
          Generate.genJsType(
            "classRecordJs",
            keys |> List.map(k => (k, "ReactDOMRe.Style.t")),
          ),
          Generate.genValueBinding(
            "classes",
            Ast_helper.Exp.construct(
              Location.mknoloc(
                Longident.parse("MaterialUi_WithStyles.ThemeFunc"),
              ),
              Some(func),
            ),
          ),
          Generate.genTypeFromType(
            "classRecordStrings",
            typeModuleName ++ "Crs",
          ),
          Generate.genJsType(
            "classRecordStringsJs",
            keys |> List.map(k => (k, "string")),
          ),
          Generate.genJsRecordConverter("classRecordStringsFromJs", keys),
        ],
      ),
      Generate.genModuleApply(moduleName, moduleName ++ "Defs"),
    ];
  | Error(loc) => raiseError(loc, None)
  };
};