type action = [#clear | #cancel | #accept | #today | #next | #previous]

type props = {
  ...Mui.CommonProps.t,
  /** Ordered array of actions to display. @default `['cancel', 'accept']` for mobile and `[]` for desktop */
  actions?: array<action>,
  /** Callback fired when the "accept" action is triggered. */
  onAccept?: unit => unit,
  /** Callback fired when the "cancel" action is triggered. */
  onCancel?: unit => unit,
  /** Callback fired when the "clear" action is triggered. */
  onClear?: unit => unit,
  /** Callback fired when the "today" action is triggered. */
  onSetToday?: unit => unit,
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props> = "PickersActionBar"
