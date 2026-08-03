type props<'date> = {
  ...Mui.CommonProps.t,
  /** Override or extend the styles applied to the component. */
  classes?: {.},
  /** The date to show. */
  day: 'date,
  /** If `true`, renders as selected. @default false */
  selected?: bool,
  /** If `true`, renders as disabled. @default false */
  disabled?: bool,
  /** If `true`, day is the current day. */
  today?: bool,
  /** If `true`, day is outside of month and will be hidden. */
  outsideCurrentMonth: bool,
  /** If `true`, day is the first visible cell of the month. */
  isFirstVisibleCell: bool,
  /** If `true`, day is the last visible cell of the month. */
  isLastVisibleCell: bool,
  /** Callback fired when the day is selected. */
  onDaySelect: 'date => unit,
  /** If `true`, today's date is rendered without a highlighting circle. @default false */
  disableHighlightToday?: bool,
  /** If `true`, days are rendered without margin. @default false */
  disableMargin?: bool,
  /** If `true`, days outside the current month are rendered. @default false */
  showDaysOutsideCurrentMonth?: bool,
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "PickersDay"
