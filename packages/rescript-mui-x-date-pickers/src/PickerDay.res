type classes = {
  root?: string,
  dayOutsideMonth?: string,
  fillerCell?: string,
  today?: string,
  selected?: string,
  disabled?: string,
}

type props<'date> = {
  ...Mui.CommonProps.t,
  /** Override or extend the styles applied to the component. */
  classes?: classes,
  /** The date to show. */
  day: 'date,
  /** If `true`, renders as selected. @default false */
  selected?: bool,
  /** If `true`, renders as disabled. @default false */
  disabled?: bool,
  /** If `true`, day is the current day. @default false */
  today?: bool,
  /** If `true`, day is outside the current month. @default false */
  outsideCurrentMonth?: bool,
  /** If `true`, day is the first visible cell of the month. @default false */
  isFirstVisibleCell?: bool,
  /** If `true`, day is the last visible cell of the month. @default false */
  isLastVisibleCell?: bool,
  /** If `true`, the day is being animated. @default false */
  isAnimating?: bool,
  /** Callback fired when the day is selected. */
  onDaySelect: 'date => unit,
  onKeyDown?: (ReactEvent.Keyboard.t, 'date) => unit,
  onFocus?: (ReactEvent.Focus.t, 'date) => unit,
  onBlur?: (ReactEvent.Focus.t, 'date) => unit,
  onMouseEnter?: (ReactEvent.Mouse.t, 'date) => unit,
  onClick?: ReactEvent.Mouse.t => unit,
  onMouseDown?: ReactEvent.Mouse.t => unit,
  /** If `true`, today's date is rendered without a highlighting circle. @default false */
  disableHighlightToday?: bool,
  /** If `true`, days outside the current month are rendered. @default false */
  showDaysOutsideCurrentMonth?: bool,
  /** Whether the day should be rendered as visually selected. */
  isVisuallySelected?: bool,
  /** If `true`, the day is a filler cell whose content is hidden. */
  isDayFillerCell?: bool,
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "PickerDay"
