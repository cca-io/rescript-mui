type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the root element if `alternativeLabel={true}`. */
  alternativeLabel?: string,
  /** State class applied to the root element if `completed={true}`. */
  completed?: string,
}

type props = {
  ...CommonProps.t,
  /**
     * Sets the step as active. Is passed to child components.
     */
  active?: bool,
  /**
     * Should be `Step` sub-components such as `StepLabel`, `StepContent`.
     */
  children?: React.element,
  /**
     * Override or extend the styles applied to the component.
     */
  classes?: classes,
  /**
     * Mark the step as completed. Is passed to child components.
     */
  completed?: bool,
  /**
     * The component used for the root node. Either a string to use a HTML element or a component.
  */
  component?: OverridableComponent.t<unknown>,
  /**
     * If `true`, the step is disabled, will also disable the button if
     * `StepButton` is a child of `Step`. Is passed to child components.
     */
  disabled?: bool,
  /**
     * Expand the step.
     * @default false
     */
  expanded?: bool,
  /**
     * The position of the step.
     * The prop defaults to the value inherited from the parent Stepper component.
     */
  index?: int,
  /**
     * If `true`, the Step is displayed as rendered last.
     * The prop defaults to the value inherited from the parent Stepper component.
     */
  last?: bool,
  /**
     * The system prop that allows defining system overrides as well as additional CSS styles.
     */
  sx?: Sx.props,
}

@module("@mui/material")
external make: React.component<props> = "Step"
