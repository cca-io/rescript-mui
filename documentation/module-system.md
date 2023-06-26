## System

The `Mui.System` module contains types for `@mui/system` values and props that are used in components like [`Box`](<(https://mui.com/material-ui/react-box/)>) or [`Grid`](https://mui.com/material-ui/react-grid/).

The bindings are not complete and therefore do not offer the full functionality
that the original does. Feel free to
[open an issue](https://github.com/cca-io/rescript-mui/issues) if you're
missing a vital use case with this component.

It makes heavy use of unboxed & untagged unions. Please refer to
[this section](union-values.md#rules-for-mixed-unions), to see how they are
used.

Example:

```rescript
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
```
