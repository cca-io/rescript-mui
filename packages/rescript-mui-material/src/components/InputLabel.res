type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `focused={true}`. */
  focused?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** State class applied to the root element if `error={true}`. */
  error?: string,
  /** State class applied to the root element if `required={true}`. */
  required?: string,
  /** State class applied to the asterisk element. */
  asterisk?: string,
  /** Styles applied to the root element if the component is a descendant of `FormControl`. */
  formControl?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the input element if `shrink={true}`. */
  shrink?: string,
  /** Styles applied to the input element unless `disableAnimation={true}`. */
  animated?: string,
  /** Styles applied to the root element if `variant="filled"`. */
  filled?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="standard"`. */
  standard?: string,
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

type margin = | @as("dense") Dense

@unboxed
type size =
  | @as("small") Small
  | @as("normal") Normal
  | String(string)

type variant =
  | @as("standard") Standard
  | @as("outlined") Outlined
  | @as("filled") Filled

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
  color?: color,
  /**
     * If `true`, the transition animation is disabled.
     * @default false
     */
  disableAnimation?: bool,
  /**
     * If `true`, the component is disabled.
     */
  disabled?: bool,
  /**
     * If `true`, the label is displayed in an error state.
     */
  error?: bool,
  /**
     * If `true`, the `input` of this label is focused.
     */
  focused?: bool,
  /**
     * If `dense`, will adjust vertical spacing. This is normally obtained via context from
     * FormControl.
     */
  margin?: margin,
  /**
     * if `true`, the label will indicate that the `input` is required.
     */
  required?: bool,
  /**
     * If `true`, the label is shrunk.
     */
  shrink?: bool,
  /**
     * The size of the component.
     * @default 'normal'
     */
  size?: size,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
  /**
     * The variant to use.
     */
  variant?: variant,
  // Native HTML element props
  htmlFor?: string,
}

@module("@mui/material")
external make: React.component<props> = "InputLabel"
