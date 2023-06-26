type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `position="fixed"`. */
  positionFixed?: string,
  /** Styles applied to the root element if `position="absolute"`. */
  positionAbsolute?: string,
  /** Styles applied to the root element if `position="sticky"`. */
  positionSticky?: string,
  /** Styles applied to the root element if `position="static"`. */
  positionStatic?: string,
  /** Styles applied to the root element if `position="relative"`. */
  positionRelative?: string,
  /** Styles applied to the root element if `color="default"`. */
  colorDefault?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `color="inherit"`. */
  colorInherit?: string,
  /** Styles applied to the root element if `color="transparent"`. */
  colorTransparent?: string,
}

@unboxed
type color =
  | @as("default") Default
  | @as("inherit") Inherit
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("transparent") Transparent
  | String(string)

type position =
  | @as("absolute") Absolute
  | @as("fixed") Fixed
  | @as("relative") Relative
  | @as("static") Static
  | @as("sticky") Sticky

type props = {
  ...Paper.publicProps,
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
    * If true, the `color` prop is applied in dark mode.
    * @default false
    */
  enableColorOnDark?: bool,
  /**
    * The positioning type. The behavior of the different options is described
    * [in the MDN web docs](https://developer.mozilla.org/en-US/docs/Learn/CSS/CSS_layout/Positioning).
    * Note: `sticky` is not universally supported and will fall back to `static` when unavailable.
    * @default 'fixed'
    */
  position?: position,
}

@module("@mui/material/AppBar")
external make: React.component<props> = "default"
