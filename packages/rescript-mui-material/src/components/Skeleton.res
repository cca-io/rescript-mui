type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="text"`. */
  text?: string,
  /** Styles applied to the root element if `variant="rectangular"`. */
  rectangular?: string,
  /** Styles applied to the root element if `variant="rounded"`. */
  rounded?: string,
  /** Styles applied to the root element if `variant="circular"`. */
  circular?: string,
  /** Styles applied to the root element if `animation="pulse"`. */
  pulse?: string,
  /** Styles applied to the root element if `animation="wave"`. */
  wave?: string,
  /** Styles applied when the component is passed children. */
  withChildren?: string,
  /** Styles applied when the component is passed children and no width. */
  fitContent?: string,
  /** Styles applied when the component is passed children and no height. */
  heightAuto?: string,
}

@unboxed
type animation =
  | @as("pulse") Pulse
  | @as("wave") Wave
  | @as(false) False

@unboxed
type size =
  | Number(float)
  | String(string)

@unboxed
type variant =
  | @as("text") Text
  | @as("rectangular") Rectangular
  | @as("rounded") Rounded
  | @as("circular") Circular

type props = {
  ...CommonProps.t,
  /**
    * The animation.
    * If `false` the animation effect is disabled.
    * @default 'pulse'
    */
  animation?: animation,
  /**
    * Optional children to infer width and height from.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Height of the skeleton.
    * Useful when you don't want to adapt the skeleton to a text element but for instance a card.
    */
  height?: size,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The type of content that will be rendered.
    * @default 'text'
    */
  variant?: variant,
  /**
    * Width of the skeleton.
    * Useful when the skeleton is inside an inline element with no width of its own.
    */
  width?: size,
}

@module("@mui/material/Skeleton")
external make: React.component<props> = "default"
