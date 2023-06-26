type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the root element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the root element if `color="action"`. */
  colorAction?: string,
  /** Styles applied to the root element if `color="error"`. */
  colorError?: string,
  /** Styles applied to the root element if `color="disabled"`. */
  colorDisabled?: string,
  /** Styles applied to the root element if `fontSize="inherit"`. */
  fontSizeInherit?: string,
  /** Styles applied to the root element if `fontSize="small"`. */
  fontSizeSmall?: string,
  /** Styles applied to the root element if `fontSize="medium"`. */
  fontSizeMedium?: string,
  /** Styles applied to the root element if `fontSize="large"`. */
  fontSizeLarge?: string,
}

@unboxed
type color =
  | @as("inherit") Inherit
  | @as("action") Action
  | @as("disabled") Disabled
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning

@unboxed
type fontSize =
  | @as("inherit") Inherit
  | @as("large") Large
  | @as("medium") Medium
  | @as("small") Small
  | String(string)

type props = {
  ...CommonProps.t,
  /**
    * Node passed into the SVG element.
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
    * You can use the `htmlColor` prop to apply a color attribute to the SVG element.
    * @default 'inherit'
    */
  color?: color,
  /**
    * The fontSize applied to the icon. Defaults to 24px, but can be configure to inherit font size.
    * @default 'medium'
    */
  fontSize?: fontSize,
  /**
    * Applies a color attribute to the SVG element.
    */
  htmlColor?: string,
  /**
    * If `true`, the root node will inherit the custom `component`'s viewBox and the `viewBox`
    * prop will be ignored.
    * Useful when you want to reference a custom `component` and have `SvgIcon` pass that
    * `component`'s viewBox to the root node.
    * @default false
    */
  inheritViewBox?: bool,
  /**
    * The shape-rendering attribute. The behavior of the different options is described on the
    * [MDN Web Docs](https://developer.mozilla.org/en-US/docs/Web/SVG/Attribute/shape-rendering).
    * If you are having issues with blurry icons you should investigate this prop.
    */
  shapeRendering?: string,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * Provides a human-readable title for the element that contains it.
    * https://www.w3.org/TR/SVG-access/#Equivalent
    */
  titleAccess?: string,
  /**
    * Allows you to redefine what the coordinates without units mean inside an SVG element.
    * For example, if the SVG element is 500 (width) by 200 (height),
    * and you pass viewBox="0 0 50 20",
    * this means that the coordinates inside the SVG will go from the top left corner (0,0)
    * to bottom right (50,20) and each unit will be worth 10px.
    * @default '0 0 24 24'
    */
  viewBox?: string,
}

@module("@mui/material/SvgIcon")
external make: React.component<props> = "default"
