type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `orientation="horizontal"`. */
  horizontal?: string,
  /** Styles applied to the root element if `orientation="vertical"`. */
  vertical?: string,
  /** Styles applied to the label element that wraps `children`. */
  label?: string,
  /** State class applied to the label element if `active={true}`. */
  active?: string,
  /** State class applied to the label element if `completed={true}`. */
  completed?: string,
  /** State class applied to the root and label elements if `error={true}`. */
  error?: string,
  /** State class applied to the root and label elements if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the `icon` container element. */
  iconContainer?: string,
  /** State class applied to the root and icon container and label if `alternativeLabel={true}`. */
  alternativeLabel?: string,
  /** Styles applied to the container element which wraps label and `optional`. */
  labelContainer?: string,
}

type slots = {
  label?: OverridableComponent.t<Typography.props>,
}

type slotProps = {
  /**
    * Props applied to the label element.
    * @default {}
    */
  label?: Typography.props,
}

type props = {
  ...CommonProps.t,
  /**
    * In most cases will simply be a string containing a title for the label.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, the step is marked as failed.
    * @default false
    */
  error?: bool,
  /**
    * Override the default label of the step icon.
    */
  icon?: React.element,
  /**
    * The optional node to display.
    */
  optional?: React.element,
  /**
    * The components used for each slot inside.
    * @default {}
    */
  slots?: slots,
  /**
    * The props used for each slot inside.
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The component to render in place of the [`StepIcon`](/material-ui/api/step-icon/).
    */
  @as("StepIconComponent")
  stepIconComponent?: React.component<StepIcon.props>,
  /**
    * Props applied to the [`StepIcon`](/material-ui/api/step-icon/) element.
    */
  @as("StepIconProps")
  stepIconProps?: StepIcon.props,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/StepLabel")
external make: React.component<props> = "default"
