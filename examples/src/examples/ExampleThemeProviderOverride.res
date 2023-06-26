let theme = outerTheme =>
  Mui.Theme.create({
    ...outerTheme,
    components: {
      muiButton: {
        styleOverrides: {
          outlined: {
            fontSize: "12px",
            fontWeight: "300",
            color: "gray",
          },
        },
      },
    },
  })

module SupervisedUserCircleIcon = {
  @react.component @module("@mui/icons-material/SupervisedUserCircle")
  external make: (~color: string=?, ~fontSize: string=?) => React.element = "default"
}

@react.component
let make = () =>
  <div>
    <Mui.ThemeProvider theme=Func(theme)>
      <Mui.Button color=Secondary variant=Outlined>
        <SupervisedUserCircleIcon />
        {"Overriden Outline Styles"->React.string}
      </Mui.Button>
    </Mui.ThemeProvider>
  </div>
