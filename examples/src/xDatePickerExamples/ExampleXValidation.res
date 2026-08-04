open XDatePickerExampleSupport

let dateErrorMessage = error =>
  switch error {
  | MuiXDatePickers.DateValidationError.NoError => ""
  | InvalidDate => "Enter a valid date"
  | DisableFuture => "Future dates are disabled"
  | DisablePast => "Past dates are disabled"
  | ShouldDisableDate => "That date is unavailable"
  | ShouldDisableMonth => "That month is unavailable"
  | ShouldDisableYear => "That year is unavailable"
  | MinDate => "The date is too early"
  | MaxDate => "The date is too late"
  }

module ErrorUnderField = {
  @react.component
  let make = () => {
    let (error, setError) = React.useState(() => MuiXDatePickers.DateValidationError.NoError)
    let message = dateErrorMessage(error)

    <MuiXDatePickers.DatePicker
      label={"August 2026 only"->React.string}
      defaultValue={value("2026-08-04")}
      minDate={Dayjs.make("2026-08-01")}
      maxDate={Dayjs.make("2026-08-31")}
      onError={(nextError, _) => setError(_ => nextError)}
      slotProps={
        textField: {
          error: message != "",
          helperText: message->React.string,
        },
      }
    />
  }
}

@react.component
let make = () =>
  <Mui.Stack spacing={Number(4.)}>
    <Section
      title="Date validation"
      description="Minimums, maximums, past/future rules, and custom date predicates."
    >
      <Card title="Minimum and maximum date" source="DateValidationMinDate / DateValidationMaxDate">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DatePicker
            label={"From August 2026"->React.string}
            defaultValue={value("2026-08-04")}
            minDate={Dayjs.make("2026-08-01")}
          />
          <MuiXDatePickers.DatePicker
            label={"Until August 2026"->React.string}
            defaultValue={value("2026-08-04")}
            maxDate={Dayjs.make("2026-08-31")}
          />
        </Mui.Stack>
      </Card>
      <Card
        title="Past and future" source="DateValidationDisablePast / DateValidationDisableFuture"
      >
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DatePicker label={"No past dates"->React.string} disablePast=true />
          <MuiXDatePickers.DatePicker label={"No future dates"->React.string} disableFuture=true />
        </Mui.Stack>
      </Card>
      <Card title="Custom disabled dates" source="DateValidationShouldDisableDate">
        <MuiXDatePickers.DateCalendar
          defaultValue={value("2026-08-04")}
          shouldDisableDate={date => {
            let weekday = date->Dayjs.day
            weekday == 0 || weekday == 6
          }}
        />
      </Card>
      <Card title="Month and year rules" source="DateValidationShouldDisableMonth / Year">
        <MuiXDatePickers.DatePicker
          label={"Selected months and years"->React.string}
          defaultValue={value("2026-08-04")}
          shouldDisableMonth={date => date->Dayjs.month == 0}
          shouldDisableYear={date => date->Dayjs.year == 2027}
        />
      </Card>
      <Card title="Typed error below field" source="RenderErrorUnderField">
        <ErrorUnderField />
      </Card>
    </Section>

    <Section
      title="Time and date-time validation"
      description="Time windows, custom time predicates, and date-time boundaries."
    >
      <Card title="Time window" source="TimeValidationMinTime / TimeValidationMaxTime">
        <MuiXDatePickers.TimePicker
          label={"Office hours"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          minTime={Dayjs.make("2026-08-04T09:00")}
          maxTime={Dayjs.make("2026-08-04T17:00")}
        />
      </Card>
      <Card title="Custom time rule" source="TimeValidationShouldDisableTime">
        <MuiXDatePickers.TimePicker
          label={"Even hours only"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          shouldDisableTime={(date, view) =>
            switch view {
            | MuiXDatePickers.Common.Hours => date->Dayjs.hour % 2 != 0
            | _ => false
            }}
        />
      </Card>
      <Card title="Date-time window" source="DateTimeValidationMinDateTime / MaxDateTime">
        <MuiXDatePickers.DateTimePicker
          label={"Conference booking"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          minDateTime={Dayjs.make("2026-08-04T09:00")}
          maxDateTime={Dayjs.make("2026-08-06T17:00")}
        />
      </Card>
    </Section>
  </Mui.Stack>
