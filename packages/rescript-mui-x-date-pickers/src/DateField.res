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

type commonProps<'date, 'error, 'inputRef> = {
  ...Mui.CommonProps.t_NoRef,
  ref?: ReactDOM.domRef,
  autoFocus?: bool,
  color?: color,
  defaultValue?: Common.dateValue<'date>,
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
  onChange?: (Common.dateValue<'date>, fieldChangeHandlerContext<'error>) => unit,
  onError?: ('error, Common.dateValue<'date>) => unit,
  onSelectedSectionsChange?: Common.fieldSelectedSections => unit,
  readOnly?: bool,
  referenceDate?: 'date,
  required?: bool,
  selectedSections?: Common.fieldSelectedSections,
  shouldRespectLeadingZeros?: bool,
  size?: size,
  slotProps?: PickerSlots.fieldComponentSlotProps,
  slots?: PickerSlots.fieldSlots,
  sx?: Mui.Sx.props,
  timezone?: Common.pickersTimezone,
  fieldRef?: React.ref<fieldRef<Common.dateValue<'date>>>,
  value?: Common.dateValue<'date>,
  variant?: variant,
  clearable?: bool,
  onClear?: ReactEvent.Mouse.t => unit,
  clearButtonPosition?: buttonPosition,
  openPickerButtonPosition?: buttonPosition,
}

type props<'date, 'inputRef> = {
  ...commonProps<'date, DateValidationError.t, 'inputRef>,
  disableFuture?: bool,
  disablePast?: bool,
  maxDate?: 'date,
  minDate?: 'date,
  shouldDisableDate?: 'date => bool,
  shouldDisableMonth?: 'date => bool,
  shouldDisableYear?: 'date => bool,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date, 'inputRef>> = "DateField"
