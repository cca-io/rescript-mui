type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if `margin="normal"`. */
  marginNormal: string,
  /** Styles applied to the root element if `margin="dense"`. */
  marginDense: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth: string,
}

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type margin =
  | @as("dense") Dense
  | @as("normal") Normal
  | @as("none") None

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | String(string)

type variant =
  | @as("standard") Standard
  | @as("outlined") Outlined
  | @as("filled") Filled

type publicProps = {
  ...CommonProps.t_NoId,
  /**
     * The component used for the root node. Either a string to use a HTML element or a component.
     */
  component?: OverridableComponent.t<unknown>,
  /**
     * If `true`, the component is displayed in focused state.
     */
  focused?: bool,
  /**
     * If `true`, the label is hidden.
     * This is used to increase density for a `FilledInput`.
     * Be sure to add `aria-label` to the `input` element.
     * @default false
     */
  hiddenLabel?: bool,
  /**
     * If `dense` or `normal`, will adjust vertical spacing of this and contained components.
     * @default 'none'
     */
  margin?: margin,
}

type props = {
  ...publicProps,
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
     * @default 'primary'
     */
  color?: color,
  /**
     * If `true`, the label, input and helper text should be displayed in a disabled state.
     * @default false
     */
  disabled?: bool,
  /**
     * If `true`, the label is displayed in an error state.
     * @default false
     */
  error?: bool,
  /**
     * If `true`, the component will take up the full width of its container.
     * @default false
     */
  fullWidth?: bool,
  /**
     * If `true`, the label will indicate that the `input` is required.
     * @default false
     */
  required?: bool,
  /**
     * The size of the component.
     * @default 'medium'
     */
  size?: size,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  /**
     * The variant to use.
     * @default 'outlined'
     */
  variant?: variant,
}

@module("@mui/material")
external make: props => React.element = "FormControl"
