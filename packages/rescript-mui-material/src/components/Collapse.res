type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element when the transition has entered. */
  entered?: string,
  /** Styles applied to the root element when the transition has exited and `collapsedSize` = 0px. */
  hidden?: string,
  /** Styles applied to the outer wrapper element. */
  wrapper?: string,
  /** Styles applied to the inner wrapper element. */
  wrapperInner?: string,
}

@unboxed
type collapsedSize =
  | String(string)
  | Number(float)

type orientation =
  | @as("horizontal") Horizontal
  | @as("vertical") Vertical

type props = {
  ...Transition.props,
  /**
    * The content node to be collapsed.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The width (horizontal) or height (vertical) of the container when collapsed.
    * @default '0px'
    */
  collapsedSize?: collapsedSize,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: React.component<Transition.props>,
  /**
    * The transition timing function.
    * You may specify a single easing or a object containing enter and exit values.
    */
  easing?: Transition.easing,
  /**
    * If `true`, the component will transition in.
    */
  @as("in")
  in_?: bool,
  /**
    * The transition orientation.
    * @default 'vertical'
    */
  orientation?: orientation,
  /**
    * The duration for the transition, in milliseconds.
    * You may specify a single timeout for all transitions, or individually with an object.
    *
    * Set to 'auto' to automatically calculate transition time based on height.
    * @default duration.standard
    */
  timeout?: Transition.durationWithAuto,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/Collapse")
external make: React.component<props> = "default"
