type timeoutObject = {
  appear?: int,
  enter?: int,
  exit?: int,
}

@unboxed
type timeout =
  | Timeout(int)
  | Object(timeoutObject)

type easingObject = {
  enter?: string,
  exit?: string,
}

@unboxed
type easing =
  | Easing(string)
  | Object(easingObject)

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
   * The transition timing function.
   * You may specify a single easing or a object containing enter and exit values.
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
  timeout?: timeout,
}

@module("@mui/material")
external make: props => React.element = "Fade"
