type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type publicProps = {
  /**
    * Months rendered per row.
    * @default 3
    */
  monthsPerRow?: [#3 | #4],
}

type monthValidationProps<'date> = {
  /**
    * Disable specific month.
    * @template TDate
    * @param {TDate} month The month to test.
    * @returns {boolean} If `true`, the month will be disabled.
    */
  shouldDisableMonth?: 'date => bool,
}

type props<'date> = {
  ...publicProps,
  ...monthValidationProps<'date>,
  ...Common.baseDateValidationProps<'date>,
  ...Common.timezoneProps,
  autoFocus?: bool,
  /**
    * className applied to the root element.
    */
  className?: string,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
  /** If `true` picker is disabled */
  disabled?: bool,
  /**
    * The selected value.
    * Used when the component is controlled.
    */
  value?: Common.dateValue<'date>,
  /**
    * The default selected value.
    * Used when the component is not controlled.
    */
  defaultValue?: Common.dateValue<'date>,
  /**
    * The date used to generate the new value when both `value` and `defaultValue` are empty.
    * @default The closest valid month using the validation props, except callbacks such as `shouldDisableMonth`.
    */
  referenceDate?: 'date,
  /**
    * Callback fired when the value changes.
    * @template TDate
    * @param {TDate} value The new value.
    */
  onChange?: 'date => unit,
  /** If `true` picker is readonly */
  readOnly?: bool,
  /**
    * If `true`, today's date is rendering without highlighting with circle.
    * @default false
    */
  disableHighlightToday?: bool,
  onMonthFocus?: int => unit,
  hasFocus?: bool,
  onFocusedViewChange?: bool => unit,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "MonthCalendar"
