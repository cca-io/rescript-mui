## Usage with TailwindCSS

It is important to change the style precedence order with the help of the
`StyledEngineProvider` component, otherwise the internal MUI classes will overwrite
your styles.

### Example

```rescript
@react.component
let make = () =>
  <Mui.StyledEngineProvider injectFirst=true>
    <Mui.Button color=Primary classes={root: "normal-case justify-start"} onClick=ignore>
      {React.string("Hello, Tailwind & MUI!")}
    </Mui.Button>
  </Mui.StyledEngineProvider>
```
