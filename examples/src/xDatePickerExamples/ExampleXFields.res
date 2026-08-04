open XDatePickerExampleSupport

module ControlledFields = {
  @react.component
  let make = () => {
    let (dateValue, setDateValue) = React.useState(() => value("2026-08-04"))
    let (timeValue, setTimeValue) = React.useState(() => value("2026-08-04T14:30"))

    <Mui.Stack spacing={Number(2.)}>
      <MuiXDatePickers.DateField
        label={"Controlled date"->React.string}
        value=dateValue
        onChange={(nextValue, _) => setDateValue(_ => nextValue)}
      />
      <MuiXDatePickers.TimeField
        label={"Controlled time"->React.string}
        value=timeValue
        onChange={(nextValue, _) => setTimeValue(_ => nextValue)}
      />
      <Mui.Typography variant=Caption color=TextSecondary>
        {("Date: " ++ formatValue(dateValue) ++ " · Time: " ++ formatValue(timeValue))
          ->React.string}
      </Mui.Typography>
    </Mui.Stack>
  }
}

@react.component
let make = () =>
  <Section
    title="Fields"
    description="Basic, controlled, formatted, clearable, and section-aware field examples."
  >
    <Card title="Basic fields" source="BasicDateField / BasicTimeField / BasicDateTimeField">
      <Mui.Stack spacing={Number(2.)}>
        <MuiXDatePickers.DateField label={"Date field"->React.string} />
        <MuiXDatePickers.TimeField label={"Time field"->React.string} />
        <MuiXDatePickers.DateTimeField label={"Date-time field"->React.string} />
      </Mui.Stack>
    </Card>

    <Card title="Controlled fields" source="DateFieldValue / TimeFieldValue">
      <ControlledFields />
    </Card>

    <Card
      title="Custom formats" source="CustomDateFormat / CustomTimeFormat / CustomDateTimeFormat"
    >
      <Mui.Stack spacing={Number(2.)}>
        <MuiXDatePickers.DateField
          label={"Month, day, year"->React.string}
          defaultValue={value("2026-08-04")}
          format="MM-DD-YYYY"
        />
        <MuiXDatePickers.TimeField
          label={"Time with seconds"->React.string}
          defaultValue={value("2026-08-04T14:30:45")}
          format="HH:mm:ss"
        />
        <MuiXDatePickers.DateTimeField
          label={"Compact date-time"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          format="YYYY/MM/DD HH:mm"
        />
      </Mui.Stack>
    </Card>

    <Card title="Field behavior" source="ClearableBehavior / RespectLeadingZerosFieldFormat">
      <Mui.Stack spacing={Number(2.)}>
        <MuiXDatePickers.DateField
          label={"Clearable"->React.string} defaultValue={value("2026-08-04")} clearable=true
        />
        <MuiXDatePickers.DateField
          label={"Leading zeros"->React.string}
          defaultValue={value("2026-08-04")}
          format="M/D/YYYY"
          shouldRespectLeadingZeros=true
        />
        <MuiXDatePickers.DateTimeField
          label={"Select the day section"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          selectedSections={MuiXDatePickers.Common.Day}
        />
      </Mui.Stack>
    </Card>
  </Section>
