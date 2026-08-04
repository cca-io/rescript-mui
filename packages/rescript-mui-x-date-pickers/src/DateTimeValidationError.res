/** Validation errors emitted by date-time pickers and date-time fields. */
@unboxed
type t =
  | @as(null) None
  | @as("invalidDate") InvalidDate
  | @as("disableFuture") DisableFuture
  | @as("disablePast") DisablePast
  | @as("shouldDisableDate") ShouldDisableDate
  | @as("shouldDisableMonth") ShouldDisableMonth
  | @as("shouldDisableYear") ShouldDisableYear
  | @as("minDate") MinDate
  | @as("maxDate") MaxDate
  | @as("minutesStep") MinutesStep
  | @as("minTime") MinTime
  | @as("maxTime") MaxTime
  | @as("shouldDisableTime-hours") ShouldDisableHours
  | @as("shouldDisableTime-minutes") ShouldDisableMinutes
  | @as("shouldDisableTime-seconds") ShouldDisableSeconds
