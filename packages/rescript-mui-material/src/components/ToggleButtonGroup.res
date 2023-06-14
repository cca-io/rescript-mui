type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled: string,
  /** Styles applied to the children. */
  grouped: string,
  /** Styles applied to the children if `orientation="horizontal"`. */
  groupedHorizontal: string,
  /** Styles applied to the children if `orientation="vertical"`. */
  groupedVertical: string,
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

type orientation =
  | @as("horizontal") Horizontal
  | @as("vertical") Vertical

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

type props<'value> = {
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
   * The color of the button when it is selected.
   * It supports both default and custom theme colors, which can be added as shown in the
   * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
   * @default 'standard'
   */
  color?: color,
  /**
   * If `true`, the component is disabled. This implies that all ToggleButton children will be disabled.
   * @default false
   */
  disabled?: bool,
  /**
   * If `true`, only allow one of the child ToggleButton values to be selected.
   * @default false
   */
  exclusive?: bool,
  /**
   * If `true`, the button group will take up the full width of its container.
   * @default false
   */
  fullWidth?: bool,
  /**
   * Callback fired when the value changes.
   *
   * @param {React.MouseEvent<HTMLElement>} event The event source of the callback.
   * @param {any} value of the selected buttons. When `exclusive` is true
   * this is a single value, when false an array of selected values. If no value
   * is selected and `exclusive` is true the value is null, when false an empty array.
   */
  onChange?: (ReactEvent.Mouse.t, 'value) => unit,
  /**
   * The component orientation (layout flow direction).
   * @default 'horizontal'
   */
  orientation?: orientation,
  /**
   * The size of the component.
   * @default 'medium'
   */
  size?: size,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * The currently selected value within the group or an array of selected
   * values when `exclusive` is false.
   *
   * The value must have reference equality with the option in order to be selected.
   */
  value?: 'value,
}

@module("@mui/material")
external make: props<'value> => React.element = "ToggleButtonGroup"
