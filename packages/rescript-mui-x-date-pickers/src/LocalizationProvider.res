// In TypeScript:
// new (...args: any) => MuiPickersAdapter<TDate, TLocale>;
type dateAdapter

type dateView

type timeView

type fieldYearPlaceholderParams = {digitAmount: int}
type fieldMonthPlaceholderParams = {contentType: Fields.fieldSectionContentType}
type fieldWeekDayPlaceholderParams = {contentType: Fields.fieldSectionContentType}

type pickersInputLocaleText<'date, 'locale> = {
  // Calendar navigation
  previousMonth: string,
  nextMonth: string,
  // Calendar week number
  calendarWeekNumberHeaderLabel: string,
  calendarWeekNumberHeaderText: string,
  calendarWeekNumberAriaLabelText: int => string,
  calendarWeekNumberText: int => string,
  // View navigation
  openPreviousView: string,
  openNextView: string,
  calendarViewSwitchingButtonAriaLabel: dateView => string,
  // DateRange placeholders
  start: string,
  end: string,
  // Action bar
  cancelButtonLabel: string,
  clearButtonLabel: string,
  okButtonLabel: string,
  todayButtonLabel: string,
  // Clock labels
  clockLabelText: (
    timeView,
    Common.dateValue<'date>,
    Adapters.muiPickersAdapter<'date, 'locale>,
  ) => string,
  hoursClockNumberText: string => string,
  minutesClockNumberText: string => string,
  secondsClockNumberText: string => string,
  // Digital clock labels
  selectViewText: Common.timeViewWithMeridiem => string,
  // Open picker labels
  openDatePickerDialogue: (
    Common.dateValue<'date>,
    Adapters.muiPickersAdapter<'date, 'locale>,
  ) => string,
  openTimePickerDialogue: (
    Common.dateValue<'date>,
    Adapters.muiPickersAdapter<'date, 'locale>,
  ) => string,
  // Table labels
  timeTableLabel: string,
  dateTableLabel: string,
  // Field section placeholders
  fieldYearPlaceholder: fieldYearPlaceholderParams => string,
  fieldMonthPlaceholder: fieldMonthPlaceholderParams => string,
  fieldDayPlaceholder: unit => string,
  fieldWeekDayPlaceholder: fieldWeekDayPlaceholderParams => string,
  fieldHoursPlaceholder: unit => string,
  fieldMinutesPlaceholder: unit => string,
  fieldSecondsPlaceholder: unit => string,
  fieldMeridiemPlaceholder: unit => string,
}

type props<'date, 'locale> = {
  ...Mui.CommonProps.t_NoRef,
  /**
    * Locale for the date library you are using
    */
  adapterLocale?: 'locale,
  children?: React.element,
  /**
    * Date library adapter class function.
    * @see See the localization provider {@link https://mui.com/x/react-date-pickers/getting-started/#setup-your-date-library-adapter date adapter setup section} for more details.
    */
  dateAdapter?: dateAdapter,
  /** 
    * Formats that are used for any child pickers 
    */
  dateFormats?: Adapters.adapterFormats,
  /**
    * Date library instance you are using, if it has some global overrides
    * ```jsx
    * dateLibInstance={momentTimeZone}
    * ```
    */
  dateLibInstance?: 'date,
  /**
    * Locale for components texts
    */
  localeText?: pickersInputLocaleText<'date, 'locale>,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date, 'locale>> = "LocalizationProvider"
