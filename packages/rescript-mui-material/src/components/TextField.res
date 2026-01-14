type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type slots = {
  /**
    * The component that renders the root.
    * @default FormControl
    */
  root?: OverridableComponent.t<FormControl.props>,
  /**
    * The component that renders the input.
    * @default OutlinedInput
    */
  input?: OverridableComponent.t<Input.props<unknown, unknown>>,
  /**
    * The component that renders the input's label.
    * @default InputLabel
    */
  inputLabel?: OverridableComponent.t<InputLabel.props>,
  /**
    * The html input element.
    * @default 'input'
    */
  htmlInput?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the helper text.
    * @default FormHelperText
    */
  formHelperText?: OverridableComponent.t<FormHelperText.props>,
  /**
    * The component that renders the select.
    * @default Select
    */
  select?: OverridableComponent.t<Select.props<unknown, unknown>>,
}

type slotProps<'value, 'inputRef> = {
  /**
    * Props forwarded to the root slot.
    * By default, the avaible props are based on the [FormControl](https://mui.com/material-ui/api/form-control/#props) component.
    */
  root?: FormControl.props,
  /**
    * Props forwarded to the input slot.
    * By default, the avaible props are based on the [Input](https://mui.com/material-ui/api/input/#props) component.
    */
  input?: Input.props<'value, 'inputRef>,
  /**
    * Props forwarded to the input label slot.
    * By default, the avaible props are based on the [InputLabel](https://mui.com/material-ui/api/input-label/#props) component.
    */
  inputLabel?: InputLabel.props,
  /**
    * Props forwarded to the html input slot.
    * By default, the avaible props are based on the html input element.
    */
  htmlInput?: InputBase.inputBaseComponentProps,
  /**
    * Props forwarded to the form helper text slot.
    * By default, the avaible props are based on the [FormHelperText](https://mui.com/material-ui/api/form-helper-text/#props) component.
    */
  formHelperText?: FormHelperText.props,
  /**
    * Props forwarded to the select slot.
    * By default, the avaible props are based on the [Select](https://mui.com/material-ui/api/select/#props) component.
    */
  select?: Select.props<'value, 'inputRef>,
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
    * If `true`, the underline is disabled for Filled.
    */
  disableUnderline?: bool,
  /**
    * Props applied to the [`FormHelperText`](/material-ui/api/form-helper-text/) element.
    * @deprecated Use `slotProps.formHelperText` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](https://mui.com/material-ui/migration/migrating-from-deprecated-apis/) for more details.
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
    * @deprecated Use `slotProps.inputLabel` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](https://mui.com/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    */
  @as("InputLabelProps")
  inputLabelProps?: InputLabel.props,
  /**
    * [Attributes](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input#Attributes) applied to the `input` element.
    * @deprecated Use `slotProps.htmlInput` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](https://mui.com/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    */
  inputProps?: InputBase.inputBaseComponentProps,
  /**
    * Props applied to the Input element.
    * It will be a [`FilledInput`](/material-ui/api/filled-input/),
    * [`OutlinedInput`](/material-ui/api/outlined-input/) or [`Input`](/material-ui/api/input/)
    * component depending on the `variant` prop value.
    * @deprecated Use `slotProps.input` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](https://mui.com/material-ui/migration/migrating-from-deprecated-apis/) for more details.
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
    * @deprecated Use `slotProps.select` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](https://mui.com/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    */
  @as("SelectProps")
  selectProps?: Select.props<'value, 'inputRef>,
  /**
    * The size of the component.
    */
  size?: size,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The props used for each slot inside.
    * @default {}
    */
  slotProps?: slotProps<'value, 'inputRef>,
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
