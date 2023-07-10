type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the transition group element. */
  viewTransitionContainer?: string,
}

type exportedDayCalendarProps = {
  /**
    * If `true`, calls `renderLoading` instead of rendering the day calendar.
    * Can be used to preload information and show it in calendar.
    * @default false
    */
  loading?: bool,
  /**
    * Formats the day of week displayed in the calendar header.
    * @param {string} day The day of week provided by the adapter's method `getWeekdays`.
    * @returns {string} The name to display.
    * @default (day) => day.charAt(0).toUpperCase()
    */
  dayOfWeekFormatter?: string => string,
  /**
    * If `true`, the week number will be display in the calendar.
    */
  displayWeekNumber?: bool,
  /**
    * Calendar will show more weeks in order to match this value.
    * Put it to 6 for having fix number of week in Gregorian calendars
    * @default undefined
    */
  fixedWeekNumber?: int,
}

type dayValidationProps<'date> = {
  /**
    * Disable specific date.
    * @template 'date
    * @param {'date} day The date to test.
    * @returns {boolean} If `true` the date will be disabled.
    */
  shouldDisableDate?: 'date => bool,
}

type exportedDateCalendarProps<'date> = {
  ...exportedDayCalendarProps,
  ...MonthCalendar.publicProps,
  ...YearCalendar.publicProps,
  ...Common.baseDateValidationProps<'date>,
  ...dayValidationProps<'date>,
  ...YearCalendar.yearValidationProps<'date>,
  ...MonthCalendar.monthValidationProps<'date>,
  ...Common.timezoneProps,
  /**
    * Default calendar month displayed when `value` and `defaultValue` are empty.
    */
  defaultCalendarMonth?: 'date,
  /**
    * If `true`, the picker and text field are disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * Make picker read only.
    * @default false
    */
  readOnly?: bool,
  /**
    * Disable heavy animations.
    * @default typeof navigator !== 'undefined' && /(android)/i.test(navigator.userAgent)
    */
  reduceAnimations?: bool,
  /**
    * Component displaying when passed `loading` true.
    * @returns {React.ReactNode} The node to render when loading.
    * @default () => <span data-mui-test="loading-progress">...</span>
    */
  renderLoading?: unit => React.element,
  /**
    * Callback fired on year change.
    * @template 'date
    * @param {'date} year The new year.
    */
  onYearChange?: 'date => unit,
  /**
    * Callback fired on month change.
    * @template 'date
    * @param {'date} month The new month.
    */
  onMonthChange?: 'date => unit,
}

type props<'date> = {
  ...Mui.CommonProps.t,
  ...exportedDateCalendarProps<'date>,
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
    * @default The closest valid date using the validation props, except callbacks such as `shouldDisableDate`.
    */
  referenceDate?: 'date,
  /**
    * Callback fired when the value changes.
    * @template 'date
    * @param {'date | null} value The new value.
    * @param {PickerSelectionState | undefined} selectionState Indicates if the date selection is complete.
    */
  onChange?: (Common.dateValue<'date>, option<Common.pickerSelectionState>) => unit,
  classes?: classes,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "DateCalendar"
