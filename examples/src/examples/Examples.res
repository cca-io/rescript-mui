open Mui

@react.component
let make = () => <>
  <Grid container=true>
    <Grid item=true md=Number(12)>
      <Typography variant=H4> {"ReScript Material-UI Examples"->React.string} </Typography>
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Class Override"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleClassOverride />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Icons"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleIcons />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Popover"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExamplePopover />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Styles"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleStyles />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Theme Provider"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleThemeProvider />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"Theme Provider Override"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleThemeProviderOverride />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"List"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleList />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/tabs/DisabledTabs.tsx"
          target="_blank">
          {"Tabs"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleTabs />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/steppers/VerticalLinearStepper.tsx"
          target="_blank">
          {"Stepper"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleStepper />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/selects/SimpleSelect.tsx"
          target="_blank">
          {"Select"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleSelect />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/radio-buttons/RadioButtonsGroup.tsx"
          target="_blank">
          {"RadioGroup"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleRadioGroup />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/slider/InputSlider.tsx"
          target="_blank">
          {"Slider"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleSlider />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/slider/InputSlider.tsx"
          target="_blank">
          {"Dashboard"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleDashboard sidebar={"Sidebar"->React.string}>
        {"Content"->React.string}
      </ExampleDashboard>
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/box/box.md"
          target="_blank">
          {"Box"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleBox />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/styles/api/api.md#serverstylesheets"
          target="_blank">
          {"ServerStyleSheets"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleServerStyleSheets />
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=String("center")>
    <Grid item=true md=Number(6)>
      <Typography variant=H5> {"TextField size Prop"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Number(6)>
      <ExampleTextFieldSize />
    </Grid>
  </Grid>
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
  <br />
</>
