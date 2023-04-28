type classes = {
  root?: string,
  //etc
  elevation1?: string,
  elevation2?: string,
  elevation3?: string,
}

@unboxed
type variant =
  | @as("elevation") Elevation
  | @as("outlined") Outlined
  | String(string)

type props = {
  ...CommonProps.t,
  children?: React.element,
  classes?: classes,
  component?: OverridableComponent.t<unknown>,
  elevation?: float,
  square?: bool,
  variant?: variant,
}

@module("@mui/material")
external make: props => React.element = "Paper"
