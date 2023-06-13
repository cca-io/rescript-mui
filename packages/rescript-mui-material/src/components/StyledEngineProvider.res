type props = {
  injectFirst?: bool,
  children: React.element,
}

@module("@mui/material/styles")
external make: props => React.element = "StylesProvider"
