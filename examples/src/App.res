open Mui

@react.component
let make = () =>
  <ThemeProvider theme={_ => Theme.create({})}>
    <Box
      width={String("100%")}
      height={String("100%")}
      maxWidth={String("970px")}
      margin={String("30px auto")}>
      <CssBaseline />
      <Examples />
      <ExamplesLab />
    </Box>
  </ThemeProvider>
