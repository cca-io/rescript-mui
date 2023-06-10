type direction =
  | @as("left") Left
  | @as("right") Right
  | @as("up") Up
  | @as("down") Down

@unboxed
type easing =
  | Easing(string)
  | Object(Transition.easingObject)

@unboxed
type duration =
  | Duration(int)
  | Object(Transition.durationObject)

type props = {
  ...CommonProps.t,
  /**
   * Perform the enter transition when it first mounts if `in` is also `true`.
   * Set this to `false` to disable this behavior.
   * @default true
   */
  appear?: bool,
  /**
   * A single child content element.
   */
  children: React.element,
  /**
   * An HTML element, or a function that returns one.
   * It's used to set the container the Slide is transitioning from.
   */
  container?: React.element,
  /**
   * Direction the child node will enter from.
   * @default 'down'
   */
  direction?: direction,
  /**
   * The transition timing function.
   * You may specify a single easing or a object containing enter and exit values.
   * @default {
   *   enter: theme.transitions.easing.easeOut,
   *   exit: theme.transitions.easing.sharp,
   * }
   */
  easing?: easing,
  /**
   * If `true`, the component will transition in.
   */
  @as("in")
  in_?: bool,
  /**
   * The duration for the transition, in milliseconds.
   * You may specify a single timeout for all transitions, or individually with an object.
   * @default {
   *   enter: theme.transitions.duration.enteringScreen,
   *   exit: theme.transitions.duration.leavingScreen,
   * }
   */
  timeout?: duration,
}

@module("@mui/material")
external make: props => React.element = "Slide"
