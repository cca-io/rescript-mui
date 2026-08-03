type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="contained"`. */
  contained?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="text"`. */
  text?: string,
  /** Styles applied to the root element if `disableElevation={true}`. */
  disableElevation?: string,
  /** State class applied to the child elements if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the first button in the button group. */
  firstButton?: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth?: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the children. */
  grouped?: string,
  /** Styles applied to the children if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the children if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the last button in the button group. */
  lastButton?: string,
  /** Styles applied to the buttons in the middle of the button group. */
  middleButton?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type orientation =
  | @as("vertical") Vertical
  | @as("horizontal") Horizontal

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

@unboxed
type variant =
  | @as("text") Text
  | @as("outlined") Outlined
  | @as("contained") Contained
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
    * @default 'primary'
    */
  color?: color,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, no elevation is used.
    * @default false
    */
  disableElevation?: bool,
  /**
    * If `true`, the button keyboard focus ripple is disabled.
    * @default false
    */
  disableFocusRipple?: bool,
  /**
    * If `true`, the button ripple effect is disabled.
    * @default false
    */
  disableRipple?: bool,
  /**
    * If `true`, the buttons will take up the full width of its container.
    * @default false
    */
  fullWidth?: bool,
  /**
    * The component orientation (layout flow direction).
    * @default 'horizontal'
    */
  orientation?: orientation,
  /**
    * The size of the component.
    * `small` is equivalent to the dense button styling.
    * @default 'medium'
    */
  size?: size,
  /**
    * The variant to use.
    * @default 'outlined'
    */
  variant?: variant,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/ButtonGroup")
external make: React.component<props> = "default"
