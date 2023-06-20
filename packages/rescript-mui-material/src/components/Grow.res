type props = {
  ...Transition.props,
  /**
   * A single child content element.
   */
  children: React.element,
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
   * The duration for the transition, in milliseconds.
   * You may specify a single timeout for all transitions, or individually with an object.
   *
   * Set to 'auto' to automatically calculate transition time based on height.
   * @default 'auto'
   */
  timeout?: Transition.durationWithAuto,
}

@module("@mui/material/Grow")
external make: React.component<props> = "default"
