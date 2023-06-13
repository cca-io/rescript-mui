open Mui

let getSpacing = (theme: Theme.t, num) => theme.spacing(num)->string_of_int ++ "px"

let useStyles = Styles.makeStylesWithTheme(theme =>
  {
    "root": {JsxDOMStyle.width: "90%"},
    "button": {JsxDOMStyle.marginTop: theme->getSpacing(1), marginRight: theme->getSpacing(1)},
    "actionsContainer": {JsxDOMStyle.marginBottom: theme->getSpacing(2)},
    "resetContainer": {JsxDOMStyle.padding: theme->getSpacing(3)},
  }
)

let getSteps = () => ["Select campaign settings", "Create an ad group", "Create an ad"]

let getStepContent = (step: int) => {
  let stepContent = [
    `For each ad campaign that you create, you can control how much
              you're willing to spend on clicks and conversions, which networks
              and geographical locations you want your ads to show on, and more.`,
    `An ad group contains one or more ads which target a shared set of keywords.`,
    `Try out different ad text to see what brings in the most customers,
              and learn how to enhance your ads using features like ad extensions.
              If you run into any problems with your ads, find out how to tell if
              they're running and how to resolve approval issues.`,
  ]
  switch stepContent->Belt.Array.get(step) {
  | None => "Unknown Step"
  | Some(content) => content
  }
}

@react.component
let make = () => {
  let classes = useStyles()
  let (activeStep, setActiveStep) = React.useReducer((_, step) => step, 0)
  let steps = getSteps()

  let handleNext = _ => setActiveStep(activeStep + 1)

  let handleBack = _ => setActiveStep(activeStep - 1)

  let handleReset = _ => setActiveStep(0)

  <div className={classes["root"]}>
    <Stepper activeStep orientation=Vertical>
      {steps
      ->Belt.Array.mapWithIndex((index, label) =>
        <Step key=label>
          <StepLabel> {label->React.string} </StepLabel>
          <StepContent>
            <Typography> {getStepContent(index)->React.string} </Typography>
            <div className={classes["actionsContainer"]}>
              <div>
                <Button
                  disabled={activeStep === 0} onClick=handleBack className={classes["button"]}>
                  {"Back"->React.string}
                </Button>
                <Button
                  variant=Contained color=Primary onClick=handleNext className={classes["button"]}>
                  {(activeStep === steps->Belt.Array.length - 1 ? "Finish" : "Next")->React.string}
                </Button>
              </div>
            </div>
          </StepContent>
        </Step>
      )
      ->React.array}
    </Stepper>
    {activeStep === steps->Belt.Array.length
      ? <Paper square=true elevation=0 className={classes["resetContainer"]}>
          <Typography> {`All steps completed - you're finished`->React.string} </Typography>
          <Button onClick=handleReset className={classes["button"]} color=Secondary>
            {"Reset"->React.string}
          </Button>
        </Paper>
      : React.null}
  </div>
}
