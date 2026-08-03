type props<'value, 'error, 'inputRef> = {
  ...DateField.commonProps<'value, 'error, 'inputRef>,
  ampm?: bool,
  disableFuture?: bool,
  disablePast?: bool,
  minDate?: 'value,
  maxDate?: 'value,
  shouldDisableDate?: 'value => bool,
  shouldDisableMonth?: 'value => bool,
  shouldDisableYear?: 'value => bool,
  minTime?: 'value,
  maxTime?: 'value,
  minutesStep?: int,
  shouldDisableTime?: ('value, Common.timeView) => bool,
  disableIgnoringDatePartForTimeValidation?: bool,
  minDateTime?: 'value,
  maxDateTime?: 'value,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'value, 'error, 'inputRef>> = "DateTimeField"
