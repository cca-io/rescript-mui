type changeImportance = [#accept | #set]

type shortcutItem<'date> = {
  label: string,
  getValue: {.} => Common.dateValue<'date>,
}

type props<'date> = {
  ...Mui.CommonProps.t,
  /** Ordered array of shortcuts to display. */
  items?: array<shortcutItem<'date>>,
  /** Importance of the change when picking a shortcut. @default "accept" */
  changeImportance?: changeImportance,
  /** If `true`, the layout is in landscape orientation. */
  isLandscape?: bool,
  /** The system prop for defining system overrides and additional CSS styles. */
  sx?: Mui.Sx.props,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "PickersShortcuts"
