@react.component
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2)

  let handleChange = (_, newValue) => setValue(newValue->Mui.Any.unsafeToInt)

  <Mui.Paper square=true>
    <Mui.Tabs value indicatorColor=Primary textColor=Primary onChange=handleChange>
      <Mui.Tab label={"Active"->React.string} />
      <Mui.Tab label={"Disabled"->React.string} disabled=true />
      <Mui.Tab label={"Active"->React.string} />
    </Mui.Tabs>
  </Mui.Paper>
}
