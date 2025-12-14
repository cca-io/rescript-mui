type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the badge `span` element. */
  badge?: string,
  /** Styles applied to the badge `span` element if `variant="dot"`. */
  dot?: string,
  /** Styles applied to the badge `span` element if `variant="standard"`. */
  standard?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'top', 'right' }}`. */
  anchorOriginTopRight?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'bottom', 'right' }}`. */
  anchorOriginBottomRight?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'top', 'left' }}`. */
  anchorOriginTopLeft?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'bottom', 'left' }}`. */
  anchorOriginBottomLeft?: string,
  /** State class applied to the badge `span` element if `invisible={true}`. */
  invisible?: string,
  /** Styles applied to the badge `span` element if `color="primary"`. */
  colorPrimary?: string,
  /** Styles applied to the badge `span` element if `color="secondary"`. */
  colorSecondary?: string,
  /** Styles applied to the badge `span` element if `color="error"`. */
  colorError?: string,
  /** Styles applied to the badge `span` element if `color="info"`. */
  colorInfo?: string,
  /** Styles applied to the badge `span` element if `color="success"`. */
  colorSuccess?: string,
  /** Styles applied to the badge `span` element if `color="warning"`. */
  colorWarning?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'top', 'right' }} overlap="rectangular"`. */
  anchorOriginTopRightRectangular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'bottom', 'right' }} overlap="rectangular"`. */
  anchorOriginBottomRightRectangular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'top', 'left' }} overlap="rectangular"`. */
  anchorOriginTopLeftRectangular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'bottom', 'left' }} overlap="rectangular"`. */
  anchorOriginBottomLeftRectangular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'top', 'right' }} overlap="circular"`. */
  anchorOriginTopRightCircular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'bottom', 'right' }} overlap="circular"`. */
  anchorOriginBottomRightCircular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'top', 'left' }} overlap="circular"`. */
  anchorOriginTopLeftCircular?: string,
  /** Styles applied to the badge `span` element if `anchorOrigin={{ 'bottom', 'left' }} overlap="circular"`. */
  anchorOriginBottomLeftCircular?: string,
  /** Styles applied to the badge `span` element if `overlap="rectangular"`. */
  overlapRectangular?: string,
  /** Styles applied to the badge `span` element if `overlap="circular"`. */
  overlapCircular?: string,
}

type vertical =
  | @as("top") Top
  | @as("bottom") Bottom

type horizontal =
  | @as("left") Left
  | @as("right") Right

type badgeOrigin = {
  vertical: vertical,
  horizontal: horizontal,
}

@unboxed
type variant =
  | @as("standard") Standard
  | @as("dot") Dot
  | String(string)

@unboxed
type color =
  | @as("primary") Primary
  | @as("secondary") Secondary
  | @as("default") Default
  | @as("error") Error
  | @as("info") Info
  | @as("success") Success
  | @as("warning") Warning
  | String(string)

type slotProps = {
  root?: JsxDOM.domProps,
  badge?: JsxDOM.domProps,
}

type badgeSlots = {
  /**
   * The component that renders the root.
   * @default 'span'
   */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
   * The component that renders the badge.
   * @default 'span'
   */
  badge?: OverridableComponent.t<JsxDOM.domProps>,
}

type overlap =
  | @as("rectangular") Rectangular
  | @as("circular") Circular

type props = {
  ...CommonProps.t,
  /**
    * The content rendered within the badge.
    */
  badgeContent?: React.element,
  /**
    * The badge will be added relative to this node.
    */
  children?: React.element,
  /**
    * If `true`, the badge is invisible.
    * @default false
    */
  invisible?: bool,
  /**
    * Max count to show.
    * @default 99
    */
  max?: int,
  /**
    * The props used for each slot inside the Badge.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The components used for each slot inside the Badge.
    * Either a string to use a HTML element or a component.
    * @default {}
    */
  slots?: badgeSlots,
  /**
    * Controls whether the badge is hidden when `badgeContent` is zero.
    * @default false
    */
  showZero?: bool,
  /**
    * The anchor of the badge.
    * @default {
    *   vertical: 'top',
    *   horizontal: 'right',
    * }
    */
  anchorOrigin?: badgeOrigin,
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
    * Wrapped shape the badge should overlap.
    * @default 'rectangular'
    */
  overlap?: overlap,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The variant to use.
    * @default 'standard'
    */
  variant?: variant,
}

@module("@mui/material/Badge")
external make: React.component<props> = "default"
