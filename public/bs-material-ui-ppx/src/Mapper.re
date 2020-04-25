open Migrate_parsetree;
open Ast_410;
open Asttypes;
open Parsetree;

let withStylesMapper = (_argv, _) => {
  ...Ast_mapper.default_mapper,
  module_expr: (mapper, mexpr) => {
    switch (mexpr) {
    | {pmod_desc: Pmod_extension(({txt: "makeStyles", loc}, pstr)), _} =>
      switch (pstr) {
      | PStr([
          {
            pstr_desc:
              Pstr_eval({pexp_desc: Pexp_record(fields, None), _}, _),
            _,
          },
        ]) =>
        NewImplementation.rewriteMakeStyles(fields)
      | PStr([
          {
            pstr_desc:
              Pstr_eval(
                {
                  pexp_desc:
                    Pexp_fun(
                      _,
                      _,
                      _,
                      {pexp_desc: Pexp_record(fields, None), _},
                    ),
                  _,
                } as fn,
                _,
              ),
            _,
          },
        ]) =>
        NewImplementation.rewriteMakeStylesWithTheme(fields, fn)
      | _ => Utils.raiseError(~loc, None)
      }

    | other => Ast_mapper.default_mapper.module_expr(mapper, other)
    };
  },
};