type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `color="primary"`. */
  primary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  secondary?: string,
  /** Styles applied to the root element if `variant="extended"`. */
  extended?: string,
  /** Styles applied to the root element if `variant="circular"`. */
  circular?: string,
  /** State class applied to the ButtonBase root element if the button is keyboard focused. */
  focusVisible?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `color="inherit"`. */
  colorInherit?: string,
  /** Styles applied to the root element if `size="small"``. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"``. */
  sizeMedium?: string,
}

@unboxed
type color =
  | @as("default") Default
  | @as("error") Error
  | @as("info") Info
  | @as("inherit") Inherit
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

@unboxed
type size =
  | @a("small") Small
  | @a("medium") Medium
  | @a("large") Large
  | String(string)

@unboxed
type variant =
  | @a("circular") Circular
  | @a("extended") Extended
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
  /**
     * The color of the component.
     * It supports both default and custom theme colors, which can be added as shown in the
     * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
     * @default 'default'
     */
  color?: color,
  /**
     * If `true`, the component is disabled.
     * @default false
     */
  disabled?: bool,
  /**
     * If `true`, the  keyboard focus ripple is disabled.
     * @default false
     */
  disableFocusRipple?: bool,
  /**
     * If `true`, the ripple effect is disabled.
     */
  disableRipple?: bool,
  /**
     * The URL to link to when the button is clicked.
     * If defined, an `a` element will be used as the root node.
     */
  href?: string,
  /**
     * The size of the component.
     * `small` is equivalent to the dense button styling.
     * @default 'large'
     */
  size?: size,
  /**
     * The variant to use.
     * @default 'circular'
     */
  variant?: variant,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  component?: OverridableComponent.t<unknown>,
}

@module("@mui/material/Fab")
external make: React.component<props> = "default"
