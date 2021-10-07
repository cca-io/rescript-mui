---
title: Module - Box
---

The `MaterialUi.Box` module contains a manual binding to the
[box component](https://material-ui.com/components/box/#box);

The bindings are not complete and therefore do not offer the full functionality
that the original does. Feel free to
[open an issue](https://github.com/cca-io/rescript-material-ui/issues) if you're
missing a vital use case with this component.

It makes heavy use of several mixed unions. Please refer to
[this section](union-values.md#rules-for-mixed-unions), to see how they are
used.

Example:

```reason
@react.component
let make = () => {
    open MaterialUi;

    <Box
      component={Box.Component.string("span")}
      style={ReactDOM.Style.make(~boxSizing="border-box", ())}
      p={Box.Value.breakpointObj(
        Box.BreakpointObj.make(~sm=Box.Value.int(2), ~md=Box.Value.int(5), ()),
      )}
      m={Box.Value.array({
        open Box.Value;
        [int(2), int(5)]
      })}
      borderTop={Box.Value.int(1)}
      borderColor={Box.Value.paletteColor(Box.PaletteColor.error_main)}
      color={Box.Value.paletteColor(Box.PaletteColor.text_secondary)}
      bgcolor={Box.Value.paletteColor(Box.PaletteColor.background_paper)}
      fontSize={Box.Value.string("30px")}
    >
      {"Testbox"->React.string}
  </Box>
};
```
