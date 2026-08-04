open XDatePickerExampleSupport

module ControlledDigitalClock = {
  @react.component
  let make = () => {
    let (selected, setSelected) = React.useState(() => value("2026-08-04T14:30"))

    <Mui.Stack spacing={Number(1.)}>
      <MuiXDatePickers.DigitalClock
        value=selected onChange={(nextValue, _) => setSelected(_ => nextValue)} timeStep=30
      />
      <Mui.Typography variant=Caption color=TextSecondary>
        {("Selected: " ++ formatValue(selected))->React.string}
      </Mui.Typography>
    </Mui.Stack>
  }
}

module ControlledTimeClock = {
  @react.component
  let make = () => {
    let (selected, setSelected) = React.useState(() => value("2026-08-04T14:30"))

    <MuiXDatePickers.TimeClock
      value=selected onChange={(nextValue, _) => setSelected(_ => nextValue)} showViewSwitcher=true
    />
  }
}

@react.component
let make = () =>
  <Mui.Stack spacing={Number(4.)}>
    <Section
      title="Clock views"
      description="Analog, digital, and multi-section clocks, including controlled values and view restrictions."
    >
      <Card title="Basic analog clock" source="BasicTimeClock">
        <MuiXDatePickers.TimeClock defaultValue={value("2026-08-04T14:30")} />
      </Card>
      <Card title="Controlled analog clock" source="TimeClockValue">
        <ControlledTimeClock />
      </Card>
      <Card title="Clock views" source="TimeClockViews / TimeClockAmPm">
        <MuiXDatePickers.TimeClock
          defaultValue={value("2026-08-04T14:30")}
          ampm=false
          views={[MuiXDatePickers.Common.Hours, MuiXDatePickers.Common.Minutes]}
          openTo={MuiXDatePickers.Common.Minutes}
          showViewSwitcher=true
        />
      </Card>
    </Section>

    <Section
      title="Digital clocks" description="Single-column and multi-section digital clock behavior."
    >
      <Card title="Basic digital clock" source="DigitalClockBasic">
        <MuiXDatePickers.DigitalClock defaultValue={value("2026-08-04T14:30")} />
      </Card>
      <Card title="Controlled digital clock" source="DigitalClockValue">
        <ControlledDigitalClock />
      </Card>
      <Card
        title="Time step and disabled values"
        source="DigitalClockTimeStep / DigitalClockSkipDisabled"
      >
        <MuiXDatePickers.DigitalClock
          defaultValue={value("2026-08-04T14:30")}
          timeStep=15
          minTime={Dayjs.make("2026-08-04T09:00")}
          maxTime={Dayjs.make("2026-08-04T17:00")}
          skipDisabled=true
        />
      </Card>
      <Card title="24-hour digital clock" source="DigitalClockAmPm">
        <MuiXDatePickers.DigitalClock defaultValue={value("2026-08-04T14:30")} ampm=false />
      </Card>
      <Card title="Multi-section clock" source="TimePicker digital view">
        <MuiXDatePickers.MultiSectionDigitalClock
          defaultValue={value("2026-08-04T14:30:15")}
          ampm=false
          views=[
            MuiXDatePickers.Common.Hours,
            MuiXDatePickers.Common.Minutes,
            MuiXDatePickers.Common.Seconds,
          ]
          timeSteps={hours: 1, minutes: 5, seconds: 15}
        />
      </Card>
      <Card title="Read-only digital clock" source="DigitalClockFormProps">
        <MuiXDatePickers.DigitalClock defaultValue={value("2026-08-04T14:30")} readOnly=true />
      </Card>
    </Section>
  </Mui.Stack>
