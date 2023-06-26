type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** State class applied to the root element if `selected={true}`. */
  selected?: string,
  /** State class applied to the root element if `color="standard"`. */
  standard?: string,
  /** State class applied to the root element if `color="primary"`. */
  primary?: string,
  /** State class applied to the root element if `color="secondary"`. */
  secondary?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** Styles applied to the root element if `size="large"`. */
  sizeLarge?: string,
}

@unboxed
type color =
  | @as("standard") Standard
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

type props<'value> = {
  ...ButtonBase.publicProps,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The color of the button when it is in an active state.
    * It supports both default and custom theme colors, which can be added as shown in the
    * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
    * @default 'standard'
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
    * If `true`, the button will take up the full width of its container.
    * @default false
    */
  fullWidth?: bool,
  /**
    * Callback fired when the state changes.
    *
    * @param {React.MouseEvent<HTMLElement>} event The event source of the callback.
    * @param {any} value of the selected button.
    */
  onChange?: (ReactEvent.Mouse.t, 'value) => unit,
  /**
    * Callback fired when the button is clicked.
    *
    * @param {React.MouseEvent<HTMLElement>} event The event source of the callback.
    * @param {any} value of the selected button.
    */
  onClick?: (ReactEvent.Mouse.t, 'value) => unit,
  /**
    * If `true`, the button is rendered in an active state.
    */
  selected?: bool,
  /**
    * The size of the component.
    * The prop defaults to the value inherited from the parent ToggleButtonGroup component.
    * @default 'medium'
    */
  size?: size,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The value to associate with the button when selected in a
    * ToggleButtonGroup.
    */
  value: 'value,
}

@module("@mui/material/ToggleButton")
external make: React.component<props<'value>> = "default"
