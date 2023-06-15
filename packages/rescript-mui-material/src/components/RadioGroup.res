type props<'value> = {
  ...FormGroup.props,
  /**
   * The default value. Use when the component is not controlled.
   */
  defaultValue?: 'value,
  /**
   * The name used to reference the value of the control.
   * If you don't provide this prop, it falls back to a randomly generated name.
   */
  name?: string,
  /**
   * Callback fired when a radio button is selected.
   *
   * @param {React.ChangeEvent<HTMLInputElement>} event The event source of the callback.
   * @param {string} value The value of the selected radio button.
   * You can pull out the new value by accessing `event.target.value` (string).
   */
  onChange?: (ReactEvent.Form.t, string) => unit,
  /**
   * Value of the selected radio button. The DOM API casts this to a string.
   */
  value?: 'value,
}

@module("@mui/material")
external make: React.component<props<'value>> = "RadioGroup"
