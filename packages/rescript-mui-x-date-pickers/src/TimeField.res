type props<'date, 'inputRef> = {
  ...DateField.commonProps<'date, TimeValidationError.t, 'inputRef>,
  ampm?: bool,
  disableFuture?: bool,
  disablePast?: bool,
  minTime?: 'date,
  maxTime?: 'date,
  minutesStep?: int,
  shouldDisableTime?: ('date, Common.timeView) => bool,
  disableIgnoringDatePartForTimeValidation?: bool,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date, 'inputRef>> = "TimeField"
