---
title: bs-css
---

## Usage with bs-css or other CSS-in-ReScript libraries

It is important to change the style precedence order with the help of the
`StylesProvider` component, otherwise the internal MUI classes will overwrite
your styles.

### Example

```rescript
module Styles = {
  open CssJs

  let categoryButton = style(. [textTransform(#none), justifyContent(#flexStart)])
  let icon = style(. [fontSize(px(24)), width(px(50))])
}

@react.component
let make = () =>
  <Mui.StylesProvider injectFirst=true>
    <Mui.Button
      color=#primary
      classes={Mui.Button.Classes.make(~root=Styles.categoryButton, ())}
      onClick=ignore>
      {React.string("Hello, BS-CSS & MUI!")}
    </Mui.Button>
  </Mui.StylesProvider>
```
