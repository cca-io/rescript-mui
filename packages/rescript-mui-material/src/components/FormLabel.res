type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if the color is secondary. */
  colorSecondary: string,
  /** State class applied to the root element if `focused={true}`. */
  focused: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled: string,
  /** State class applied to the root element if `error={true}`. */
  error: string,
  /** State class applied to the root element if `filled={true}`. */
  filled: string,
  /** State class applied to the root element if `required={true}`. */
  required: string,
  /** Styles applied to the asterisk element. */
  asterisk: string,
}

@unboxed
type color =
  | @as("error") Error
  | @as("info") Info
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type props = {
  ...CommonProps.t,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The color of the component.
   * It supports both default and custom theme colors, which can be added as shown in the
   * [palette customization guide](https://mui.com/material-ui/customization/palette/#adding-new-colors).
   */
  color?: color,
  /**
     * The component used for the root node. Either a string to use a HTML element or a component.
     */
  component?: OverridableComponent.t<unknown>,
  /**
   * If `true`, the label should be displayed in a disabled state.
   */
  disabled?: bool,
  /**
   * If `true`, the label is displayed in an error state.
   */
  error?: bool,
  /**
   * If `true`, the label should use filled classes key.
   */
  filled?: bool,
  /**
   * If `true`, the input of this label is focused (used by `FormGroup` components).
   */
  focused?: bool,
  /**
   * If `true`, the label will indicate that the `input` is required.
   */
  required?: bool,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: props => React.element = "FormLabel"
