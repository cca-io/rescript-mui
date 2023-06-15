type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `variant="filled"` or `variant="outlined"`. */
  contained?: string,
  /** State class applied to the root element if `focused={true}`. */
  focused?: string,
  /** State class applied to the root element if `filled={true}`. */
  filled?: string,
  /** State class applied to the root element if `required={true}`. */
  required?: string,
}

type margin = | @as("dense") Dense

@unboxed
type variant =
  | @as("standard") Standard
  | @as("outlined") Outlined
  | @as("filled") Filled
  | String(string)

type props = {
  ...CommonProps.t,
  /**
     * The content of the component.
     *
     * If `' '` is provided, the component reserves one line height for displaying a future message.
     */
  children?: React.element,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
     * The component used for the root node. Either a string to use a HTML element or a component.
     */
  component?: OverridableComponent.t<unknown>,
  /**
     * If `true`, the helper text should be displayed in a disabled state.
     */
  disabled?: bool,
  /**
     * If `true`, helper text should be displayed in an error state.
     */
  error?: bool,
  /**
     * If `true`, the helper text should use filled classes key.
     */
  filled?: bool,
  /**
     * If `true`, the helper text should use focused classes key.
     */
  focused?: bool,
  /**
     * If `dense`, will adjust vertical spacing. This is normally obtained via context from
     * FormControl.
     */
  margin?: margin,
  /**
     * If `true`, the helper text should use required classes key.
     */
  required?: bool,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  /**
     * The variant to use.
     */
  variant?: variant,
}

@module("@mui/material")
external make: React.component<props> = "FormHelperText"
