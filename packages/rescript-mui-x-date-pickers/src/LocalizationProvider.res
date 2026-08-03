type dateAdapter

type fieldYearPlaceholderParams = {
  digitAmount: int,
  format: string,
}

type fieldContentPlaceholderParams = {
  contentType: Fields.fieldSectionContentType,
  format: string,
}

type fieldFormatPlaceholderParams = {format: string}

/** All fields are optional because MUI's `PickersInputLocaleText` is a partial locale. */
type pickersInputLocaleText = {
  datePickerToolbarTitle?: string,
  timePickerToolbarTitle?: string,
  dateTimePickerToolbarTitle?: string,
  dateRangePickerToolbarTitle?: string,
  timeRangePickerToolbarTitle?: string,
  previousMonth?: string,
  nextMonth?: string,
  calendarWeekNumberHeaderLabel?: string,
  calendarWeekNumberHeaderText?: string,
  calendarWeekNumberAriaLabelText?: int => string,
  calendarWeekNumberText?: int => string,
  openPreviousView?: string,
  openNextView?: string,
  calendarViewSwitchingButtonAriaLabel?: Common.dateView => string,
  start?: string,
  end?: string,
  startDate?: string,
  startTime?: string,
  endDate?: string,
  endTime?: string,
  cancelButtonLabel?: string,
  clearButtonLabel?: string,
  okButtonLabel?: string,
  todayButtonLabel?: string,
  nextStepButtonLabel?: string,
  clockLabelText?: (Common.timeView, Nullable.t<string>) => string,
  hoursClockNumberText?: string => string,
  minutesClockNumberText?: string => string,
  secondsClockNumberText?: string => string,
  selectViewText?: Common.timeViewWithMeridiem => string,
  openDatePickerDialogue?: Nullable.t<string> => string,
  openTimePickerDialogue?: Nullable.t<string> => string,
  openRangePickerDialogue?: Nullable.t<string> => string,
  fieldClearLabel?: string,
  timeTableLabel?: string,
  dateTableLabel?: string,
  fieldYearPlaceholder?: fieldYearPlaceholderParams => string,
  fieldMonthPlaceholder?: fieldContentPlaceholderParams => string,
  fieldDayPlaceholder?: fieldFormatPlaceholderParams => string,
  fieldWeekDayPlaceholder?: fieldContentPlaceholderParams => string,
  fieldHoursPlaceholder?: fieldFormatPlaceholderParams => string,
  fieldMinutesPlaceholder?: fieldFormatPlaceholderParams => string,
  fieldSecondsPlaceholder?: fieldFormatPlaceholderParams => string,
  fieldMeridiemPlaceholder?: fieldFormatPlaceholderParams => string,
  year?: string,
  month?: string,
  day?: string,
  weekDay?: string,
  hours?: string,
  minutes?: string,
  seconds?: string,
  meridiem?: string,
  empty?: string,
}

type props<'date, 'locale> = {
  ...Mui.CommonProps.t_NoRef,
  /** Locale for the date library being used. */
  adapterLocale?: 'locale,
  children?: React.element,
  /** Date library adapter class. */
  dateAdapter?: dateAdapter,
  /** Formats used by child pickers. */
  dateFormats?: Adapters.adapterFormats,
  /** Date library instance with global overrides. */
  dateLibInstance?: 'date,
  /** Locale text overrides. */
  localeText?: pickersInputLocaleText,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date, 'locale>> = "LocalizationProvider"
