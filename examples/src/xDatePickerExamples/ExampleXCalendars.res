open XDatePickerExampleSupport

module ControlledCalendar = {
  @react.component
  let make = () => {
    let (selected, setSelected) = React.useState(() => value("2026-08-04"))

    <Mui.Stack spacing={Number(1.)}>
      <MuiXDatePickers.DateCalendar
        value=selected onChange={(nextValue, _, _) => setSelected(_ => nextValue)}
      />
      <Mui.Typography variant=Caption color=TextSecondary>
        {("Selected: " ++ formatValue(selected))->React.string}
      </Mui.Typography>
    </Mui.Stack>
  }
}

@react.component
let make = () =>
  <Mui.Stack spacing={Number(4.)}>
    <Section
      title="Calendars"
      description="Date, month, and year calendar views with controlled and display variants."
    >
      <Card title="Basic calendar" source="BasicDateCalendar">
        <MuiXDatePickers.DateCalendar defaultValue={value("2026-08-04")} />
      </Card>
      <Card title="Controlled calendar" source="DateCalendarValue">
        <ControlledCalendar />
      </Card>
      <Card title="Calendar views" source="DateCalendarViews">
        <MuiXDatePickers.DateCalendar
          defaultValue={value("2026-08-04")}
          views={[MuiXDatePickers.Common.Year, MuiXDatePickers.Common.Day]}
          openTo={MuiXDatePickers.Common.Year}
        />
      </Card>
      <Card title="Week numbers" source="AddWeekNumber">
        <MuiXDatePickers.DateCalendar
          defaultValue={value("2026-08-04")}
          displayWeekNumber=true
          fixedWeekNumber=6
          showDaysOutsideCurrentMonth=true
        />
      </Card>
      <Card title="Read-only calendar" source="DateCalendarFormProps">
        <MuiXDatePickers.DateCalendar
          defaultValue={value("2026-08-04")} readOnly=true disableHighlightToday=true
        />
      </Card>
      <Card title="Reference date" source="DateCalendarReferenceDate">
        <MuiXDatePickers.DateCalendar
          referenceDate={Dayjs.make("2028-02-01")}
          minDate={Dayjs.make("2028-01-01")}
          maxDate={Dayjs.make("2028-12-31")}
        />
      </Card>
    </Section>

    <Section
      title="Month and year calendars"
      description="Standalone calendar views and descending year order."
    >
      <Card title="Month calendar" source="YearMonthCalendar">
        <MuiXDatePickers.MonthCalendar defaultValue={value("2026-08-04")} monthsPerRow=#4 />
      </Card>
      <Card title="Year calendar" source="YearMonthCalendar">
        <MuiXDatePickers.YearCalendar
          defaultValue={value("2026-08-04")}
          yearsPerRow=#4
          minDate={Dayjs.make("2020-01-01")}
          maxDate={Dayjs.make("2030-12-31")}
        />
      </Card>
      <Card title="Descending years" source="YearsOrderDescendingCalendar">
        <MuiXDatePickers.YearCalendar
          yearsOrder=#desc maxDate={Dayjs.now()} minDate={Dayjs.make("2016-01-01")}
        />
      </Card>
    </Section>
  </Mui.Stack>
