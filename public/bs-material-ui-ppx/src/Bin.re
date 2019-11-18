open Migrate_parsetree;

let () =
  Migrate_parsetree.Driver.register(
    ~name="withstyles",
    ~args=[],
    Migrate_parsetree.Versions.ocaml_402,
    Mapper.withStylesMapper,
  );

Driver.run_as_ppx_rewriter();