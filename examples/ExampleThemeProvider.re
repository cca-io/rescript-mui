open MaterialUi;

let theme =
  Theme.create(
    ThemeOptions.(
      make(
        ~palette=PaletteOptions.make(~primary={"main": "#0096F0"}, ()),
        (),
      )
    ),
  );