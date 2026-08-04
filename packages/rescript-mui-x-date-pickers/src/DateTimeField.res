type props<'date, 'inputRef> = {
  ...DateField.commonProps<'date, DateTimeValidationError.t, 'inputRef>,
  ampm?: bool,
  disableFuture?: bool,
  disablePast?: bool,
  minDate?: 'date,
  maxDate?: 'date,
  shouldDisableDate?: 'date => bool,
  shouldDisableMonth?: 'date => bool,
  shouldDisableYear?: 'date => bool,
  minTime?: 'date,
  maxTime?: 'date,
  minutesStep?: int,
  shouldDisableTime?: ('date, Common.timeView) => bool,
  disableIgnoringDatePartForTimeValidation?: bool,
  minDateTime?: 'date,
  maxDateTime?: 'date,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date, 'inputRef>> = "DateTimeField"
