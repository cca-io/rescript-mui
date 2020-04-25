open Migrate_parsetree;
open Ast_410;
open Asttypes;
open Parsetree;

let rec getLastExpression = (exp: expression) =>
  switch (exp) {
  | {pexp_desc: Pexp_sequence(sExp1, sExp2)} => getLastExpression(sExp2)
  | {pexp_desc: Pexp_let(_, _, lExp)} => getLastExpression(lExp)
  | {pexp_desc: Pexp_apply(aExp, _)} => getLastExpression(aExp)
  | {pexp_desc: Pexp_match(e, _)} => getLastExpression(e)
  | {pexp_desc: Pexp_try(e, _)} => getLastExpression(e)
  | {pexp_desc: Pexp_field(e, _)} => getLastExpression(e)
  | {pexp_desc: Pexp_constraint(e, _)} => getLastExpression(e)
  | {pexp_desc: Pexp_coerce(e, _, _)} => getLastExpression(e)
  | {pexp_desc: Pexp_send(e, _)} => getLastExpression(e)
  | {pexp_desc: Pexp_assert(e)} => getLastExpression(e)
  | {pexp_desc: Pexp_lazy(e)} => getLastExpression(e)
  | {pexp_desc: Pexp_poly(e, _)} => getLastExpression(e)
  | other => other
  };
