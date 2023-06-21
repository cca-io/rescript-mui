type adapterFormats = {
  // Token formats
  /**
   * The 4-digit year.
   * @example "2019"
   */
  year: string,
  /**
   * The full month name.
   * @example "January"
   */
  month: string,
  /**
   * The abbreviated month name.
   * @example "Jan"
   */
  monthShort: string,
  /**
   * The day of the month.
   * @example "1"
   */
  dayOfMonth: string,
  /**
   * The name of the day of the week.
   * @example "Wednesday"
   */
  weekday: string,
  /**
   * The abbreviated name of the day of the week.
   * @example "Wed"
   * */
  weekdayShort: string,
  /**
   * The hours, 24-hour clock.
   * @example "23"
   */
  hours24h: string,
  /**
   * The hours, 12-hour clock.
   * @example "11"
   */
  hours12h: string,
  /**
   * The meridiem.
   * @example "AM"
   */
  meridiem: string,
  /**
   * The minutes.
   * @example "44"
   */
  minutes: string,
  /**
   * The seconds.
   * @example "00"
   */
  seconds: string,
  // Date formats
  /** The localized full date.
   * Used for the aria-label of the opening button of the `DatePicker`.
   * @example "Jan 1, 2019"
   */
  fullDate: string,
  /**
   * A keyboard input friendly date format.
   * Used in the date fields.
   * @example "02/13/2020
   */
  keyboardDate: string,
  /**
   * The abbreviated month name and the day of the month.
   * Used in the `DateRangePicker` toolbar.
   * @example "Jan 1"
   */
  shortDate: string,
  /**
   * The month name and the day of the month.
   * Used in the `DatePicker` toolbar for non-english locales.
   * @example "1 January"
   */
  normalDate: string,
  /**
   * The month name, the day of the week and the day of the month.
   * Used in the `DatePicker` toolbar for english locales.
   * @example "Sun, Jan 1"
   */
  normalDateWithWeekday: string,
  // Time formats
  /**
   * The hours and the minutes.
   * Used for the aria-label of the opening button of the `TimePicker`.
   * @example "11:44 PM" for locales with meridiem, "23:44" for locales without meridiem.
   */
  fullTime: string,
  /**
   * The hours with the meridiem and minutes.
   * @example "11:44 PM"
   */
  fullTime12h: string,
  /**
   * The hours without the meridiem and minutes.
   * @example "23:44"
   */
  fullTime24h: string,
  // Date & Time formats

  /**
   * A keyboard input friendly time format.
   * Used in the date-time fields.
   * @example "02/13/2020 11:44 PM" for locales with meridiem, "02/13/2020 23:44" for locales without meridiem.
   */
  keyboardDateTime: string,
  /**
   * A keyboard input friendly time format for 12-hour clock.
   * Used in the date-time fields.
   * @example "02/13/2020 11:44 PM"
   */
  keyboardDateTime12h: string,
  /**
   * A keyboard input friendly time format for 24-hour clock.
   * Used in the date-time fields.
   * @example "02/13/2020 23:44"
   */
  keyboardDateTime24h: string,
}

@unboxed
type formatKey =
  | @as("year") Year
  | @as("month") Month
  | @as("monthShort") MonthShort
  | @as("dayOfMonth") DayOfMonth
  | @as("weekday") Weekday
  | @as("weekdayShort") WeekdayShort
  | @as("hours24h") Hours24h
  | @as("hours12h") Hours12h
  | @as("meridiem") Meridiem
  | @as("minutes") Minutes
  | @as("seconds") Seconds
  | @as("fullDate") FullDate
  | @as("keyboardDate") KeyboardDate
  | @as("shortDate") ShortDate
  | @as("normalDate") NormalDate
  | @as("normalDateWithWeekday") NormalDateWithWeekday
  | @as("fullTime") FullTime
  | @as("fullTime12h") FullTime12h
  | @as("fullTime24h") FullTime24h
  | @as("keyboardDateTime") KeyboardDateTime
  | @as("keyboardDateTime12h") KeyboardDateTime12h
  | @as("keyboardDateTime24h") KeyboardDateTime24h
  | String(string)

type escapedCharacters = {start: string, end: string}

type fieldFormatTokenObj = {
  sectionType: Fields.fieldSectionType,
  contentType: Fields.fieldSectionContentType,
  maxLength?: int,
}

type fieldFormatToken
// | Object(fieldFormatTokenObj)
// | Field(Fields.fieldSectionType)

type fieldFormatTokenMap = Js.Dict.t<fieldFormatToken>

@unboxed
type date<'date> =
  | Date('date)
  | @as(null) Null

type pickersTimezone // TODO

type meridiem =
  | @as("am") AM
  | @as("pm") PM

type muiPickersAdapter<'date, 'locale> = {
  /**
   * A boolean confirming that the adapter used is an MUI adapter.
   */
  isMUIAdapter: bool,
  isTimezoneCompatible: bool,
  formats: adapterFormats,
  locale?: 'locale,
  /**
   * Name of the library that is used right now
   */
  lib: string,
  /**
   * The characters used to escape a string inside a format.
   */
  escapedCharacters: escapedCharacters,
  /**
   * A map containing all the format that the field components can understand.
   */
  formatTokenMap: fieldFormatTokenMap,
  /**
   * Create a date in the date library format.
   * If no `value` parameter is provided, creates a date with the current timestamp.
   * If a `value` parameter is provided, pass it to the date library to try to parse it.
   * @template 'date
   * @param {any} value The optional value to parse.
   * @returns {'date | null} The parsed date.
   */
  date: option<string> => date<'date>,
  /**
   * Create a date in the date library format.
   * If no `value` parameter is provided, creates a date with the current timestamp.
   * If a `value` parameter is provided, pass it to the date library to try to parse it.
   * @template 'date
   * @param {string | null | undefined} value The optional value to parse.
   * @param {string} timezone The timezone of the date.
   * @returns {'date | null} The parsed date.
   */
  dateWithTimezone: (option<string>, pickersTimezone) => date<'date>,
  /**
   * Extracts the timezone from a date.
   * @template 'date
   * @param {'date} value The date from which we want to get the timezone.
   */
  getTimezone: date<'date> => string,
  /**
   * Convert a date to another timezone.
   * @template 'date
   * @param {'date} value The date to convert.
   * @param {string} timezone The timezone to convert the date to.
   * @returns {'date} The converted date.
   */
  setTimezone: (date<'date>, pickersTimezone) => 'date,
  /**
   * Convert a date in the library format into a JavaScript `Date` object.
   * @template 'date
   * @param {'date} value The value to convert.
   * @returns {Date} the JavaScript date.
   */
  toJsDate: date<'date> => Js.Date.t,
  /**
   * Parse an iso string into a date in the date library format.
   * @deprecate Will be removed in v7.
   * @template 'date
   * @param {string} isoString The iso string to parse.
   * @returns {'date} the parsed date.
   */
  parseISO: string => 'date,
  /**
   * Stringify a date in the date library format into an ISO string.
   * @deprecate Will be removed in v7.
   * @template 'date
   * @param {'date} value The date to stringify.
   * @returns {string} the iso string representing the date.
   */
  toISO: 'date => string,
  /**
   * Parse a string date in a specific format.
   * @template 'date
   * @param {string} value The string date to parse.
   * @param {string} format The format in which the string date is.
   * @returns {'date | null} The parsed date.
   */
  parse: (string, ~format: string) => date<'date>,
  /**
   * Get the code of the locale currently used by the adapter.
   * @returns {string} The code of the locale.
   */
  getCurrentLocaleCode: unit => string,
  /**
   * Check if the current locale is using 12 hours cycle (i.e: time with meridiem).
   * @returns {boolean} `true` if the current locale is using 12 hours cycle.
   */
  is12HourCycleInCurrentLocale: unit => bool,
  /**
   * Create a format with no meta-token (e.g: `LLL` or `PP`).
   * @param {string} format The format to expand.
   * @returns {string} The expanded format.
   */
  expandFormat: string => string,
  /**
   * Check if the date is valid.
   * @param {any} value The value to test.
   * @returns {boolean} `true` if the value is valid.
   */
  isValid: 'date => bool,
  /**
   * Format a date using an adapter format string (see the `AdapterFormats` interface)
   * @template 'date
   * @param {'date} value The date to format.
   * @param {keyof AdapterFormats} formatKey The formatKey to use.
   * @returns {string} The stringify date.
   */
  format: ('date, formatKey) => string,
  /**
   * Format a date using a format of the date library.
   * @template 'date
   * @param {'date} value The date to format.
   * @param {string} formatString The format to use.
   * @returns {string} The stringify date.
   */
  formatByString: ('date, string) => string,
  /**
   * Format a number to be rendered in the clock.
   * Is being used in hijri and jalali adapters.
   * @param {string} numberToFormat The number to format.
   * @returns {string} The formatted number.
   */
  formatNumber: string => string,
  /**
   * Check if the two dates are equal (e.g: they represent the same timestamp).
   * @param {any} value The reference date.
   * @param {any} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the two dates are equal.
   */
  isEqual: ('date, 'date) => bool,
  /**
   * Check if the two dates are in the same year (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the two dates are in the same year.
   */
  isSameYear: ('date, 'date) => bool,
  /**
   * Check if the two dates are in the same month (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the two dates are in the same month.
   */
  isSameMonth: ('date, 'date) => bool,
  /**
   * Check if the two dates are in the same day (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the two dates are in the same day.
   */
  isSameDay: ('date, 'date) => bool,
  /**
   * Check if the two dates are at the same hour (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the two dates are in the same hour.
   */
  isSameHour: ('date, 'date) => bool,
  /**
   * Check if the reference date is after the second date.
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the reference date is after the second date.
   */
  isAfter: ('date, 'date) => bool,
  /**
   * Check if the year of the reference date is after the year of the second date (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the year of the reference date is after the year of the second date.
   */
  isAfterYear: ('date, 'date) => bool,
  /**
   * Check if the day of the reference date is after the day of the second date (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the day of the reference date is after the day of the second date.
   */
  isAfterDay: ('date, 'date) => bool,
  /**
   * Check if the reference date is before the second date.
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the reference date is before the second date.
   */
  isBefore: ('date, 'date) => bool,
  /**
   * Check if the year of the reference date is before the year of the second date (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the year of the reference date is before the year of the second date.
   */
  isBeforeYear: ('date, 'date) => bool,
  /**
   * Check if the day of the reference date is before the day of the second date (using the timezone of the reference date).
   * @template 'date
   * @param {'date} value The reference date.
   * @param {'date} comparing The date to compare with the reference date.
   * @returns {boolean} `true` if the day of the reference date is before the day of the second date.
   */
  isBeforeDay: ('date, 'date) => bool,
  /**
   * Check if the value is withing the provided range.
   * @template 'date
   * @param {'date} value The value to test.
   * @param {['date, 'date]} range The range in which the value should be.
   * @returns {boolean} `true` if the value is within the provided range.
   */
  isWithinRange: ('date, ('date, 'date)) => bool,
  /**
   * Return the start of the year for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The start of the year of the given date.
   */
  startOfYear: 'date => 'date,
  /**
   * Return the start of the month for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The start of the month of the given date.
   */
  startOfMonth: 'date => 'date,
  /**
   * Return the start of the week for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The start of the week of the given date.
   */
  startOfWeek: 'date => 'date,
  /**
   * Return the start of the day for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The start of the day of the given date.
   */
  startOfDay: 'date => 'date,
  /**
   * Return the end of the year for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The end of the year of the given date.
   */
  endOfYear: 'date => 'date,
  /**
   * Return the end of the month for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The end of the month of the given date.
   */
  endOfMonth: 'date => 'date,
  /**
   * Return the end of the week for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The end of the week of the given date.
   */
  endOfWeek: 'date => 'date,
  /**
   * Return the end of the day for the given date.
   * @template 'date
   * @param {'date} value The original date.
   * @returns {'date} The end of the day of the given date.
   */
  endOfDay: 'date => 'date,
  /**
   * Add the specified number of years to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of years to be added.
   * @returns {'date} The new date with the years added.
   */
  addYears: ('date, int) => 'date,
  /**
   * Add the specified number of months to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of months to be added.
   * @returns {'date} The new date with the months added.
   */
  addMonths: ('date, int) => 'date,
  /**
   * Add the specified number of weeks to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of weeks to be added.
   * @returns {'date} The new date with the weeks added.
   */
  addWeeks: ('date, int) => 'date,
  /**
   * Add the specified number of days to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of days to be added.
   * @returns {'date} The new date with the days added.
   */
  addDays: ('date, int) => 'date,
  /**
   * Add the specified number of hours to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of hours to be added.
   * @returns {'date} The new date with the hours added.
   */
  addHours: ('date, int) => 'date,
  /**
   * Add the specified number of minutes to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of minutes to be added.
   * @returns {'date} The new date with the minutes added.
   */
  addMinutes: ('date, int) => 'date,
  /**
   * Add the specified number of seconds to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} amount The amount of seconds to be added.
   * @returns {'date} The new date with the seconds added.
   */
  addSeconds: ('date, int) => 'date,
  /**
   * Get the year of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The year of the given date.
   */
  getYear: 'date => int,
  /**
   * Get the month of the given date.
   * The value is 0-based, in the Gregorian calendar January = 0, February = 1, ...
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The month of the given date.
   */
  getMonth: 'date => int,
  /**
   * Get the date (e.g: the day in the month) of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The date of the given date.
   */
  getDate: 'date => int,
  /**
   * Get the hours of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The hours of the given date.
   */
  getHours: 'date => int,
  /**
   * Get the minutes of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The minutes of the given date.
   */
  getMinutes: 'date => int,
  /**
   * Get the seconds of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The seconds of the given date.
   */
  getSeconds: 'date => int,
  /**
   * Get the milliseconds of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The milliseconds of the given date.
   */
  getMilliseconds: 'date => int,
  /**
   * Set the year to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} year The year of the new date.
   * @returns {'date} The new date with the year set.
   */
  setYear: ('date, int) => 'date,
  /**
   * Set the month to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} month The month of the new date.
   * @returns {'date} The new date with the month set.
   */
  setMonth: ('date, int) => 'date,
  /**
   * Set the date (e.g: the day in the month) to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} date The date of the new date.
   * @returns {'date} The new date with the date set.
   */
  setDate: ('date, int) => 'date,
  /**
   * Set the hours to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} hours The hours of the new date.
   * @returns {'date} The new date with the hours set.
   */
  setHours: ('date, int) => 'date,
  /**
   * Set the minutes to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} minutes The minutes of the new date.
   * @returns {'date} The new date with the minutes set.
   */
  setMinutes: ('date, int) => 'date,
  /**
   * Set the seconds to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} seconds The seconds of the new date.
   * @returns {'date} The new date with the seconds set.
   */
  setSeconds: ('date, int) => 'date,
  /**
   * Set the milliseconds to the given date.
   * @template 'date
   * @param {'date} value The date to be changed.
   * @param {number} milliseconds The milliseconds of the new date.
   * @returns {'date} The new date with the milliseconds set.
   */
  setMilliseconds: ('date, int) => 'date,
  /**
   * Get the number of days in a month of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The number of days in the month
   */
  getDaysInMonth: 'date => int,
  /**
   * Get the label of each day of a week.
   * @returns {string[]} The label of each day of a week.
   */
  getWeekdays: unit => array<string>,
  /**
   * Create a nested list with all the days of the month of the given date grouped by week.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {'date[][]} A nested list with all the days of the month grouped by week.
   */
  getWeekArray: 'date => array<array<'date>>,
  /**
   * Get the number of the week of the given date.
   * @template 'date
   * @param {'date} value The given date.
   * @returns {number} The number of the week of the given date.
   */
  getWeekNumber: 'date => int,
  /**
   * Create a list with all the years between the start end the end date.
   * @template 'date
   * @param {'date} start The start of the range.
   * @param {'date} end The end of the range.
   * @returns {'date[]} List of all the years between the start end the end date.
   */
  getYearRange: (~start: 'date, ~end: 'date) => array<'date>,
  /**
   * Allow to customize how the "am"` and "pm" strings are rendered.
   * @param {"am" | "pm"} meridiem The string to render.
   * @return {string} The formatted string.
   */
  getMeridiemText: meridiem => string,
}
