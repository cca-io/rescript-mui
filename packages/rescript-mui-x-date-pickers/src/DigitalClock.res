type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the list (`ul`) element. */
  list?: string,
  /** Styles applied to the list item (`li`) element. */
  item?: string,
}

type props<'date> = {
  ...Mui.CommonProps.t,
  /** Override or extend the styles applied to the component. */
  classes?: classes,
  /** The selected value. Used when the component is controlled. */
  value?: Common.dateValue<'date>,
  /** The default value. Used when the component is not controlled. */
  defaultValue?: Common.dateValue<'date>,
  /** The date used to generate the new value when both `value` and `defaultValue` are empty. */
  referenceDate?: 'date,
  /** Callback fired when the value changes. */
  onChange?: (Common.dateValue<'date>, option<Common.pickerSelectionState>) => unit,
  /** 12h/24h view. @default adapter-based */
  ampm?: bool,
  /** The time step in minutes between two consecutive values. @default 30 */
  timeStep?: int,
  /** If `true`, disabled digital clock items will not be rendered. @default false */
  skipDisabled?: bool,
  /** Minimal selectable time. */
  minTime?: 'date,
  /** Maximal selectable time. */
  maxTime?: 'date,
  /** Do not ignore the date part when validating min/max time. @default false */
  disableIgnoringDatePartForTimeValidation?: bool,
  /** Disable specific time. */
  shouldDisableTime?: ('date, Common.timeView) => bool,
  /** If `true`, disable values after the current time. @default false */
  disableFuture?: bool,
  /** If `true`, disable values before the current time. @default false */
  disablePast?: bool,
  /** If `true`, the component is disabled. @default false */
  disabled?: bool,
  /** If `true`, the component is read-only. @default false */
  readOnly?: bool,
  /** Available views. */
  views?: array<Common.timeView>,
  /** Choose which timezone to use for the value. */
  timezone?: Common.pickersTimezone,
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "DigitalClock"
