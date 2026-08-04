open XDatePickerExampleSupport

@module("dayjs/locale/de") external germanLocale: unknown = "default"

module EventIcon = {
  @react.component @module("@mui/icons-material/Event")
  external make: unit => React.element = "default"
}

module Lifecycle = {
  @react.component
  let make = () => {
    let (changes, setChanges) = React.useState(() => 0)
    let (accepts, setAccepts) = React.useState(() => 0)
    let (lastValue, setLastValue) = React.useState(() => "Empty")

    <Mui.Stack spacing={Number(1.)}>
      <MuiXDatePickers.DatePicker
        label={"Lifecycle"->React.string}
        defaultValue={value("2026-08-04")}
        onChange={(nextValue, _) => {
          setChanges(count => count + 1)
          setLastValue(_ => formatValue(nextValue))
        }}
        onAccept={(nextValue, _) => {
          setAccepts(count => count + 1)
          setLastValue(_ => formatValue(nextValue))
        }}
      />
      <Mui.Typography variant=Caption color=TextSecondary>
        {`Changes: ${changes->Int.toString} · Accepts: ${accepts->Int.toString} · ${lastValue}`->React.string}
      </Mui.Typography>
    </Mui.Stack>
  }
}

@react.component
let make = () => {
  let _ = germanLocale

  <Mui.Stack spacing={Number(4.)}>
    <Section
      title="Slots and field customization"
      description="Typed slot records for helper text, actions, headers, toolbars, icons, and field behavior."
    >
      <Card title="Text field slot props" source="TextFieldSlotProps / HelperText">
        <Mui.Stack spacing={Number(2.)}>
          <MuiXDatePickers.DatePicker
            label={"Small field"->React.string} slotProps={textField: {size: Small}}
          />
          <MuiXDatePickers.DatePicker
            label={"Helper text"->React.string}
            slotProps={textField: {helperText: "MM/DD/YYYY"->React.string}}
          />
          <MuiXDatePickers.DatePicker
            label={"Filled field"->React.string} slotProps={textField: {variant: #filled}}
          />
          <MuiXDatePickers.DatePicker
            label={"Nested input slots"->React.string}
            slotProps={
              textField: {
                slotProps: {
                  input: {endAdornment: "optional"->React.string},
                  htmlInput: {maxLength: 10, ariaLabel: "Date"},
                },
              },
            }
          />
        </Mui.Stack>
      </Card>

      <Card title="Action bar" source="ActionBarComponentProps">
        <MuiXDatePickers.StaticDateTimePicker
          defaultValue={value("2026-08-04T14:30")}
          slotProps={actionBar: {actions: [#clear, #today, #cancel, #accept]}}
        />
      </Card>

      <Card title="Calendar header format" source="CustomCalendarHeaderFormat">
        <MuiXDatePickers.DateCalendar
          defaultValue={value("2026-08-04")} slotProps={calendarHeader: {format: "MM/YYYY"}}
        />
      </Card>

      <Card title="Toolbar format" source="CustomToolbarFormat">
        <MuiXDatePickers.StaticDatePicker
          displayStaticWrapperAs=#desktop
          defaultValue={value("2026-08-04")}
          slotProps={toolbar: {toolbarFormat: "ddd DD MMMM", hidden: false}}
        />
      </Card>

      <Card title="Clear and opening button" source="ClearableProp / StartEdgeOpeningButton">
        <MuiXDatePickers.DesktopDatePicker
          label={"Clearable, start icon"->React.string}
          defaultValue={value("2026-08-04")}
          slotProps={
            field: {clearable: true, openPickerButtonPosition: #start},
            openPickerButton: {color: Secondary, size: Small},
          }
        />
      </Card>

      <Card title="Custom opening icon" source="CustomSlots / CustomOpeningIcon">
        <MuiXDatePickers.DatePicker
          label={"Event icon"->React.string}
          slots={
            openPickerIcon: Mui.OverridableComponent.componentWithUnknownProps(EventIcon.make),
          }
        />
      </Card>

      <Card title="Spacious format" source="FieldFormatDensity">
        <MuiXDatePickers.DateTimePicker
          label={"Spacious sections"->React.string}
          defaultValue={value("2026-08-04T14:30")}
          formatDensity=#spacious
        />
      </Card>
    </Section>

    <Section
      title="Localization and lifecycle"
      description="Adapter locale, translated labels, and current callback signatures."
    >
      <Card title="German Day.js locale" source="LocalizationDayjs">
        <MuiXDatePickers.LocalizationProvider
          dateAdapter={MuiXDatePickers.AdapterDayjs.make} adapterLocale="de"
        >
          <Mui.Stack spacing={Number(2.)}>
            <MuiXDatePickers.DateField
              label={"Datum"->React.string} defaultValue={value("2026-08-04")}
            />
            <MuiXDatePickers.TimeField
              label={"Uhrzeit"->React.string} defaultValue={value("2026-08-04T14:30")}
            />
          </Mui.Stack>
        </MuiXDatePickers.LocalizationProvider>
      </Card>

      <Card title="Localized picker labels" source="UseLocaleText">
        <MuiXDatePickers.LocalizationProvider
          dateAdapter={MuiXDatePickers.AdapterDayjs.make}
          localeText={
            cancelButtonLabel: "Abbrechen",
            clearButtonLabel: "Löschen",
            okButtonLabel: "Übernehmen",
            todayButtonLabel: "Heute",
          }
        >
          <MuiXDatePickers.StaticDatePicker
            defaultValue={value("2026-08-04")}
            slotProps={actionBar: {actions: [#clear, #today, #cancel, #accept]}}
          />
        </MuiXDatePickers.LocalizationProvider>
      </Card>

      <Card title="Change and accept lifecycle" source="Lifecycle examples">
        <Lifecycle />
      </Card>
    </Section>
  </Mui.Stack>
}
