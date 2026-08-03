## Icons

The Material UI icons do not have separate bindings. Generating bindings for
the complete icon package would add thousands of modules, while binding the
icons used by an application is straightforward.

It is therefore recommended to bind to the icons you need manually. See the
following example for how this could look like:

```rescript
module SupervisedUserCircle = {
  @react.component @module("@mui/icons-material/SupervisedUserCircle")
  external make: (~color: string=?, ~fontSize: string=?) => React.element = "default"
}

@react.component
let make = () => {
  <SupervisedUserCircle color="primary" fontSize="large" />
}
```
