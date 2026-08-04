open XDatePickerExampleSupport

module ControlledDatePicker = {
  @react.component
  let make = () => {
    let (selected, setSelected) = React.useState(() => value("2026-08-04"))

    <Mui.Stack spacing={Number(1.)}>
      <MuiXDatePickers.DatePicker
        label={"Controlled date"->React.string}
        value=selected
        onChange={(nextValue, _) => setSelected(_ => nextValue)}
      />
      <Mui.Typography variant=Caption color=TextSecondary>
        {("Value: " ++ formatValue(selected))->React.string}
      </Mui.Typography>
    </Mui.Stack>
  }
}

@react.component
let make = () =>
  <Mui.Stack spacing={Number(4.)}>
    <Section
      title="Picker families"
      description="Responsive, desktop, mobile, and controlled examples from the upstream picker introductions."
    >
      <Card title="Basic pickers" source="BasicDatePicker / BasicTimePicker / BasicDateTimePicker">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DatePicker label={"Date"->React.string} />
          <MuiXDatePickers.TimePicker label={"Time"->React.string} />
          <MuiXDatePickers.DateTimePicker label={"Date and time"->React.string} />
        </Mui.Stack>
      </Card>

      <Card title="Controlled value" source="ControlledComponent / DatePickerValue">
        <ControlledDatePicker />
      </Card>

      <Card title="Responsive variants" source="ResponsivePickers">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DesktopDatePicker label={"Desktop date"->React.string} />
          <MuiXDatePickers.MobileDatePicker label={"Mobile date"->React.string} />
          <MuiXDatePickers.DatePicker
            label={"Desktop from 900px"->React.string}
            desktopModeMediaQuery="@media (min-width: 900px)"
          />
        </Mui.Stack>
      </Card>

      <Card title="Form props" source="FormPropsDatePickers / FormPropsTimePickers">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DatePicker label={"Disabled"->React.string} disabled=true />
          <MuiXDatePickers.TimePicker
            label={"Read only"->React.string} readOnly=true defaultValue={value("2026-08-04T14:30")}
          />
          <MuiXDatePickers.DateTimePicker label={"Named field"->React.string} name="appointment" />
        </Mui.Stack>
      </Card>
    </Section>

    <Section title="Static pickers" description="Always-visible mobile and landscape variants.">
      <Card title="Static date" source="StaticDatePickerLandscape">
        <MuiXDatePickers.StaticDatePicker
          defaultValue={value("2026-08-04")} orientation=#landscape
        />
      </Card>
      <Card title="Static time" source="StaticTimePickerDemo">
        <MuiXDatePickers.StaticTimePicker
          defaultValue={value("2026-08-04T14:30")} displayStaticWrapperAs=#desktop
        />
      </Card>
      <Card title="Static date-time" source="StaticDateTimePickerLandscape">
        <MuiXDatePickers.StaticDateTimePicker
          defaultValue={value("2026-08-04T14:30")} orientation=#landscape
        />
      </Card>
    </Section>

    <Section
      title="Views and opening view"
      description="Restricted view sets, seconds, and explicit opening views."
    >
      <Card title="Date views" source="DatePickerViews / DatePickerOpenTo">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DatePicker
            label={"Year and month"->React.string}
            views={[MuiXDatePickers.Common.Year, MuiXDatePickers.Common.Month]}
            openTo={MuiXDatePickers.Common.Year}
          />
          <MuiXDatePickers.DatePicker
            label={"Month and day"->React.string}
            views={[MuiXDatePickers.Common.Month, MuiXDatePickers.Common.Day]}
            openTo={MuiXDatePickers.Common.Month}
          />
        </Mui.Stack>
      </Card>
      <Card title="Time views" source="TimePickerViews / SecondsTimePicker">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.TimePicker
            label={"Minutes first"->React.string}
            views={[MuiXDatePickers.Common.Hours, MuiXDatePickers.Common.Minutes]}
            openTo={MuiXDatePickers.Common.Minutes}
          />
          <MuiXDatePickers.TimePicker
            label={"With seconds"->React.string}
            views=[
              MuiXDatePickers.Common.Hours,
              MuiXDatePickers.Common.Minutes,
              MuiXDatePickers.Common.Seconds,
            ]
            format="HH:mm:ss"
          />
        </Mui.Stack>
      </Card>
      <Card title="Date-time views" source="DateTimePickerViews / DateTimePickerOpenTo">
        <MuiXDatePickers.DateTimePicker
          label={"Start at hours"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          openTo={MuiXDatePickers.Common.Hours}
          views=[
            MuiXDatePickers.Common.Year,
            MuiXDatePickers.Common.Day,
            MuiXDatePickers.Common.Hours,
            MuiXDatePickers.Common.Minutes,
          ]
        />
      </Card>
    </Section>
  </Mui.Stack>
