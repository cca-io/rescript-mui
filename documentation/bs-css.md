## Usage with bs-css or other CSS-in-ReScript libraries

It is important to change the style precedence order with the help of the
`StyledEngineProvider` component, otherwise the internal MUI classes will overwrite
your styles.

### Example

```rescript
module Styles = {
  open CssJs

  let categoryButton = style([textTransform(#none), justifyContent(#flexStart)])
}

@react.component
let make = () =>
  <Mui.StyledEngineProvider injectFirst=true>
    <Mui.Button color=Primary classes={root: Styles.categoryButton} onClick=ignore>
      {React.string("Hello, BS-CSS & MUI!")}
    </Mui.Button>
  </Mui.StyledEngineProvider>
```
