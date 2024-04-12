module H7 = {
  @react.component
  let make = (~children) => <span className="text-small"> children </span>
}

@react.component
let make = (~children) =>
  <Mui.Typography component={Mui.OverridableComponent.componentWithUnknownProps(H7.make)}>
    children
  </Mui.Typography>
