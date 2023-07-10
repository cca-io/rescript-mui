type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type publicProps = {
  /**
    * Years rendered per row.
    * @default 3
    */
  yearsPerRow?: [#3 | #4],
}

type yearValidationProps<'date> = {
  /**
    * Disable specific year.
    * @template TDate
    * @param {TDate} year The year to test.
    * @returns {boolean} If `true`, the year will be disabled.
    */
  shouldDisableYear?: 'date => bool,
}

type props<'date> = {
  ...publicProps,
  ...yearValidationProps<'date>,
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
    * @default The closest valid year using the validation props, except callbacks such as `shouldDisableYear`.
    */
  referenceDate?: 'date,
  /**
    * Callback fired when the value changes.
    * @template 'date
    * @param {'date} value The new value.
    */
  onChange?: 'date => unit,
  /** If `true` picker is readonly */
  readOnly?: bool,
  /**
    * If `true`, today's date is rendering without highlighting with circle.
    * @default false
    */
  disableHighlightToday?: bool,
  onYearFocus?: int => unit,
  hasFocus?: bool,
  onFocusedViewChange?: bool => unit,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "YearCalendar"
