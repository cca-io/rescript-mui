@react.component
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2)

  let handleChange = (_, newValue) => setValue(newValue->MaterialUi.anyUnpack)

  open MaterialUi
  <Paper square=true>
    <Tabs value=Any(value) indicatorColor=#Primary textColor=#Primary onChange=handleChange>
      <Tab label={"Active"->React.string} />
      <Tab label={"Disabled"->React.string} disabled=true />
      <Tab label={"Active"->React.string} />
    </Tabs>
  </Paper>
}
