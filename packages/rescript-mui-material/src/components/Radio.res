type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `checked={true}`. */
  checked?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | @as("default") Default
  | String(string)

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

type edge =
  | @as("start") Start
  | @as("end") End
  | @as(false) False

type props<'value> = {
  ...ButtonBase.publicPropsWithOnClick,
  autoFocus?: bool,
  /**
   * If `true`, the component is checked.
   */
  checked?: bool,
  /**
   * The icon to display when the component is checked.
   * @default <RadioButtonIcon checked />
   */
  checkedIcon?: React.element,
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
   * The default checked state. Use when the component is not controlled.
   */
  defaultChecked?: bool,
  /**
   * If `true`, the component is disabled.
   */
  disabled?: bool,
  /**
   * If `true`, the  keyboard focus ripple is disabled.
   * @default false
   */
  disableFocusRipple?: bool,
  /**
   * If given, uses a negative margin to counteract the padding on one
   * side (this is often helpful for aligning the left or right
   * side of the icon with content above or below, without ruining the border
   * size and shape).
   * @default false
   */
  edge?: edge,
  /**
   * The icon to display when the component is unchecked.
   * @default <RadioButtonIcon />
   */
  icon?: React.element,
  /**
   * [Attributes](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input#Attributes) applied to the `input` element.
   */
  inputProps?: unknown,
  /**
   * Pass a ref to the `input` element.
   */
  inputRef?: React.ref<unknown>,
  /**
   * Name attribute of the `input` element.
   */
  name?: string,
  /**
   * Callback fired when the state is changed.
   *
   * @param {React.ChangeEvent<HTMLInputElement>} event The event source of the callback.
   * You can pull out the new value by accessing `event.target.value` (string).
   * You can pull out the new checked state by accessing `event.target.checked` (boolean).
   */
  onChange?: (ReactEvent.Form.t, bool) => unit,
  readOnly?: bool,
  /**
   * If `true`, the `input` element is required.
   * @default false
   */
  required?: bool,
  /**
   * The size of the component.
   * `small` is equivalent to the dense radio styling.
   * @default 'medium'
   */
  size?: size,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * The value of the component. The DOM API casts this to a string.
   */
  value?: 'value,
}

@module("@mui/material")
external make: React.component<props<'value>> = "Radio"
