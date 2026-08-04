/** Validation errors emitted by date pickers and date fields. */
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
