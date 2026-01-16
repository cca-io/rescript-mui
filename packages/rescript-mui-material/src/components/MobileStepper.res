type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `position="bottom"`. */
  positionBottom?: string,
  /** Styles applied to the root element if `position="top"`. */
  positionTop?: string,
  /** Styles applied to the root element if `position="static"`. */
  positionStatic?: string,
  /** Styles applied to the dots container if `variant="dots"`. */
  dots?: string,
  /** Styles applied to each dot if `variant="dots"`. */
  dot?: string,
  /** Styles applied to a dot if `variant="dots"` and this is the active step. */
  dotActive?: string,
  /** Styles applied to the Linear Progress component if `variant="progress"`. */
  progress?: string,
}

type position =
  | @as("bottom") Bottom
  | @as("static") Static
  | @as("top") Top

type variant =
  | @as("text") Text
  | @as("dots") Dots
  | @as("progress") Progress

type slots = {
  /**
    * The component that renders the root slot.
    * @default Paper
    */
  root?: OverridableComponent.t<Paper.props>,
  /**
    * The component that renders the progress slot.
    * @default LinearProgress
    */
  progress?: OverridableComponent.t<LinearProgress.props>,
  /**
    * The component that renders the dots slot.
    * @default 'div'
    */
  dots?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the dot slot.
    * @default 'div'
    */
  dot?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    */
  root?: Paper.props,
  /**
    * Props forwarded to the progress slot.
    */
  progress?: LinearProgress.props,
  /**
    * Props forwarded to the dots slot.
    */
  dots?: JsxDOM.domProps,
  /**
    * Props forwarded to the dot slot.
    */
  dot?: JsxDOM.domProps,
}

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
    * @deprecated Use `slotProps.progress` instead. This prop will be removed in v7.
    */
  @as("LinearProgressProps")
  linearProgressProps?: LinearProgress.props,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The extra props for the slot components.
    * You can override the existing props or add new ones.
    * @default {}
    */
  slotProps?: slotProps,
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
