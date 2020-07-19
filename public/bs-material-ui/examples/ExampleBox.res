@react.component
let make = () => {
  open MaterialUi
  <Box
    component={Box.Component.string("span")}
    style={ReactDOMRe.Style.make(~boxSizing="border-box", ())}
    p={Box.Value.breakpointObj(
      Box.BreakpointObj.make(~sm=Box.Value.int(2), ~md=Box.Value.int(5), ()),
    )}
    m={Box.Value.array({
      open Box.Value
      [int(2), int(5)]
    })}
    borderTop={Box.Value.int(1)}
    borderColor={Box.Value.paletteColor(Box.PaletteColor.error_main)}
    color={Box.Value.paletteColor(Box.PaletteColor.text_secondary)}
    bgcolor={Box.Value.paletteColor(Box.PaletteColor.background_paper)}
    fontSize={Box.Value.string("30px")}>
    {"Testbox"->React.string}
  </Box>
}