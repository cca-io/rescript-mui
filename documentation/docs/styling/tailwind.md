---
title: Tailwind
---

It is important to change the style precedence order with the help of the
`StylesProvider` component, otherwise the internal MUI classes will overwrite
your styles.

### Example

```rescript
@react.component
let make = () =>
  <Mui.StylesProvider injectFirst=true>
    <Mui.Button
      color=#primary
      classes={Mui.Button.Classes.make(~root="normal-case justify-start", ())}
      onClick=ignore>
      {React.string("Hello, Tailwind & MUI!")}
    </Mui.Button>
  </Mui.StylesProvider>
```
