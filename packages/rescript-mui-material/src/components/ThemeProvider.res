type props = {
  children: React.element,
  theme: ThemeOptions.t => Theme.t,
}

@module("@mui/material/styles")
external make: props => React.element = "ThemeProvider"
