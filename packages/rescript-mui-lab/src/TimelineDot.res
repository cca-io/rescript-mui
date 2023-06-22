type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="filled"`. */
  filled?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `color="grey"` and `variant="filled"`. */
  filledGrey?: string,
  /** Styles applied to the root element if `color="grey"` and `variant="outlined"`. */
  outlinedGrey?: string,
  /** Styles applied to the root element if `color="primary"` and `variant="filled"`. */
  filledPrimary?: string,
  /** Styles applied to the root element if `color="primary"` and `variant="outlined"`. */
  outlinedPrimary?: string,
  /** Styles applied to the root element if `color="secondary"` and `variant="filled"`. */
  filledSecondary?: string,
  /** Styles applied to the root element if `color="secondary"` and `variant="outlined"`. */
  outlinedSecondary?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("grey") Grey
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

@unboxed
type variant =
  | @as("filled") Filled
  | @as("outlined") Outlined
  | String(string)

type props = {
  ...Mui.CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The dot can have a different colors.
    * @default 'grey'
    */
  color?: color,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
  /**
    * The dot can appear filled or outlined.
    * @default 'filled'
    */
  variant?: variant,
}

@module("@mui/lab/TimelineDot")
external make: React.component<props> = "default"
