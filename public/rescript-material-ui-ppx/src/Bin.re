let () = {
  Migrate_parsetree.Driver.register(
    ~name="withStyles",
    ~args=[],
    Migrate_parsetree.Versions.ocaml_410,
    Mapper.withStylesMapper
  );

  let argv =
    switch (Sys.argv) {
    | [|program, input_file, output_file|] =>
      [|program, input_file, "-o", output_file, "--dump-ast" |]
    | _ =>
      Sys.argv
      /* Or print some error message, because BuckleScript should
         never pass any other pattern of arguments. */
    };

  Migrate_parsetree.Driver.run_main(~argv, ());
};
