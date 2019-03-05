open Asttypes;
open Parsetree;

let genTypeFromType = (name: string, typeName: string) =>
  Ast_helper.Str.type_([
    Ast_helper.Type.mk(
      ~manifest={
        ptyp_desc:
          Ptyp_constr(Location.mknoloc(Longident.Lident(typeName)), []),
        ptyp_loc: Location.none,
        ptyp_attributes: [],
      },
      Location.mknoloc(name),
    ),
  ]);

let genRecordTypeWithCore =
    (name: string, entries: list((string, core_type)), attrs: list(string)) =>
  Ast_helper.Str.type_([
    Ast_helper.Type.mk(
      ~kind=
        Ptype_record(
          List.map(
            entry => {
              let (name, typ) = entry;
              {
                pld_name: Location.mknoloc(name),
                pld_mutable: Immutable,
                pld_type: typ,
                pld_loc: Location.none,
                pld_attributes: [],
              };
            },
            entries,
          ),
        ),
      ~attrs=List.map(a => (Location.mknoloc(a), PStr([])), attrs),
      Location.mknoloc(name),
    ),
  ]);

let genRecordType = (name: string, entries: list((string, string)), attrs) =>
  Ast_helper.Str.type_([
    Ast_helper.Type.mk(
      ~kind=
        Ptype_record(
          List.map(
            entry => {
              let (name, typ) = entry;
              {
                pld_name: Location.mknoloc(name),
                pld_mutable: Immutable,
                pld_type: {
                  ptyp_desc:
                    Ptyp_constr(Location.mknoloc(Longident.parse(typ)), []),
                  ptyp_loc: Location.none,
                  ptyp_attributes: [],
                },
                pld_loc: Location.none,
                pld_attributes: [],
              };
            },
            entries,
          ),
        ),
      ~attrs,
      Location.mknoloc(name),
    ),
  ]);

let genJsType = (name: string, entries: list((string, string))) =>
  Ast_helper.Str.type_([
    Ast_helper.Type.mk(
      ~kind=Ptype_abstract,
      ~manifest={
        ptyp_desc:
          Ptyp_constr(
            Location.mknoloc(Longident.parse("Js.t")),
            [
              {
                ptyp_desc:
                  Ptyp_object(
                    List.map(
                      entry => {
                        let (name, typ) = entry;
                        (
                          name,
                          [],
                          {
                            ptyp_desc:
                              Ptyp_constr(
                                Location.mknoloc(Longident.parse(typ)),
                                [],
                              ),
                            ptyp_loc: Location.none,
                            ptyp_attributes: [],
                          },
                        );
                      },
                      entries,
                    ),
                    Closed,
                  ),
                ptyp_loc: Location.none,
                ptyp_attributes: [],
              },
            ],
          ),
        ptyp_loc: Location.none,
        ptyp_attributes: [],
      },
      Location.mknoloc(name),
    ),
  ]);

let genModule = (name: string, structure: Parsetree.structure) =>
  Ast_helper.Str.module_({
    pmb_name: Location.mknoloc(name),
    pmb_expr: {
      pmod_desc: Pmod_structure(structure),
      pmod_loc: Location.none,
      pmod_attributes: [],
    },
    pmb_attributes: [],
    pmb_loc: Location.none,
  });

let genModuleApply = (name: string, applyTo: string) =>
  Ast_helper.Str.module_({
    pmb_name: Location.mknoloc(name),
    pmb_expr: {
      pmod_desc:
        Pmod_apply(
          {
            pmod_desc:
              Pmod_ident(
                Location.mknoloc(
                  Longident.parse("MaterialUi_WithStyles.WithStylesSafe"),
                ),
              ),
            pmod_loc: Location.none,
            pmod_attributes: [],
          },
          {
            pmod_desc:
              Pmod_ident(Location.mknoloc(Longident.parse(applyTo))),
            pmod_loc: Location.none,
            pmod_attributes: [],
          },
        ),
      pmod_loc: Location.none,
      pmod_attributes: [],
    },
    pmb_attributes: [],
    pmb_loc: Location.none,
  });

let genModuleTemplate =
    (
      name: string,
      classesStringTypeName: string,
      structure: Parsetree.structure,
    ) =>
  Ast_helper.Str.module_({
    pmb_name: Location.mknoloc(name),
    pmb_expr: {
      pmod_desc:
        Pmod_constraint(
          {
            pmod_desc: Pmod_structure(structure),
            pmod_loc: Location.none,
            pmod_attributes: [],
          },
          {
            pmty_desc:
              Pmty_with(
                {
                  pmty_desc:
                    Pmty_ident(
                      Location.mknoloc(
                        Longident.parse(
                          "MaterialUi_WithStyles.WithStylesSafeTemplate",
                        ),
                      ),
                    ),
                  pmty_loc: Location.none,
                  pmty_attributes: [],
                },
                [
                  Pwith_type(
                    Location.mknoloc(Longident.Lident("classRecordStrings")),
                    {
                      ptype_name: Location.mknoloc(classesStringTypeName),
                      ptype_params: [],
                      ptype_cstrs: [],
                      ptype_kind: Ptype_abstract,
                      ptype_private: Public,
                      ptype_manifest:
                        Some({
                          ptyp_desc:
                            Ptyp_constr(
                              Location.mknoloc(
                                Longident.Lident(classesStringTypeName),
                              ),
                              [],
                            ),
                          ptyp_loc: Location.none,
                          ptyp_attributes: [],
                        }),
                      ptype_attributes: [],
                      ptype_loc: Location.none,
                    },
                  ),
                ],
              ),
            pmty_loc: Location.none,
            pmty_attributes: [],
          },
        ),
      pmod_loc: Location.none,
      pmod_attributes: [],
    },
    pmb_attributes: [],
    pmb_loc: Location.none,
  });

let genValueBinding = (name: string, expr) =>
  Ast_helper.Str.value(
    Nonrecursive,
    [Ast_helper.Vb.mk(Ast_helper.Pat.var(Location.mknoloc(name)), expr)],
  );

let genJsRecordConverter = (name: string, entries: list(string)) =>
  genValueBinding(
    name,
    Ast_helper.Exp.fun_(
      "",
      None,
      Ast_helper.Pat.var(Location.mknoloc("arg")),
      Ast_helper.Exp.constraint_(
        Ast_helper.Exp.record(
          List.map(
            entry => (
              Location.mknoloc(Longident.Lident(entry)),
              Ast_helper.Exp.apply(
                Ast_helper.Exp.ident(
                  Location.mknoloc(Longident.Lident("##")),
                ),
                [
                  (
                    "",
                    Ast_helper.Exp.ident(
                      Location.mknoloc(Longident.Lident("arg")),
                    ),
                  ),
                  (
                    "",
                    Ast_helper.Exp.ident(
                      Location.mknoloc(Longident.Lident(entry)),
                    ),
                  ),
                ],
              ),
            ),
            entries,
          ),
          None,
        ),
        Ast_helper.Typ.constr(
          Location.mknoloc(Longident.Lident("classRecordStrings")),
          [],
        ),
      ),
    ),
  );