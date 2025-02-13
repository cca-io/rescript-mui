type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if color secondary. */
  colorSecondary?: string,
  /** Styles applied to the root element unless `disableUnderline={true}`. */
  underline?: string,
  /** State class applied to the root element if the component is focused. */
  focused?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `startAdornment` is provided. */
  adornedStart?: string,
  /** Styles applied to the root element if `endAdornment` is provided. */
  adornedEnd?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
  /** Styles applied to the input element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `multiline={true}`. */
  multiline?: string,
  /** Styles applied to the root element if `hiddenLabel={true}`. */
  hiddenLabel?: string,
  /** Styles applied to the input element. */
  input?: string,
  /** Styles applied to the input element if `size="small"`. */
  inputSizeSmall?: string,
  /** Styles applied to the `input` if in `<FormControl hiddenLabel />`. */
  inputHiddenLabel?: string,
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
    * If `true`, the label is hidden.
    * This is used to increase density for a `FilledInput`.
    * Be sure to add `aria-label` to the `input` element.
    * @default false
    */
  hiddenLabel?: bool,
  /**
    * Callback fired when the value is changed.
    *
    * @param {React.ChangeEvent<HTMLTextAreaElement | HTMLInputElement>} event The event source of the callback.
    * You can pull out the new value by accessing `event.target.value` (string).
    */
  onChange?: ReactEvent.Synthetic.t => unit,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/FilledInput")
external make: React.component<props<'value>> = "default"
