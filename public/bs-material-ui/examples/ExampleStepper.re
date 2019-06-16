external jsonTopSpacingFunc: Js.Json.t => (. int) => int = "%identity";
module T = MaterialUi.Theme;
let getSpacing = (theme, num) =>
  theme->T.Theme.spacingGet->jsonTopSpacingFunc(. num)->string_of_int ++ "px";

[%mui.withStyles
  "ExampleStyles"(theme =>
    {
      root: ReactDOMRe.Style.make(~width="90%", ()),
      button:
        ReactDOMRe.Style.make(
          ~marginTop=theme->getSpacing(1),
          ~marginRight=theme->getSpacing(1),
          (),
        ),
      actionsContainer:
        ReactDOMRe.Style.make(~marginBottom=theme->getSpacing(2), ()),
      resetContainer:
        ReactDOMRe.Style.make(~padding=theme->getSpacing(3), ()),
    }
  )
];

let getSteps = () => [|
  "Select campaign settings",
  "Create an ad group",
  "Create an ad",
|];

let getStepContent = (step: int) => {
  let stepContent = [|
    {|For each ad campaign that you create, you can control how much
              you're willing to spend on clicks and conversions, which networks
              and geographical locations you want your ads to show on, and more.|},
    {|An ad group contains one or more ads which target a shared set of keywords.|},
    {|Try out different ad text to see what brings in the most customers,
              and learn how to enhance your ads using features like ad extensions.
              If you run into any problems with your ads, find out how to tell if
              they're running and how to resolve approval issues.|},
  |];
  switch (stepContent->Belt.Array.get(step)) {
  | None => "Unknown Step"
  | Some(content) => content
  };
};

[@react.component]
let make = () => {
  let classes = ExampleStyles.useStyles();
  let (activeStep, setActiveStep) = React.useReducer((_, step) => step, 0);
  let steps = getSteps();

  let handleNext = _ => {
    setActiveStep(activeStep + 1);
  };

  let handleBack = _ => {
    setActiveStep(activeStep - 1);
  };

  let handleReset = _ => {
    setActiveStep(0);
  };

  MaterialUi.(
    <div className={classes.root}>
      <Stepper activeStep={`Int(activeStep)} orientation=`Vertical>
        {steps->Belt.Array.mapWithIndex((index, label) =>
           <Step key=label>
             <StepLabel> label->React.string </StepLabel>
             <StepContent>
               <Typography>
                 {getStepContent(index)->React.string}
               </Typography>
               <div className={classes.actionsContainer}>
                 <div>
                   <Button
                     disabled={activeStep === 0}
                     onClick=handleBack
                     className={classes.button}>
                     "Back"->React.string
                   </Button>
                   <Button
                     variant=`Contained
                     color=`Primary
                     onClick=handleNext
                     className={classes.button}>
                     {activeStep === steps->Belt.Array.length - 1
                        ? "Finish" : "Next"}
                     ->React.string
                   </Button>
                 </div>
               </div>
             </StepContent>
           </Step>
         )}
      </Stepper>
      {activeStep === steps->Belt.Array.length
         ? <Paper
             square=true
             elevation={`Int(0)}
             className={classes.resetContainer}>
             <Typography>
               {j|All steps completed - you're finished|j}->React.string
             </Typography>
             <Button
               onClick=handleReset className={classes.button} color=`Secondary>
               "Reset"->React.string
             </Button>
           </Paper>
         : React.null}
    </div>
  );
};