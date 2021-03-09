let theme = MaterialUi_Theme.create({
  open MaterialUi_ThemeOptions
  make(~palette=PaletteOptions.make(~primary=Primary.make(~main="#8fe830", ()), ()), ())
})

@react.component
let make = () => {
  open MaterialUi
  <div>
    <Button color=#Primary variant=#Outlined> {"Default Primary Color"->React.string} </Button>
    {" "->React.string}
    <MuiThemeProvider theme>
      <Button color=#Primary variant=#Outlined> {"Themed Primary Color"->React.string} </Button>
    </MuiThemeProvider>
  </div>
}
