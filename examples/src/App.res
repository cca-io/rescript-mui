open Mui

@react.component
let make = () =>
  <ThemeProvider theme={Theme.create(ThemeOptions.make())}>
    <Box
      width={Box.Value.string("100%")}
      height={Box.Value.string("100%")}
      maxWidth={Box.Value.string("970px")}
      margin={Box.Value.string("30px auto")}>
      <CssBaseline /> <Examples /> <ExamplesLab />
    </Box>
  </ThemeProvider>
