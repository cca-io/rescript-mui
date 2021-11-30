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

let createOptionsWithTypeConstraint = (fields: rawFields) => {
  let keys = parseFields(fields);
  [
    Str.type_(
      Nonrecursive,
      [
        Type.mk(
          ~kind=
            Ptype_record(
              keys
              |> List.fold_left(
                   (prev, (name, loc)) =>
                     switch (name) {
                     | "defaultTheme" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(
                               Longident.parse("Mui.ThemeOptions.t"),
                             ),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | "name" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(Longident.Lident("string")),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | "flip" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(
                               Longident.parse("Js.nullable"),
                             ),
                             [
                               Typ.constr(
                                 Location.mknoloc(Longident.Lident("bool")),
                                 [],
                               ),
                             ],
                           ),
                         ),
                         ...prev,
                       ]
                     | "generateId" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.arrow(
                             Nolabel,
                             Typ.constr(
                               Location.mknoloc(Longident.Lident("unit")),
                               [],
                             ),
                             Typ.constr(
                               Location.mknoloc(Longident.Lident("string")),
                               [],
                             ),
                           ),
                         ),
                         ...prev,
                       ]
                     | "classNamePrefix" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(Longident.Lident("string")),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | "media" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(Longident.Lident("string")),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | "meta" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(Longident.Lident("string")),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | "index" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(Longident.Lident("int")),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | "link" => [
                         Type.field(
                           ~loc,
                           Location.mkloc(name, loc),
                           Typ.constr(
                             Location.mknoloc(Longident.Lident("bool")),
                             [],
                           ),
                         ),
                         ...prev,
                       ]
                     | _ => prev
                     },
                   [],
                 ),
            ),
          Location.mknoloc("options"),
        ),
      ],
    ),
    Str.value(
      Nonrecursive,
      [
        Vb.mk(
          Pat.constraint_(
            Pat.var(Location.mknoloc("options")),
            Typ.constr(Location.mknoloc(Longident.parse("options")), []),
          ),
          Exp.record(fields, None),
        ),
      ],
    ),
  ];
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
    createRecordTypeExpression(~keys, ~mapTo="ReactDOM.Style.t", "styles"),
    Typ.arrow(
      Nolabel,
      Typ.constr(Location.mknoloc(Longident.parse("unit")), []),
      Typ.constr(Location.mknoloc(Longident.parse("classes")), []),
    ),
  );
};

let rewriteMakeStyles = (fields: rawFields, options: option(rawFields)) => {
  let (classTypeExpression, styleTypeExpression, useStylesTypeExpression) =
    getTypeExpressions(fields);

  Mod.constraint_(
    Mod.mk(
      Pmod_structure(
        List.append(
          switch (options) {
          | None => []
          | Some(options) => createOptionsWithTypeConstraint(options)
          },
          [
            Str.module_(
              Mb.mk(
                Location.mknoloc(Some("Styles")),
                Mod.mk(
                  Pmod_structure([
                    Str.type_(Nonrecursive, [styleTypeExpression]),
                  ]),
                ),
              ),
            ),
            Str.type_(
              Recursive,
              [
                classTypeExpression,
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
                        Exp.constant(
                          Const.string("@material-ui/core/styles"),
                        ),
                      ),
                    ]),
                  ),
                ],
                ~prim=["makeStyles"],
                Location.mknoloc("makeStyles"),
                Typ.arrow(
                  Nolabel,
                  Typ.constr(
                    Location.mknoloc(Longident.parse("Styles.styles")),
                    [],
                  ),
                  switch (options) {
                  | None =>
                    Typ.constr(
                      Location.mknoloc(Longident.parse("useStyles")),
                      [],
                    )
                  | Some(_) =>
                    Typ.arrow(
                      Nolabel,
                      Typ.constr(
                        Location.mknoloc(Longident.parse("options")),
                        [],
                      ),
                      Typ.constr(
                        Location.mknoloc(Longident.parse("useStyles")),
                        [],
                      ),
                    )
                  },
                ),
              ),
            ),
            Str.value(
              Nonrecursive,
              [
                Vb.mk(
                  Ast_helper.Pat.var(Location.mknoloc("useStyles")),
                  Exp.apply(
                    Exp.ident(
                      Location.mknoloc(Longident.parse("makeStyles")),
                    ),
                    [
                      (
                        Nolabel,
                        Exp.constraint_(
                          Exp.record(fields, None),
                          Typ.constr(
                            Location.mknoloc(
                              Longident.parse("Styles.styles"),
                            ),
                            [],
                          ),
                        ),
                      ),
                      ...switch (options) {
                         | None => []
                         | Some(_) => [
                             (
                               Nolabel,
                               Exp.ident(
                                 Location.mknoloc(
                                   Longident.parse("options"),
                                 ),
                               ),
                             ),
                           ]
                         },
                    ],
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
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
    (
      fields: rawFields,
      funcExpr: Parsetree.expression,
      options: option(rawFields),
    ) => {
  let (classTypeExpression, styleTypeExpression, useStylesTypeExpression) =
    getTypeExpressions(fields);
  let themeFuncTypeExpression =
    Type.mk(
      ~kind=Ptype_abstract,
      ~manifest=
        Typ.arrow(
          Nolabel,
          Typ.constr(Location.mknoloc(Longident.parse("Mui.Theme.t")), []),
          Typ.constr(
            Location.mknoloc(Longident.parse("Styles.styles")),
            [],
          ),
        ),
      Location.mknoloc("themeFunc"),
    );

  Mod.constraint_(
    Mod.mk(
      Pmod_structure(
        List.append(
          switch (options) {
          | None => []
          | Some(options) => createOptionsWithTypeConstraint(options)
          },
          [
            Str.module_(
              Mb.mk(
                Location.mknoloc(Some("Styles")),
                Mod.mk(
                  Pmod_structure([
                    Str.type_(Nonrecursive, [styleTypeExpression]),
                  ]),
                ),
              ),
            ),
            Str.type_(
              Recursive,
              [
                classTypeExpression,
                themeFuncTypeExpression,
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
                        Exp.constant(
                          Const.string("@material-ui/core/styles"),
                        ),
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
                  switch (options) {
                  | None =>
                    Typ.constr(
                      Location.mknoloc(Longident.parse("useStyles")),
                      [],
                    )
                  | Some(_) =>
                    Typ.arrow(
                      Nolabel,
                      Typ.constr(
                        Location.mknoloc(Longident.parse("options")),
                        [],
                      ),
                      Typ.constr(
                        Location.mknoloc(Longident.parse("useStyles")),
                        [],
                      ),
                    )
                  },
                ),
              ),
            ),
            Str.value(
              Nonrecursive,
              [
                Vb.mk(
                  Ast_helper.Pat.var(Location.mknoloc("useStyles")),
                  Exp.apply(
                    Exp.ident(
                      Location.mknoloc(Longident.parse("makeStyles")),
                    ),
                    [
                      (Nolabel, funcExpr),
                      ...switch (options) {
                         | None => []
                         | Some(_) => [
                             (
                               Nolabel,
                               Exp.ident(
                                 Location.mknoloc(
                                   Longident.parse("options"),
                                 ),
                               ),
                             ),
                           ]
                         },
                    ],
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
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
