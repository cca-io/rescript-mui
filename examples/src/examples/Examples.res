open MaterialUi

@react.component
let make = () => <>
  <Grid container=true>
    <Grid item=true md=Grid.Md.\"12">
      <Typography variant=#h4> "ReScript Material-UI Examples" </Typography>
    </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Class Override" </Typography> </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleClassOverride /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Icons" </Typography> </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleIcons /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Popover" </Typography> </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExamplePopover /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Styles" </Typography> </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleStyles /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "Theme Provider" </Typography> </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleThemeProvider /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> "Theme Provider Override" </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleThemeProviderOverride /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6"> <Typography variant=#h5> "List" </Typography> </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleList /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/tabs/DisabledTabs.tsx"
          target="_blank">
          {"Tabs"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleTabs /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/steppers/VerticalLinearStepper.tsx"
          target="_blank">
          {"Stepper"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleStepper /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/selects/SimpleSelect.tsx"
          target="_blank">
          {"Select"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleSelect /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/slider/InputSlider.tsx"
          target="_blank">
          {"Slider"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleSlider /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/slider/InputSlider.tsx"
          target="_blank">
          {"Dashboard"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6">
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
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/box/box.md"
          target="_blank">
          {"Box"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleBox /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5>
        <a
          href="https://github.com/mui-org/material-ui/blob/master/docs/src/pages/styles/api/api.md#serverstylesheets"
          target="_blank">
          {"ServerStyleSheets"->React.string}
        </a>
      </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleServerStyleSheets /> </Grid>
  </Grid>
  <br />
  <br />
  <Divider />
  <br />
  <br />
  <Grid container=true alignItems=#center>
    <Grid item=true md=Grid.Md.\"6">
      <Typography variant=#h5> {"TextField size Prop"->React.string} </Typography>
    </Grid>
    <Grid item=true md=Grid.Md.\"6"> <ExampleTextFieldSize /> </Grid>
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
