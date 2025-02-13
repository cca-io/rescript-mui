type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if the component is a descendant of `FormControl`. */
  formControl?: string,
  /** Styles applied to the root element if the component is focused. */
  focused?: string,
  /** Styles applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if color secondary. */
  colorSecondary?: string,
  /** Styles applied to the root element unless `disableUnderline={true}`. */
  underline?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
  /** Styles applied to the input element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `multiline={true}`. */
  multiline?: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth?: string,
  /** Styles applied to the input element. */
  input?: string,
  /** Styles applied to the input element if `size="small"`. */
  inputSizeSmall?: string,
  /** Styles applied to the input element if `multiline={true}`. */
  inputMultiline?: string,
  /** Styles applied to the input element if `startAdornment` is provided. */
  inputAdornedStart?: string,
  /** Styles applied to the input element if `endAdornment` is provided. */
  inputAdornedEnd?: string,
  /** Styles applied to the input element if `type="search"`. */
  inputTypeSearch?: string,
}

type props<'value> = {
  ...InputBase.publicProps<'value>,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Callback fired when the value is changed.
    *
    * @param {React.ChangeEvent<HTMLTextAreaElement | HTMLInputElement>} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (string).
    */
  onChange?: ReactEvent.Form.t => unit,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/Input")
external make: React.component<props<'value>> = "default"
