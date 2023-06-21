type props<'value> = {
  ...Mui.Tabs.publicProps,
  /**
    * A list of `<Tab />` elements.
    */
  children: React.element,
  /**
    * Callback fired when the value changes.
    *
    * @param {React.SyntheticEvent} event The event source of the callback. **Warning**: This is a generic event not a change event.
    * @param {any} value We default to the index of the child (number)
    */
  onChange?: (ReactEvent.Synthetic.t, 'value) => unit,
  /**
    * The value of the currently selected `Tab`.
    * If you don't want any selected `Tab`, you can set this prop to `false`.
    */
  value?: 'value,
}

@module("@mui/lab/TabList")
external make: React.component<props<'value>> = "default"
