module H7 = {
  @react.component
  let make = (~children) => <span style={fontWeight: "bold", marginBottom: "4px"}> children </span>
}

@react.component
let make = () =>
  <Mui.Typography component={Mui.OverridableComponent.componentWithUnknownProps(H7.make)}>
    {"This is a custom h7"->React.string}
  </Mui.Typography>
