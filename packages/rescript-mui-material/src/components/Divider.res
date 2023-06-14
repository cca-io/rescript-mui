type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if `absolute={true}`. */
  absolute: string,
  /** Styles applied to the root element if `variant="inset"`. */
  inset: string,
  /** Styles applied to the root element if `variant="fullWidth"`. */
  fullWidth: string,
  /** Styles applied to the root element if `light={true}`. */
  light: string,
  /** Styles applied to the root element if `variant="middle"`. */
  middle: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical: string,
  /** Styles applied to the root element if `flexItem={true}`. */
  flexItem: string,
  /** Styles applied to the root element if divider have text. */
  withChildren: string,
  /** Styles applied to the root element if divider have text and `orientation="vertical"`. */
  withChildrenVertical: string,
  /** Styles applied to the root element if `textAlign="right" orientation="horizontal"`. */
  textAlignRight: string,
  /** Styles applied to the root element if `textAlign="left" orientation="horizontal"`. */
  textAlignLeft: string,
  /** Styles applied to the span children element if `orientation="horizontal"`. */
  wrapper: string,
  /** Styles applied to the span children element if `orientation="vertical"`. */
  wrapperVertical: string,
}

type textAlign =
  | @as("center") Center
  | @as("right") Right
  | @as("left") Left

type orientation =
  | @as("horizontal") Horizontal
  | @as("vertical") Vertical

@unboxed
type variant =
  | @as("fullWidth") FullWidth
  | @as("inset") Inset
  | @as("middle") Middle

type props = {
  ...CommonProps.t,
  /**
    * Absolutely position the element.
    * @default false
    */
  absolute?: bool,
  /**
    * The content of the component.
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
    * If `true`, a vertical divider will have the correct height when used in flex container.
    * (By default, a vertical divider will have a calculated height of `0px` if it is the child of a flex container.)
    * @default false
    */
  flexItem?: bool,
  /**
    * If `true`, the divider will have a lighter color.
    * @default false
    */
  light?: bool,
  /**
    * The component orientation.
    * @default 'horizontal'
    */
  orientation?: orientation,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The text alignment.
    * @default 'center'
    */
  textAlign?: textAlign,
  /**
    * The variant to use.
    * @default 'fullWidth'
    */
  variant?: variant,
  role?: string,
}

@module("@mui/material")
external make: props => React.element = "Divider"
