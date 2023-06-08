@react.component
let make = () =>
  <Mui.StylesProvider injectFirst=true>
    <Mui.Button color=Primary className="my-global-class-name" onClick=ignore>
      {React.string("Hello, plain CSS & MUI!")}
    </Mui.Button>
  </Mui.StylesProvider>
