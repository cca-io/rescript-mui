type classes = {
  root?: string,
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
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  component?: OverridableComponent.t<unknown>,
  elevation?: float,
  square?: bool,
  variant?: variant,
}

@module("@mui/material")
external make: props => React.element = "Paper"
