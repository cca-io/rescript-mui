type props = {
  children: React.element,
  theme: Theme.t,
}

@module("@mui/material/styles")
external make: props => React.element = "ThemeProvider"
