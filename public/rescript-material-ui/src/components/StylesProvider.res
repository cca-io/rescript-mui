@react.component @module("@mui/styles")
external make: (
  ~disableGeneration: bool=?,
  ~generateClassName: unit => string=?,
  ~injectFirst: bool=?,
  ~jss: {..}=?,
  ~children: React.element,
) => React.element = "StylesProvider"
