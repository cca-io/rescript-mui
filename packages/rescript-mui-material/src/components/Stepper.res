type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the root element if `alternativeLabel={true}`. */
  alternativeLabel?: string,
}

type orientation =
  | @as("horizontal") Horizontal
  | @as("vertical") Vertical

type props = {
  ...CommonProps.t,
  elevation?: int,
  square?: bool,
  variant?: Paper.variant,
  /**
    * Set the active step (zero based index).
    * Set to -1 to disable all the steps.
    * @default 0
    */
  activeStep?: int,
  /**
    * If set to 'true' and orientation is horizontal,
    * then the step label will be positioned under the icon.
    * @default false
    */
  alternativeLabel?: bool,
  /**
    * Two or more `<Step />` components.
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
    * An element to be placed between each step.
    * @default <StepConnector />
    */
  connector?: React.element,
  /**
    * If set the `Stepper` will not assist in controlling steps for linear flow.
    * @default false
    */
  nonLinear?: bool,
  /**
    * The component orientation (layout flow direction).
    * @default 'horizontal'
    */
  orientation?: orientation,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/Stepper")
external make: React.component<props> = "default"
