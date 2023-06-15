let theme = outerTheme =>
  Mui.Theme.create({
    ...outerTheme,
    palette: {primary: {main: "#8fe830"}},
  })

@react.component
let make = () =>
  <div>
    <Mui.Button color=Primary variant=Outlined>
      {"Default Primary Color"->React.string}
    </Mui.Button>
    {" "->React.string}
    <Mui.ThemeProvider theme>
      <Mui.Button color=Primary variant=Outlined>
        {"Themed Primary Color"->React.string}
      </Mui.Button>
    </Mui.ThemeProvider>
  </div>
