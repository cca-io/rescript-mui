@unboxed
type themeOrThemeFunc =
  | Theme(Theme.t)
  | Func(ThemeOptions.t => Theme.t)

type props = {
  children: React.element,
  theme: themeOrThemeFunc,
}

@module("@mui/material/styles")
external make: props => React.element = "ThemeProvider"
