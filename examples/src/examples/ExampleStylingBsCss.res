module Styles = {
  open CssJs

  let categoryButton = style([textTransform(#none), justifyContent(#flexStart)])
}

@react.component
let make = () =>
  <Mui.StylesProvider injectFirst=true>
    <Mui.Button color=Primary classes={root: Styles.categoryButton} onClick=ignore>
      {React.string("Hello, BS-CSS & MUI!")}
    </Mui.Button>
  </Mui.StylesProvider>
