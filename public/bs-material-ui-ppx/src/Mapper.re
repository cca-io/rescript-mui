open Migrate_parsetree;
open Ast_410;
open Asttypes;
open Parsetree;

let withStylesMapper = (_argv, _) => {
  ...Ast_mapper.default_mapper,
  structure: (mapper, structure) => {
    let rec loop = items =>
      switch (items) {
      | [] => []
      | [
          {
            pstr_desc:
              Pstr_eval(
                {
                  pexp_desc:
                    [@implicit_arity]
                    Pexp_extension({txt: "mui.withStyles"}, pstr),
                },
                _,
              ),
            pstr_loc,
          },
          ...rest,
        ] =>
        let converters =
          switch (pstr) {
          | PStr(pstr) => Replace.analyse((pstr, pstr_loc))
          | _ => []
          };
        List.append(converters, loop(rest));
      | [item, ...rest] => [
          mapper.structure_item(mapper, item),
          ...loop(rest),
        ]
      };
    let items = loop(structure);
    items;
  },
};
