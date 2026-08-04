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

## Translating JavaScript and TypeScript examples to ReScript

Most examples in the upstream MUI X documentation port directly. The main differences are how ReScript represents nullable picker values, string unions, component-valued slots, and JavaScript object literals.

A picker file normally uses several modules from this package, so the examples below assume it is opened once at the top of the file:

```rescript
open MuiXDatePickers
```

| JavaScript / TypeScript                       | ReScript                                              |
| --------------------------------------------- | ----------------------------------------------------- |
| A date-library value or `null`                | `DateValue.t<'date>` with nullable and option helpers |
| A validation-error string union or `null`     | A typed validation-error variant                      |
| An open `slots` or `slotProps` object         | A component-specific typed record                     |
| A React component assigned directly to a slot | An `OverridableComponent` conversion                  |
| A locale imported from the date library       | An application-owned ReScript external                |

### Pass the bound adapter module

The adapter bindings do not bundle their underlying date library. Install the library that matches your adapter—for example, `dayjs` for `AdapterDayjs` or `date-fns` for `AdapterDateFns`.

JavaScript and TypeScript pass the imported adapter class:

```tsx
<LocalizationProvider dateAdapter={AdapterDayjs}>
  {children}
</LocalizationProvider>
```

ReScript passes the binding's adapter module value:

```rescript
<LocalizationProvider
  dateAdapter={AdapterDayjs.make}
>
  {children}
</LocalizationProvider>
```

### Represent nullable picker values with `DateValue`

JavaScript and TypeScript APIs expose picker values as the date-library value or `null`. ReScript exposes the same runtime representation as `DateValue.t<'date>`. Use `DateValue` instead of constructing `Common.dateValue` directly; this avoids ambiguous `Date` constructors and converts cleanly to standard nullable or option representations:

```rescript
let value = dayjsValue->DateValue.fromDate
let maybeValue = value->DateValue.toOption

let label = switch maybeValue {
| Some(date) => formatDate(date)
| None => "No date selected"
}
```

`DateValue` also provides `fromNullable`, `toNullable`, `fromOption`, `toOption`, `fromNull`, and `toNull`.

The picker `value`, `defaultValue`, and callback value use `DateValue.t<'date>`. Validation boundaries such as `minDate`, `maxDate`, `minTime`, and `maxTime` take the non-null date-library value.

### Write `slots` and `slotProps` as typed records

MUI X exposes customization through named slots. These bindings provide typed slot records for common customizations, including `calendarHeader`, `textField`, `actionBar`, `field`, `toolbar`, and `openPickerButton`:

```rescript
<DateCalendar
  slotProps={calendarHeader: {format: "MM/YYYY"}}
/>

<DateTimePicker
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
<DesktopDatePicker
  slotProps={
    field: {
      clearable: true,
      openPickerButtonPosition: #start,
    },
  }
/>
```

The picker text field has its own nested slots. The two input layers map as follows:

- MUI input layer → `slotProps.textField.slotProps.input`
- native HTML input → `slotProps.textField.slotProps.htmlInput`

```rescript
<DatePicker
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

When replacing a slot component, convert the React component to MUI's overridable component representation:

```rescript
<DatePicker
  slots={
    openPickerIcon:
      Mui.OverridableComponent.componentWithUnknownProps(MyCalendarIcon.make),
  }
/>
```

### Pattern-match validation errors

JavaScript receives a string or `null`, while TypeScript describes those values with string unions. ReScript validation callbacks expose `DateValidationError.t`, `TimeValidationError.t`, or `DateTimeValidationError.t` so callers can exhaustively pattern-match them:

```rescript
let validationMessage = error =>
  switch error {
  | DateValidationError.NoError => ""
  | InvalidDate => "Enter a valid date"
  | MinDate => "The date is too early"
  | MaxDate => "The date is too late"
  | DisablePast => "Past dates are disabled"
  | DisableFuture => "Future dates are disabled"
  | ShouldDisableDate => "That date is unavailable"
  | ShouldDisableMonth => "That month is unavailable"
  | ShouldDisableYear => "That year is unavailable"
  }

<DatePicker
  onError={(error, _value) => setError(_ => validationMessage(error))}
/>
```

`NoError` is represented as JavaScript `null`; the other constructors are represented as MUI X's validation-error strings.

Use the error module matching the component family. Time validation additionally distinguishes hour, minute, and second failures such as `ShouldDisableHours`; date-time validation contains both the date and time cases.

### Accept the complete callback arguments

The bindings expose all callback arguments documented by MUI X. Use `_` for an argument you completely ignore, or prefix a descriptive name with `_` when the name still helps explain the callback:

```rescript
<DateCalendar
  onChange={(value, _selectionState, _view) => handleCalendarChange(value)}
/>

<DateTimePicker
  onChange={(value, context) => handleChange(value, context.validationError)}
  onAccept={(value, _) => handleAccept(value)}
/>
```

- `DateCalendar.onChange` receives `(value, selectionState, view)`.
- Picker `onChange` and `onAccept` receive `(value, context)`.
- Field `onChange` receives `(value, {validationError})`.

### Component props mirror upstream availability

This mirrors upstream MUI X: `DateTimePicker` accepts `className` and `sx`, but not `classes`. Apply a generated root class with `className`:

```rescript
<DateTimePicker className=classes.root />
```

Components that expose upstream utility classes, such as `DateCalendar`, still have a typed `classes` prop:

```rescript
<DateCalendar classes={root: classes.calendarRoot} />
```

### Bind date-library locales in the application

JavaScript and TypeScript applications import locale values from the corresponding date library. The ReScript adapter is bound here, while applications declare externals for the locale exports they use. For date-fns:

```rescript
module DateFnsLocale = {
  type t

  @module("date-fns/locale") external de: t = "de"
  @module("date-fns/locale") external enUS: t = "enUS"
  @module("date-fns/locale") external fr: t = "fr"
}

<LocalizationProvider
  dateAdapter={AdapterDateFns.make}
  adapterLocale={DateFnsLocale.de}
>
  {children}
</LocalizationProvider>
```

Day.js locales must be loaded by the application before passing the locale key:

```rescript
@module("dayjs/locale/de") external germanLocale: unknown = "default"

let _ = germanLocale

<LocalizationProvider
  dateAdapter={AdapterDayjs.make}
  adapterLocale="de"
>
  {children}
</LocalizationProvider>
```

### Community package scope

These bindings target `@mui/x-date-pickers`. Range pickers and other Pro-only APIs from `@mui/x-date-pickers-pro` are not included. Headless MUI X hooks are also not currently part of this package.

## Examples

The repository contains a gallery of 47 runnable Community examples covering picker families, fields, calendars, clocks, validation, localization, lifecycle callbacks, and slot customization. See the [example gallery](../../examples/src/xDatePickerExamples/ExamplesXDatePickers.res) and its [coverage notes](../../examples/src/xDatePickerExamples/README.md).

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
