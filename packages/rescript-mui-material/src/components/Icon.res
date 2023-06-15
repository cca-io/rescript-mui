type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `color="action"`. */
  colorAction?: string,
  /** Styles applied to the root element if `color="error"`. */
  colorError?: string,
  /** Styles applied to the root element if `color="disabled"`. */
  colorDisabled?: string,
  /** Styles applied to the root element if `fontSize="inherit"`. */
  fontSizeInherit?: string,
  /** Styles applied to the root element if `fontSize="small"`. */
  fontSizeSmall?: string,
  /** Styles applied to the root element if `fontSize="large"`. */
  fontSizeLarge?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("action") Action
  | @as("disabled") Disabled
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning

@unboxed
type fontSize =
  | @as("inherit") Inherit
  | @as("large") Large
  | @as("medium") Medium
  | @as("small") Small
  | String(string)

type props = {
  ...CommonProps.t,
  /**
     * The base class applied to the icon. Defaults to 'material-icons', but can be changed to any
     * other base class that suits the icon font you're using (e.g. material-icons-rounded, fas, etc).
     * @default 'material-icons'
     */
  baseClassName?: string,
  /**
     * The name of the icon font ligature.
     */
  children?: React.element,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
     * The color of the component.
     * It supports both default and custom theme colors, which can be added as shown in the
     * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
     * @default 'inherit'
     */
  color?: color,
  /**
     * The fontSize applied to the icon. Defaults to 24px, but can be configure to inherit font size.
     * @default 'medium'
     */
  fontSize?: fontSize,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  component?: OverridableComponent.t<unknown>,
}

@module("@mui/material")
external make: React.component<props> = "Icon"
