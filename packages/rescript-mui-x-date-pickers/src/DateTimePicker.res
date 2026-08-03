type formatDensity = [#dense | #spacious]
type orientation = [#landscape | #portrait]
type perRow = [#3 | #4]

type timeSteps = {
  hours?: int,
  minutes?: int,
  seconds?: int,
}

type props<'date> = {
  ...Mui.CommonProps.t,
  /** The selected value. Used when the component is controlled. */
  value?: Common.dateValue<'date>,
  /** The default value. Used when the component is not controlled. */
  defaultValue?: Common.dateValue<'date>,
  /** The date used to generate the new value when both `value` and `defaultValue` are empty. */
  referenceDate?: 'date,
  /** Callback fired when the value changes. */
  onChange?: (Common.dateValue<'date>, option<Common.pickerSelectionState>) => unit,
  /** Callback fired when the value is accepted. */
  onAccept?: Common.dateValue<'date> => unit,
  /** Callback fired when the error associated with the current value changes. */
  onError?: (Nullable.t<string>, Common.dateValue<'date>) => unit,
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
  /** Minimal selectable moment of time (date part is ignored unless `disableIgnoringDatePartForTimeValidation`). */
  minTime?: 'date,
  /** Maximal selectable moment of time (date part is ignored unless `disableIgnoringDatePartForTimeValidation`). */
  maxTime?: 'date,
  /** Minimal selectable date-time. */
  minDateTime?: 'date,
  /** Maximal selectable date-time. */
  maxDateTime?: 'date,
  /** If `true`, disable values after the current date/time. @default false */
  disableFuture?: bool,
  /** If `true`, disable values before the current date/time. @default false */
  disablePast?: bool,
  /** Disable specific date. */
  shouldDisableDate?: 'date => bool,
  /** Disable specific month. */
  shouldDisableMonth?: 'date => bool,
  /** Disable specific year. */
  shouldDisableYear?: 'date => bool,
  /** Disable specific time. */
  shouldDisableTime?: ('date, Common.timeView) => bool,
  /** Do not ignore the date part when validating min/max time. @default false */
  disableIgnoringDatePartForTimeValidation?: bool,
  /** 12h/24h view for the clock. @default adapter-based */
  ampm?: bool,
  /** Display ampm controls under the clock (instead of in the toolbar). @default false */
  ampmInClock?: bool,
  /** Step over minutes. @default 1 */
  minutesStep?: int,
  /** Amount of time options at or below which the single column time renderer is used. @default 24 */
  thresholdToRenderTimeInASingleColumn?: int,
  /** The time steps between two time unit options. */
  timeSteps?: timeSteps,
  /** If `true`, disabled digital clock items will not be rendered. @default false */
  skipDisabled?: bool,
  /** If `true`, calls `renderLoading` instead of rendering the day calendar. @default false */
  loading?: bool,
  /** Component displayed on loading. */
  renderLoading?: unit => React.element,
  /** Formats the day of week displayed in the calendar header. */
  dayOfWeekFormatter?: string => string,
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
  /** Years rendered per row. @default 4 */
  yearsPerRow?: perRow,
  /** Callback fired on month change. */
  onMonthChange?: 'date => unit,
  /** Callback fired on year change. */
  onYearChange?: 'date => unit,
  /** Available views. */
  views?: array<Common.dateOrTimeView>,
  /** The visible view. Used when the component view is controlled. */
  view?: Common.dateOrTimeView,
  /** The default visible view. */
  openTo?: Common.dateOrTimeView,
  /** Callback fired on view change. */
  onViewChange?: Common.dateOrTimeView => unit,
  /** Control the popup or dialog open state. */
  @as("open") open_?: bool,
  /** Callback fired when the popup requests to be opened. */
  onOpen?: unit => unit,
  /** Callback fired when the popup requests to be closed. */
  onClose?: unit => unit,
  /** If `true`, the popup will close after submitting the full date. */
  closeOnSelect?: bool,
  /** If `true`, the open picker button will not be rendered. @default false */
  disableOpenPicker?: bool,
  /** The orientation of the picker. */
  orientation?: orientation,
  /** Overridable component slots. @default {} */
  slots?: {.},
  /** The props used for each component slot. @default {} */
  slotProps?: {.},
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "DateTimePicker"
