type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `edge="start"`. */
  edgeStart?: string,
  /** Styles applied to the root element if `edge="end"`. */
  edgeEnd?: string,
  /** Styles applied to the root element if `color="inherit"`. */
  colorInherit?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `color="error"`. */
  colorError?: string,
  /** Styles applied to the root element if `color="info"`. */
  colorInfo?: string,
  /** Styles applied to the root element if `color="success"`. */
  colorSuccess?: string,
  /** Styles applied to the root element if `color="warning"`. */
  colorWarning?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `size="small"`. */
  sizeSmall?: string,
  /** Styles applied to the root element if `size="medium"`. */
  sizeMedium?: string,
  /** Styles applied to the root element if `size="large"`. */
  sizeLarge?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("default") Default
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

@unboxed
type edge =
  | @as("start") Start
  | @as("end") End
  | @as(false) False

@unboxed
type size =
  | @as("small") Small
  | @as("medium") Medium
  | @as("large") Large
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
    * @default 'default'
    */
  color?: color,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, the keyboard focus ripple is disabled.
    * @default false
    */
  disableFocusRipple?: bool,
  /**
    * If given, uses a negative margin to counteract the padding on one
    * side (this is often helpful for aligning the left or right
    * side of the icon with content above or below, without ruining the border
    * size and shape).
    * @default false
    */
  edge?: edge,
  /**
    * The size of the component.
    * `small` is equivalent to the dense button styling.
    * @default 'medium'
    */
  size?: size,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/IconButton")
external make: React.component<props> = "default"
