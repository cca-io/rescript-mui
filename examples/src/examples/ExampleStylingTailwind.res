@react.component
let make = () =>
  <Mui.StyledEngineProvider injectFirst=true>
    <Mui.Button color=Primary classes={root: "normal-case justify-start"} onClick=ignore>
      {React.string("Hello, Tailwind & MUI!")}
    </Mui.Button>
  </Mui.StyledEngineProvider>
