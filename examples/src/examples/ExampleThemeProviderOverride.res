external styleToString: ReactDOM.Style.t => string = "%identity"

let theme = MaterialUi.Theme.create({
  open MaterialUi.ThemeOptions
  make(
    ~overrides=Overrides.make(
      ~\"MuiButton"=ButtonClassKey.make(
        ~outlined=ReactDOM.Style.make(
          ~fontSize="12px",
          ~fontWeight="300",
          ~color="gray",
          (),
        )->ReactDOM.Style.unsafeAddProp(
          "& svg",
          ReactDOM.Style.make(~marginRight="15px", ~fontSize="16px", ())->styleToString,
        ),
        (),
      ),
      (),
    ),
    (),
  )
})

module SupervisedUserCircleIcon = {
  @react.component @module("@material-ui/icons/SupervisedUserCircle")
  external make: (~color: string=?, ~fontSize: string=?) => React.element = "default"
}

@react.component
let make = () => {
  open MaterialUi
  <div>
    <ThemeProvider theme>
      <Button color=#secondary variant=#outlined>
        <SupervisedUserCircleIcon /> {"Overriden Outline Styles"->React.string}
      </Button>
    </ThemeProvider>
  </div>
}
