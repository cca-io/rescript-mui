# ReScript bindings for @mui/x-date-pickers

This library provides ReScript bindings for the date and time pickers of [MUI-X](https://mui.com/x/react-date-pickers/).

## Installation

1. Install all necessary packages according to the official MUI-X Date Pickers installation guide: https://mui.com/x/react-date-pickers/getting-started/.
2. Install both `@rescript-mui/material` and `@rescript-mui/x-date-pickers`

```sh
npm install @rescript-mui/material @rescript-mui/x-date-pickers
```

3. Add them to `dependencies` in your `rescript.json`:

```json
{
  "dependencies": ["@rescript-mui/material", "@rescript-mui/x-date-pickers"]
}
```

## Migration gotchas

### Install the date library separately

The adapter bindings do not bundle their underlying date library. Install the library that
matches your adapter—for example, `dayjs` for `AdapterDayjs` or `date-fns` for
`AdapterDateFns`—and pass the adapter to `LocalizationProvider`:

```rescript
<MuiXDatePickers.LocalizationProvider
  dateAdapter={MuiXDatePickers.AdapterDayjs.make}
>
  {children}
</MuiXDatePickers.LocalizationProvider>
```

### Avoid constructing `Common.dateValue` directly

Picker values are the date-library value or `null`. Use `DateValue` to avoid ambiguous
`Date` constructors in `Common` and to convert to standard nullable or option
representations:

```rescript
let value = dayjsValue->MuiXDatePickers.DateValue.fromDate
let maybeValue = value->MuiXDatePickers.DateValue.toOption

let label = switch maybeValue {
| Some(date) => formatDate(date)
| None => "No date selected"
}
```

`DateValue` also provides `fromNullable`, `toNullable`, `fromOption`, `toOption`,
`fromNull`, and `toNull`.

The picker `value`, `defaultValue`, and callback value use `DateValue.t<'date>`. Validation
boundaries such as `minDate`, `maxDate`, `minTime`, and `maxTime` take the non-null date-library
value.

### Use component-specific `slotProps`

MUI X moved customization props into named slots. These bindings provide typed slot
records for common customizations, including `calendarHeader`, `textField`, `actionBar`,
`field`, `toolbar`, and `openPickerButton`:

```rescript
<MuiXDatePickers.DateCalendar
  slotProps={calendarHeader: {format: "MM/YYYY"}}
/>

<MuiXDatePickers.DateTimePicker
  slotProps={
    textField: {
      helperText: "Choose a local date and time"->React.string,
    },
    actionBar: {
      actions: [#clear, #today, #cancel, #accept],
    },
  }
/>
```

Field behavior that belongs to the picker field is nested under `field`:

```rescript
<MuiXDatePickers.DesktopDatePicker
  slotProps={
    field: {
      clearable: true,
      openPickerButtonPosition: #start,
    },
  }
/>
```

The picker text field has its own slots. This replaces the old capitalization-sensitive
`InputProps` versus `inputProps` distinction:

- old `InputProps` → `slotProps.textField.slotProps.input`
- old `inputProps` → `slotProps.textField.slotProps.htmlInput`

```rescript
<MuiXDatePickers.DatePicker
  slotProps={
    textField: {
      slotProps: {
        input: {
          endAdornment: customAdornment,
        },
        htmlInput: {
          maxLength: 10,
          ariaLabel: "Date",
        },
      },
    },
  }
/>
```

When replacing a slot component, convert the React component to MUI's overridable component
representation:

```rescript
<MuiXDatePickers.DatePicker
  slots={
    openPickerIcon:
      Mui.OverridableComponent.componentWithUnknownProps(MyCalendarIcon.make),
  }
/>
```

### Validation errors are typed

Validation callbacks expose `DateValidationError.t`, `TimeValidationError.t`, or
`DateTimeValidationError.t` rather than `Nullable.t<string>`:

```rescript
let validationMessage = error =>
  switch error {
  | MuiXDatePickers.DateValidationError.None => ""
  | InvalidDate => "Enter a valid date"
  | MinDate => "The date is too early"
  | MaxDate => "The date is too late"
  | DisablePast => "Past dates are disabled"
  | DisableFuture => "Future dates are disabled"
  | ShouldDisableDate => "That date is unavailable"
  | ShouldDisableMonth => "That month is unavailable"
  | ShouldDisableYear => "That year is unavailable"
  }

<MuiXDatePickers.DatePicker
  onError={(error, _value) => setError(_ => validationMessage(error))}
/>
```

Use the error module matching the component family. Time validation additionally distinguishes
hour, minute, and second failures such as `ShouldDisableHours`; date-time validation contains
both the date and time cases.

### Callback arities follow current MUI X

The current callback signatures include context that older bindings may have omitted:

```rescript
<MuiXDatePickers.DateCalendar
  onChange={(value, selectionState, view) => {
    handleCalendarChange(value, selectionState, view)
  }}
/>

<MuiXDatePickers.DateTimePicker
  onChange={(value, context) => handleChange(value, context.validationError)}
  onAccept={(value, context) => handleAccept(value, context.validationError)}
/>
```

- `DateCalendar.onChange` receives `(value, selectionState, view)`.
- Picker `onChange` and `onAccept` receive `(value, context)`.
- Field `onChange` receives `(value, {validationError})`.

### `DateTimePicker` has no `classes` prop

This mirrors upstream MUI X: `DateTimePicker` accepts `className` and `sx`, but not `classes`.
Apply a generated root class with `className`:

```rescript
<MuiXDatePickers.DateTimePicker className=classes.root />
```

Components that expose upstream utility classes, such as `DateCalendar`, still have a typed
`classes` prop:

```rescript
<MuiXDatePickers.DateCalendar classes={root: classes.calendarRoot} />
```

### Date-library locales come from the application

The adapter is bound here, but locale values remain owned by the corresponding date library.
For date-fns, bind the named exports your application uses:

```rescript
module DateFnsLocale = {
  type t

  @module("date-fns/locale") external de: t = "de"
  @module("date-fns/locale") external enUS: t = "enUS"
  @module("date-fns/locale") external fr: t = "fr"
}

<MuiXDatePickers.LocalizationProvider
  dateAdapter={MuiXDatePickers.AdapterDateFns.make}
  adapterLocale={DateFnsLocale.de}
>
  {children}
</MuiXDatePickers.LocalizationProvider>
```

Day.js locales must be loaded by the application before passing the locale key:

```rescript
@module("dayjs/locale/de") external germanLocale: unknown = "default"

let _ = germanLocale

<MuiXDatePickers.LocalizationProvider
  dateAdapter={MuiXDatePickers.AdapterDayjs.make}
  adapterLocale="de"
>
  {children}
</MuiXDatePickers.LocalizationProvider>
```

### Community package scope

These bindings target `@mui/x-date-pickers`. Range pickers and other Pro-only APIs from
`@mui/x-date-pickers-pro` are not included. Headless MUI X hooks are also not currently part
of this package.

## Examples

The repository contains a gallery of 47 runnable Community examples covering picker families,
fields, calendars, clocks, validation, localization, lifecycle callbacks, and slot
customization. See the
[example gallery](../../examples/src/xDatePickerExamples/ExamplesXDatePickers.res) and its
[coverage notes](../../examples/src/xDatePickerExamples/README.md).

## Progress

### MUI-X Date Pickers

- [x] AdapterDateFns
- [x] AdapterDateFnsJalali
- [x] AdapterDayjs
- [x] AdapterLuxon
- [x] AdapterMoment
- [x] AdapterMomentHijri
- [x] AdapterMomentJalaali
- [x] DateCalendar
- [x] DateField
- [x] DatePicker
- [x] DateTimeField
- [x] DateTimePicker
- [x] DayCalendarSkeleton
- [x] DesktopDatePicker
- [x] DesktopDateTimePicker
- [x] DesktopTimePicker
- [x] DigitalClock
- [x] LocalizationProvider
- [x] MobileDatePicker
- [x] MobileDateTimePicker
- [x] MobileTimePicker
- [x] MonthCalendar
- [x] MultiSectionDigitalClock
- [x] PickersActionBar
- [x] PickersCalendarHeader
- [x] PickerDay
- [x] PickersLayout
- [x] Unstable_PickersSectionList
- [x] PickersShortcuts
- [x] PickersTextField
- [x] StaticDatePicker
- [x] StaticDateTimePicker
- [x] StaticTimePicker
- [x] TimeClock
- [x] TimeField
- [x] TimePicker
- [x] YearCalendar
