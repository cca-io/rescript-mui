@react.component
let make = () => {
  open MaterialUi
  <Box
    component={Box.Component.string("span")}
    style={ReactDOM.Style.make(~boxSizing="border-box", ())}
    p={Box.Value.breakpointObj(
      Box.BreakpointObj.make(~sm=Box.Value.int(2), ~md=Box.Value.int(5), ()),
    )}
    m={Box.Value.array({
      open Box.Value
      [int(2), int(5)]
    })}
    borderTop={Box.Value.int(1)}
    borderColor={Box.Value.paletteColor(#"error.main")}
    color={Box.Value.paletteColor(#"text.secondary")}
    bgcolor={Box.Value.paletteColor(#"background.paper")}
    fontSize={Box.Value.string("30px")}>
    {"Testbox"->React.string}
  </Box>
}
