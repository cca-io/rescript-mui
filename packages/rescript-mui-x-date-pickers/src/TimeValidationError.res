/** Validation errors emitted by time pickers and time fields. */
@unboxed
type t =
  | @as(null) NoError
  | @as("invalidDate") InvalidDate
  | @as("disableFuture") DisableFuture
  | @as("disablePast") DisablePast
  | @as("minutesStep") MinutesStep
  | @as("minTime") MinTime
  | @as("maxTime") MaxTime
  | @as("shouldDisableTime-hours") ShouldDisableHours
  | @as("shouldDisableTime-minutes") ShouldDisableMinutes
  | @as("shouldDisableTime-seconds") ShouldDisableSeconds
