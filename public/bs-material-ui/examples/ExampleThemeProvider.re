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

[@react.component]
let make = () =>
  MaterialUi.(
    <div>
      <Button color=`Primary variant=`Outlined>
        "Default Primary Color"->React.string
      </Button>
      " "->ReasonReact.string
      <MuiThemeProvider theme>
        <Button color=`Primary variant=`Outlined>
          "Themed Primary Color"->React.string
        </Button>
      </MuiThemeProvider>
    </div>
  );
