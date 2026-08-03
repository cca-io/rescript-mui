type changeImportance = [#accept | #set]

type getValueParams<'date> = {
  isValid: Common.dateValue<'date> => bool,
}

type shortcutItem<'date> = {
  label: string,
  getValue: getValueParams<'date> => Common.dateValue<'date>,
  id?: string,
}

type props<'date> = {
  ...Mui.List.props,
  /** Ordered array of shortcuts to display. */
  items?: array<shortcutItem<'date>>,
  /** Importance of the change when picking a shortcut. @default "accept" */
  changeImportance?: changeImportance,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "PickersShortcuts"
