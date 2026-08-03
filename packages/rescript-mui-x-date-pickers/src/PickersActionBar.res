type action = [#clear | #cancel | #accept | #today | #next | #nextOrAccept]

type props = {
  ...Mui.DialogActions.props,
  /** Ordered array of actions to display. */
  actions?: array<action>,
}

@module("@mui/x-date-pickers")
external make: React.component<props> = "PickersActionBar"
