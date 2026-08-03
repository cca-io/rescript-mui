type props<'value, 'error, 'inputRef> = {
  ...DateField.commonProps<'value, 'error, 'inputRef>,
  ampm?: bool,
  disableFuture?: bool,
  disablePast?: bool,
  minTime?: 'value,
  maxTime?: 'value,
  minutesStep?: int,
  shouldDisableTime?: ('value, Common.timeView) => bool,
  disableIgnoringDatePartForTimeValidation?: bool,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'value, 'error, 'inputRef>> = "TimeField"
