The MaterialUi icons **do not** have separate bindings. There is a good reason
for this: Bindings result in thousands of files (or one extremely large one),
which take a good while to recompile (easily upwards of one minute, this is
unacceptable performance for a ReScript project).

It is therefore recommended to bind to the icons you need manually. See the
following example for how this could look like:

```rescript
module SupervisedUserCircleOutlined = {
  @react.component @module("@mui/icons-material/SupervisedUserCircle")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  <SupervisedUserCircleOutlined color={Mui.Colors.red.c400} fontSize="26px" />
}
```
