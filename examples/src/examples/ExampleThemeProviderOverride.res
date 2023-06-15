external styleToString: ReactDOM.Style.t => string = "%identity"

let theme = outerTheme =>
  Mui.Theme.create({
    ...outerTheme,
    overrides: {
      muiButton: {
        outlined: {
          fontSize: "12px",
          fontWeight: "300",
          color: "gray",
        }->ReactDOM.Style.unsafeAddProp(
          "& svg",
          {marginRight: "15px", fontSize: "16px"}->styleToString,
        ),
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
    <Mui.ThemeProvider theme>
      <Mui.Button color=Secondary variant=Outlined>
        <SupervisedUserCircleIcon />
        {"Overriden Outline Styles"->React.string}
      </Mui.Button>
    </Mui.ThemeProvider>
  </div>
