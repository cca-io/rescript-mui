type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="determinate"`. */
  determinate?: string,
  /** Styles applied to the root element if `variant="indeterminate"`. */
  indeterminate?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the svg element. */
  svg?: string,
  /** Styles applied to the `circle` svg path. */
  circle?: string,
  /** Styles applied to the `circle` svg path if `variant="determinate"`. */
  circleDeterminate?: string,
  /** Styles applied to the `circle` svg path if `variant="indeterminate"`. */
  circleIndeterminate?: string,
  /** Styles applied to the `circle` svg path if `disableShrink={true}`. */
  circleDisableShrink?: string,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | @as("inherit") Inherit
  | String(string)

@unboxed
type size =
  | Number(int)
  | String(string)

@unboxed
type variant =
  | @as("determinate") Determinate
  | @as("indeterminate") Indeterminate

type props = {
  ...CommonProps.t,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The color of the component.
   * It supports both default and custom theme colors, which can be added as shown in the
   * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
   * @default 'primary'
   */
  color?: color,
  /**
   * If `true`, the shrink animation is disabled.
   * This only works if variant is `indeterminate`.
   * @default false
   */
  disableShrink?: bool,
  /**
   * The size of the component.
   * If using a number, the pixel unit is assumed.
   * If using a string, you need to provide the CSS unit, e.g '3rem'.
   * @default 40
   */
  size?: size,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * The thickness of the circle.
   * @default 3.6
   */
  thickness?: float,
  /**
   * The value of the progress indicator for the determinate variant.
   * Value between 0 and 100.
   * @default 0
   */
  value?: int,
  /**
   * The variant to use.
   * Use indeterminate when there is no progress value.
   * @default 'indeterminate'
   */
  variant?: variant,
}

@module("@mui/material/CircularProgress")
external make: React.component<props> = "default"
