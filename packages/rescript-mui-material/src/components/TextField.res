type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type variant =
  | @as("standard") Standard
  | @as("outlined") Outlined
  | @as("filled") Filled

type props<'value, 'inputRef> = {
  ...CommonProps.t,
  ...CommonProps.inputTextareaProps,
  ...CommonProps.eventHandlerProps,
  ...FormControl.publicProps,
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
    * The default value. Use when the component is not controlled.
    */
  defaultValue?: 'value,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, the label is displayed in an error state.
    * @default false
    */
  error?: bool,
  /**
    * Props applied to the [`FormHelperText`](/material-ui/api/form-helper-text/) element.
    */
  @as("FormHelperTextProps")
  formHelperTextProps?: FormHelperText.props,
  /**
    * If `true`, the input will take up the full width of its container.
    * @default false
    */
  fullWidth?: bool,
  /**
    * The helper text content.
    */
  helperText?: React.element,
  /**
    * Props applied to the [`InputLabel`](/material-ui/api/input-label/) element.
    * Pointer events like `onClick` are enabled if and only if `shrink` is `true`.
    */
  @as("InputLabelProps")
  inputLabelProps?: InputLabel.props,
  /**
    * [Attributes](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input#Attributes) applied to the `input` element.
    */
  inputProps?: InputBase.inputBaseComponentProps,
  /**
    * Props applied to the Input element.
    * It will be a [`FilledInput`](/material-ui/api/filled-input/),
    * [`OutlinedInput`](/material-ui/api/outlined-input/) or [`Input`](/material-ui/api/input/)
    * component depending on the `variant` prop value.
    */
  @as("InputProps")
  inputProps_?: Input.props<'value, 'inputRef>,
  /**
    * Pass a ref to the `input` element.
    */
  inputRef?: React.ref<'inputRef>,
  /**
    * The label content.
    */
  label?: React.element,
  /**
    * If `true`, a `textarea` element is rendered instead of an input.
    * @default false
    */
  multiline?: bool,
  onChange?: ReactEvent.Form.t => unit,
  /**
    * Number of rows to display when multiline option is set to true.
    */
  rows?: int,
  /**
    * Maximum number of rows to display when multiline option is set to true.
    */
  maxRows?: int,
  /**
    * Minimum number of rows to display when multiline option is set to true.
    */
  minRows?: int,
  /**
    * Render a [`Select`](/material-ui/api/select/) element while passing the Input element to `Select` as `input` parameter.
    * If this option is set you must pass the options of the select as children.
    * @default false
    */
  select?: bool,
  /**
    * Props applied to the [`Select`](/material-ui/api/select/) element.
    */
  @as("SelectProps")
  selectProps?: Select.props<'value, 'inputRef>,
  /**
    * The size of the component.
    */
  size?: size,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The value of the `input` element, required for a controlled component.
    */
  value?: 'value,
  /**
    * The variant to use.
    */
  variant?: variant,
}

@module("@mui/material/TextField")
external make: React.component<props<'value, 'inputRef>> = "default"
