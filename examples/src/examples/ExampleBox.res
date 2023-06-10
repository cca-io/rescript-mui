@react.component
let make = () =>
  <Mui.Box
    component={Mui.OverridableComponent.string("span")}
    style={JsxDOMStyle.boxSizing: "border-box"}
    p={Breakpoint({sm: Number(2.), md: Number(5.)})}
    m={Array([Number(2.), Number(5.)])}
    borderTop={Number(1.)}
    borderColor={ErrorMain}
    color={TextSecondary}
    bgcolor={BackgroundPaper}
    fontSize={String("30px")}>
    {"Testbox"->React.string}
  </Mui.Box>
