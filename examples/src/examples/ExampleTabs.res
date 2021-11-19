@react.component
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2)

  let handleChange = (_, newValue) => setValue(newValue->MaterialUi.Types.anyUnpack)

  open MaterialUi
  <Paper square=true>
    <Tabs value=Any(value) indicatorColor=#primary textColor=#primary onChange=handleChange>
      <Tab label={"Active"->React.string} />
      <Tab label={"Disabled"->React.string} disabled=true />
      <Tab label={"Active"->React.string} />
    </Tabs>
  </Paper>
}
