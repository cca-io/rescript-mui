type formatDensity = [#dense | #spacious]
type orientation = [#landscape | #portrait]
type perRow = [#3 | #4]

type props<'date> = {
  ...Mui.CommonProps.t,
  /** The selected value. Used when the component is controlled. */
  value?: Common.dateValue<'date>,
  /** The default value. Used when the component is not controlled. */
  defaultValue?: Common.dateValue<'date>,
  /** The date used to generate the new value when both `value` and `defaultValue` are empty. */
  referenceDate?: 'date,
  /** Callback fired when the value changes. */
  onChange?: (
    Common.dateValue<'date>,
    Common.pickerChangeHandlerContext<DateValidationError.t>,
  ) => unit,
  /** Callback fired when the value is accepted. */
  onAccept?: (
    Common.dateValue<'date>,
    Common.pickerChangeHandlerContext<DateValidationError.t>,
  ) => unit,
  /** Callback fired when the error associated with the current value changes. */
  onError?: (DateValidationError.t, Common.dateValue<'date>) => unit,
  /** Choose which timezone to use for the value. */
  timezone?: Common.pickersTimezone,
  /** The label content. */
  label?: React.element,
  /** Format of the date when rendered in the input(s). */
  format?: string,
  /** Density of the format when rendered in the input. @default "dense" */
  formatDensity?: formatDensity,
  /** Name attribute of the `input` element. */
  name?: string,
  /** If `true`, the component is disabled. @default false */
  disabled?: bool,
  /** If `true`, the component is read-only. @default false */
  readOnly?: bool,
  /** Minimal selectable date. */
  minDate?: 'date,
  /** Maximal selectable date. */
  maxDate?: 'date,
  /** If `true`, disable values after the current date. @default false */
  disableFuture?: bool,
  /** If `true`, disable values before the current date. @default false */
  disablePast?: bool,
  /** Disable specific date. */
  shouldDisableDate?: 'date => bool,
  /** Disable specific month. */
  shouldDisableMonth?: 'date => bool,
  /** Disable specific year. */
  shouldDisableYear?: 'date => bool,
  /** If `true`, calls `renderLoading` instead of rendering the day calendar. @default false */
  loading?: bool,
  /** Component displayed on loading. */
  renderLoading?: unit => React.element,
  /** Formats the day of week displayed in the calendar header. */
  dayOfWeekFormatter?: 'date => string,
  /** If `true`, the week number will be displayed in the calendar. */
  displayWeekNumber?: bool,
  /** Calendar will show more weeks in order to match this value. */
  fixedWeekNumber?: int,
  /** If `true`, days outside the current month are rendered. @default false */
  showDaysOutsideCurrentMonth?: bool,
  /** If `true`, today's date is rendered without a highlighting circle. @default false */
  disableHighlightToday?: bool,
  /** Disable heavy animations. */
  reduceAnimations?: bool,
  /** Months rendered per row. @default 3 */
  monthsPerRow?: perRow,
  /** Years rendered per row. @default 3 */
  yearsPerRow?: perRow,
  /** Years are displayed in ascending or descending order. @default 'asc' */
  yearsOrder?: [#asc | #desc],
  /** Callback fired on month change. */
  onMonthChange?: 'date => unit,
  /** Callback fired on year change. */
  onYearChange?: 'date => unit,
  /** Available views. */
  views?: array<Common.dateView>,
  /** The visible view. Used when the component view is controlled. */
  view?: Common.dateView,
  /** The default visible view. */
  openTo?: Common.dateView,
  /** Callback fired on view change. */
  onViewChange?: Common.dateView => unit,
  /** Control the popup or dialog open state. */
  @as("open") open_?: bool,
  /** Callback fired when the popup requests to be opened. */
  onOpen?: unit => unit,
  /** Callback fired when the popup requests to be closed. */
  onClose?: unit => unit,
  /** If `true`, the popup will close after submitting the full date. */
  closeOnSelect?: bool,
  /** Keep the picker open while the field has focus. @default false */
  keepOpenDuringFieldFocus?: bool,
  /** Media query used to choose the desktop picker variant. */
  desktopModeMediaQuery?: string,
  /** If `true`, the open picker button will not be rendered. @default false */
  disableOpenPicker?: bool,
  /** The orientation of the picker. */
  orientation?: orientation,
  /** Overridable component slots. @default {} */
  slots?: PickerSlots.datePickerSlots,
  /** The props used for each component slot. @default {} */
  slotProps?: PickerSlots.datePickerSlotProps<'date>,
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "DatePicker"
