type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the SVG text element. */
  text: string,
  /** State class applied to the root element if `active={true}`. */
  active: string,
  /** State class applied to the root element if `completed={true}`. */
  completed: string,
  /** State class applied to the root element if `error={true}`. */
  error: string,
}

type props = {
  ...CommonProps.t,
  /**
   * Whether this step is active.
   * @default false
   */
  active?: bool,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * Mark the step as completed. Is passed to child components.
   * @default false
   */
  completed?: bool,
  /**
   * If `true`, the step is marked as failed.
   * @default false
   */
  error?: bool,
  /**
   * The label displayed in the step icon.
   */
  icon: React.element,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: props => React.element = "StepIcon"
