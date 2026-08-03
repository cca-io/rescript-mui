type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="text"`. */
  text?: string,
  /** Styles applied to the root element if `variant="outlined"`. */
  outlined?: string,
  /** Styles applied to the root element if `variant="contained"`. */
  contained?: string,
  /** Styles applied to the root element if `disableElevation={true}`. */
  disableElevation?: string,
  /** State class applied to the ButtonBase root element if the button is keyboard focused. */
  focusVisible?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `color="inherit"`. */
  colorInherit?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** Styles applied to the root element if `size="large"`. */
  sizeLarge?: string,
  /** Styles applied to the root element if `fullWidth={true}`. */
  fullWidth?: string,
  /** Styles applied to the icon element if supplied. */
  icon?: string,
  /** Styles applied to the startIcon element if supplied. */
  startIcon?: string,
  /** Styles applied to the endIcon element if supplied. */
  endIcon?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `color="success"`. */
  colorSuccess?: string,
  /** Styles applied to the root element if `color="error"`. */
  colorError?: string,
  /** Styles applied to the root element if `color="info"`. */
  colorInfo?: string,
  /** Styles applied to the root element if `color="warning"`. */
  colorWarning?: string,
  /** Styles applied to the root element if `loading={true}`. */
  loading?: string,
  /** Styles applied to the loadingWrapper element. */
  loadingWrapper?: string,
  /** Styles applied to the loadingIconPlaceholder element. */
  loadingIconPlaceholder?: string,
  /** Styles applied to the loadingIndicator element. */
  loadingIndicator?: string,
  /** Styles applied to the root element if `loadingPosition="center"`. */
  loadingPositionCenter?: string,
  /** Styles applied to the root element if `loadingPosition="start"`. */
  loadingPositionStart?: string,
  /** Styles applied to the root element if `loadingPosition="end"`. */
  loadingPositionEnd?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("success") Success
  | @as("error") Error
  | @as("info") Info
  | @as("warning") Warning
  | String(string)

@unboxed
type loading =
  | @as(true) True
  | @as(false) False
  | @as(null) Null

@unboxed
type loadingPosition =
  | @as("start") Start
  | @as("end") End
  | @as("center") Center
  | String(string)

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
  | String(string)

@unboxed
type variant =
  | @as("contained") Contained
  | @as("outlined") Outlined
  | @as("text") Text
  | String(string)

type props = {
  ...ButtonBase.publicPropsWithOnClick,
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
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, no elevation is used.
    * @default false
    */
  disableElevation?: bool,
  /**
    * If `true`, the keyboard focus ripple is disabled.
    * @default false
    */
  disableFocusRipple?: bool,
  /**
    * Element placed after the children.
    */
  endIcon?: React.element,
  /**
    * If `true`, the button will take up the full width of its container.
    * @default false
    */
  fullWidth?: bool,
  /**
    * If `true`, the loading indicator is shown and the button is disabled.
    * If `true | false`, the loading wrapper is always rendered before the children to prevent Google Translation Crash.
    * @default null
    */
  loading?: loading,
  /**
    * Element placed before the children if the button is in loading state.
    * The node should contain an element with `role="progressbar"` with an accessible name.
    * By default we render a `CircularProgress` that is labelled by the button itself.
    * @default <CircularProgress color="inherit" size={16} />
    */
  loadingIndicator?: React.element,
  /**
    * The loading indicator can be positioned on the start, end, or the center of the button.
    * @default 'center'
    */
  loadingPosition?: loadingPosition,
  /**
    * The size of the component.
    * `small` is equivalent to the dense button styling.
    * @default 'medium'
    */
  size?: size,
  /**
    * Element placed before the children.
    */
  startIcon?: React.element,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use.
    * @default 'text'
    */
  variant?: variant,
}

@module("@mui/material/Button")
external make: React.component<props> = "default"
