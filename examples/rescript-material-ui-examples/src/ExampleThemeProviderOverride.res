external styleToString: ReactDOM.Style.t => string = "%identity"

let theme = MaterialUi_Theme.create({
  open MaterialUi_ThemeOptions
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

@react.component
let make = () => {
  open MaterialUi
  <div>
    <MuiThemeProvider theme>
      <Button color=#secondary variant=#outlined>
        <ExampleIcons.SupervisedUserCircle.Filled /> {"Overriden Outline Styles"->React.string}
      </Button>
    </MuiThemeProvider>
  </div>
}
