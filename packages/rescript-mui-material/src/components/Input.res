type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if the component is a descendant of `FormControl`. */
  formControl: string,
  /** Styles applied to the root element if the component is focused. */
  focused: string,
  /** Styles applied to the root element if `disabled={true}`. */
  disabled: string,
  /** Styles applied to the root element if color secondary. */
  colorSecondary: string,
  /** Styles applied to the root element unless `disableUnderline={true}`. */
  underline: string,
  /** State class applied to the root element if `error={true}`. */
  error: string,
  /** Styles applied to the input element if `size="small"`. */
  sizeSmall: string,
  /** Styles applied to the root element if `multiline={true}`. */
  multiline: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth: string,
  /** Styles applied to the input element. */
  input: string,
  /** Styles applied to the input element if `size="small"`. */
  inputSizeSmall: string,
  /** Styles applied to the input element if `multiline={true}`. */
  inputMultiline: string,
  /** Styles applied to the input element if `startAdornment` is provided. */
  inputAdornedStart: string,
  /** Styles applied to the input element if `endAdornment` is provided. */
  inputAdornedEnd: string,
  /** Styles applied to the input element if `type="search"`. */
  inputTypeSearch: string,
}

type props<'a> = {
  ...InputBase.publicProps,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The default value. Use when the component is not controlled.
   */
  defaultValue?: 'a,
  /**
   * If `true`, the `input` will not have an underline.
   */
  disableUnderline?: bool,
  /**
   * Pass a ref to the `input` element.
   */
  inputRef?: React.ref<'a>,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * The value of the `input` element, required for a controlled component.
   */
  value?: 'a,
}

@module("@mui/material")
external make: props<'a> => React.element = "Input"
