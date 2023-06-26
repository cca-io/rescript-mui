## Usage with plain CSS

It is important to change the style precedence order with the help of the
`StyledEngineProvider` component, otherwise the internal MUI classes will overwrite
your styles.

### Example

```rescript
@react.component
let make = () =>
  <Mui.StyledEngineProvider injectFirst=true>
    <Mui.Button
      color=#primary
      className="my-global-class-name"
      onClick=ignore>
      {React.string("Hello, plain CSS & MUI!")}
    </Mui.Button>
  </Mui.StyledEngineProvider>
```
