type dateView =
  | @as("year") Year
  | @as("month") Month
  | @as("day") Day

type timeView =
  | @as("hours") Hours
  | @as("minutes") Minutes
  | @as("seconds") Seconds

type dateOrTimeView =
  | @as("year") Year
  | @as("month") Month
  | @as("day") Day
  | @as("hours") Hours
  | @as("minutes") Minutes
  | @as("seconds") Seconds

type timeViewWithMeridiem =
  | @as("hours") Hours
  | @as("minutes") Minutes
  | @as("seconds") Seconds
  | @as("meridiem") Meridiem

type dateOrTimeViewWithMeridiem =
  | @as("year") Year
  | @as("month") Month
  | @as("day") Day
  | @as("hours") Hours
  | @as("minutes") Minutes
  | @as("seconds") Seconds
  | @as("meridiem") Meridiem

@unboxed
type wrapperVariant =
  | @as("mobile") Mobile
  | @as("desktop") Desktop
  | @as(null) Null

type pickerSelectionState =
  | @as("partial") Partial
  | @as("shallow") Shallow
  | @as("finish") Finish

@unboxed
type dateValue<'date> =
  | @as(null) Null
  | Date('date)

@unboxed
type pickersTimezone =
  | @as("default") Default
  | @as("system") System
  | @as("UTC") UTC
  | String(string)

type baseDateValidationProps<'date> = {
  /**
    * Maximal selectable date.
    */
  maxDate?: 'date,
  /**
    * Minimal selectable date.
    */
  minDate?: 'date,
}

type timezoneProps = {
  /**
    * Choose which timezone to use for the value.
    * Example: "default", "system", "UTC", "America/New_York".
    * If you pass values from other timezones to some props, they will be converted to this timezone before being used.
    * @see See the {@link https://mui.com/x/react-date-pickers/timezone/ timezones documention} for more details.
    * @default The timezone of the `value` or `defaultValue` prop is defined, 'default' otherwise.
    */
  timezone?: pickersTimezone,
}
