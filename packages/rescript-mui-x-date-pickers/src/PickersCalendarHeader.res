type classes = {
  root?: string,
  labelContainer?: string,
  label?: string,
  switchViewButton?: string,
  switchViewIcon?: string,
}

type props<'date> = {
  ...Mui.CommonProps.t,
  /** Format used for the calendar header label. */
  format?: string,
  slots?: {.},
  slotProps?: {.},
  currentMonth: 'date,
  disabled?: bool,
  views: array<Common.dateView>,
  onMonthChange: 'date => unit,
  view: Common.dateView,
  reduceAnimations: bool,
  onViewChange?: Common.dateView => unit,
  labelId?: string,
  classes?: classes,
  disablePast?: bool,
  disableFuture?: bool,
  minDate: 'date,
  maxDate: 'date,
  timezone: Common.pickersTimezone,
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "PickersCalendarHeader"
