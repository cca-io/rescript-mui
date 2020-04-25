open Migrate_parsetree;
open Ast_410;
open Ast_helper;

type rawFields = list((Asttypes.loc(Longident.t), Parsetree.expression));

let parseFields = (fields: rawFields) => {
  fields
  |> List.fold_left(
       (prev, field) => {
         switch (field) {
         | (
             {txt: Longident.Lident(name), loc}: Asttypes.loc(Longident.t),
             _,
           ) => [
             (name, loc),
             ...prev,
           ]
         | _ => prev
         }
       },
       [],
     );
};

let createRecordTypeExpression =
    (
      ~keys: list((string, Migrate_parsetree__Ast_410.Location.t)),
      ~mapTo: string,
      name: string,
    ) => {
  Type.mk(
    ~kind=
      Ptype_record(
        keys
        |> List.map(((name, loc)) => {
             Type.field(
               ~loc,
               Location.mkloc(name, loc),
               Typ.constr(Location.mknoloc(Longident.parse(mapTo)), []),
             )
           }),
      ),
    Location.mknoloc(name),
  );
};

let getTypeExpressions = (fields: rawFields) => {
  let keys = fields |> parseFields;
  (
    createRecordTypeExpression(~keys, ~mapTo="string", "classes"),
    createRecordTypeExpression(~keys, ~mapTo="ReactDOMRe.Style.t", "styles"),
    Typ.arrow(
      Nolabel,
      Typ.constr(Location.mknoloc(Longident.parse("unit")), []),
      Typ.constr(Location.mknoloc(Longident.parse("classes")), []),
    ),
  );
};

let rewriteMakeStyles = (fields: rawFields) => {
  let (classTypeExpression, styleTypeExpression, useStylesTypeExpression) =
    getTypeExpressions(fields);

  Mod.constraint_(
    Mod.mk(
      Pmod_structure([
        Str.type_(Nonrecursive, [classTypeExpression]),
        Str.type_(Nonrecursive, [styleTypeExpression]),
        Str.type_(
          Nonrecursive,
          [
            Type.mk(
              ~kind=Ptype_abstract,
              ~manifest=useStylesTypeExpression,
              Location.mknoloc("useStyles"),
            ),
          ],
        ),
        Str.primitive(
          Val.mk(
            ~attrs=[
              Attr.mk(
                Location.mknoloc("bs.module"),
                PStr([
                  Str.eval(
                    Exp.constant(Const.string("@material-ui/core/styles")),
                  ),
                ]),
              ),
            ],
            ~prim=["makeStyles"],
            Location.mknoloc("makeStyles"),
            Typ.arrow(
              Nolabel,
              Typ.constr(Location.mknoloc(Longident.parse("styles")), []),
              Typ.constr(
                Location.mknoloc(Longident.parse("useStyles")),
                [],
              ),
            ),
          ),
        ),
        Str.value(
          Nonrecursive,
          [
            Vb.mk(
              Ast_helper.Pat.var(Location.mknoloc("useStyles")),
              Exp.apply(
                Exp.ident(Location.mknoloc(Longident.parse("makeStyles"))),
                [(Nolabel, Exp.record(fields, None))],
              ),
            ),
          ],
        ),
      ]),
    ),
    Mty.mk(
      Pmty_signature([
        Sig.type_(Nonrecursive, [classTypeExpression]),
        Sig.value(
          Val.mk(Location.mknoloc("useStyles"), useStylesTypeExpression),
        ),
      ]),
    ),
  );
};

let rewriteMakeStylesWithTheme =
    (fields: rawFields, funcExpr: Parsetree.expression) => {
  let (classTypeExpression, styleTypeExpression, useStylesTypeExpression) =
    getTypeExpressions(fields);
  let themeFuncTypeExpression =
    Type.mk(
      ~kind=Ptype_abstract,
      ~manifest=
        Typ.arrow(
          Nolabel,
          Typ.constr(
            Location.mknoloc(Longident.parse("MaterialUi.Theme.t")),
            [],
          ),
          Typ.constr(Location.mknoloc(Longident.parse("styles")), []),
        ),
      Location.mknoloc("themeFunc"),
    );

  Mod.constraint_(
    Mod.mk(
      Pmod_structure([
        Str.type_(Nonrecursive, [classTypeExpression]),
        Str.type_(Nonrecursive, [styleTypeExpression]),
        Str.type_(Nonrecursive, [themeFuncTypeExpression]),
        Str.type_(
          Nonrecursive,
          [
            Type.mk(
              ~kind=Ptype_abstract,
              ~manifest=useStylesTypeExpression,
              Location.mknoloc("useStyles"),
            ),
          ],
        ),
        Str.primitive(
          Val.mk(
            ~attrs=[
              Attr.mk(
                Location.mknoloc("bs.module"),
                PStr([
                  Str.eval(
                    Exp.constant(Const.string("@material-ui/core/styles")),
                  ),
                ]),
              ),
            ],
            ~prim=["makeStyles"],
            Location.mknoloc("makeStyles"),
            Typ.arrow(
              Nolabel,
              Typ.constr(
                Location.mknoloc(Longident.parse("themeFunc")),
                [],
              ),
              Typ.constr(
                Location.mknoloc(Longident.parse("useStyles")),
                [],
              ),
            ),
          ),
        ),
        Str.value(
          Nonrecursive,
          [
            Vb.mk(
              Ast_helper.Pat.var(Location.mknoloc("useStyles")),
              Exp.apply(
                Exp.ident(Location.mknoloc(Longident.parse("makeStyles"))),
                [(Nolabel, funcExpr)],
              ),
            ),
          ],
        ),
      ]),
    ),
    Mty.mk(
      Pmty_signature([
        Sig.type_(Nonrecursive, [classTypeExpression]),
        Sig.value(
          Val.mk(Location.mknoloc("useStyles"), useStylesTypeExpression),
        ),
      ]),
    ),
  );
};