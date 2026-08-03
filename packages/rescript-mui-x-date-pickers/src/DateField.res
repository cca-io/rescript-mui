@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type formatDensity = [#dense | #spacious]
type margin = [#dense | #none | #normal]

@unboxed
type size =
  | @as("medium") Medium
  | @as("small") Small
  | String(string)

type variant = [#filled | #outlined | #standard]
type buttonPosition = [#start | #end]

type fieldChangeHandlerContext<'error> = {validationError: 'error}
type fieldRef<'value>

type commonProps<'value, 'error, 'inputRef> = {
  ...Mui.CommonProps.t_NoRef,
  ref?: ReactDOM.domRef,
  autoFocus?: bool,
  color?: color,
  defaultValue?: 'value,
  disabled?: bool,
  error?: bool,
  focused?: bool,
  format?: string,
  formatDensity?: formatDensity,
  fullWidth?: bool,
  helperText?: React.element,
  hiddenLabel?: bool,
  inputRef?: React.ref<'inputRef>,
  label?: React.element,
  margin?: margin,
  name?: string,
  onBlur?: ReactEvent.Focus.t => unit,
  onChange?: ('value, fieldChangeHandlerContext<'error>) => unit,
  onError?: ('error, 'value) => unit,
  onSelectedSectionsChange?: Common.fieldSelectedSections => unit,
  readOnly?: bool,
  referenceDate?: 'value,
  required?: bool,
  selectedSections?: Common.fieldSelectedSections,
  shouldRespectLeadingZeros?: bool,
  size?: size,
  slotProps?: {.},
  slots?: {.},
  sx?: Mui.Sx.props,
  timezone?: Common.pickersTimezone,
  fieldRef?: React.ref<fieldRef<'value>>,
  value?: 'value,
  variant?: variant,
  clearable?: bool,
  onClear?: ReactEvent.Mouse.t => unit,
  clearButtonPosition?: buttonPosition,
  openPickerButtonPosition?: buttonPosition,
}

type props<'value, 'error, 'inputRef> = {
  ...commonProps<'value, 'error, 'inputRef>,
  disableFuture?: bool,
  disablePast?: bool,
  maxDate?: 'value,
  minDate?: 'value,
  shouldDisableDate?: 'value => bool,
  shouldDisableMonth?: 'value => bool,
  shouldDisableYear?: 'value => bool,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'value, 'error, 'inputRef>> = "DateField"
