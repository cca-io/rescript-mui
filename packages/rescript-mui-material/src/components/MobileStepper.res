type classes = {
  /** Styles applied to the root element. */
  root: string,
  /** Styles applied to the root element if `position="bottom"`. */
  positionBottom: string,
  /** Styles applied to the root element if `position="top"`. */
  positionTop: string,
  /** Styles applied to the root element if `position="static"`. */
  positionStatic: string,
  /** Styles applied to the dots container if `variant="dots"`. */
  dots: string,
  /** Styles applied to each dot if `variant="dots"`. */
  dot: string,
  /** Styles applied to a dot if `variant="dots"` and this is the active step. */
  dotActive: string,
  /** Styles applied to the Linear Progress component if `variant="progress"`. */
  progress: string,
}

type position =
  | @as("bottom") Bottom
  | @as("static") Static
  | @as("top") Top

type variant =
  | @as("text") Text
  | @as("dots") Dots
  | @as("progress") Progress

type props = {
  ...Paper.publicProps,
  /**
   * The total steps.
   */
  steps: int,
  /**
   * Set the active step (zero based index).
   * Defines which dot is highlighted when the variant is 'dots'.
   * @default 0
   */
  activeStep?: int,
  /**
   * A back button element. For instance, it can be a `Button` or an `IconButton`.
   */
  backButton: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Props applied to the `LinearProgress` element.
   */
  @as("LinearProgressProps")
  linearProgressProps?: LinearProgress.props,
  /**
   * A next button element. For instance, it can be a `Button` or an `IconButton`.
   */
  nextButton: React.element,
  /**
   * Set the positioning type.
   * @default 'bottom'
   */
  position?: position,
  /**
   * The variant to use.
   * @default 'dots'
   */
  variant?: variant,
}

@module("@mui/material/MobileStepper")
external make: React.component<props> = "default"
