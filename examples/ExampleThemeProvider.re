let theme =
  MaterialUi_Theme.create(
    MaterialUi_ThemeOptions.(
      make(
        ~palette=
          PaletteOptions.make(
            ~primary=Primary.make(~main="#8fe830", ()),
            (),
          ),
        (),
      )
    ),
  );

let component = ReasonReact.statelessComponent(__MODULE__);

let make = _ => {
  ...component,
  render: _ =>
    MaterialUi.(
      <div>
        <Button color=`Primary variant=`Outlined>
          "Default Primary Color"
        </Button>
        " "->ReasonReact.string
        <MuiThemeProvider theme>
          <Button color=`Primary variant=`Outlined>
            "Themed Primary Color"
          </Button>
        </MuiThemeProvider>
      </div>
    ),
};