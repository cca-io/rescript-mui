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
