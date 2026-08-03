type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `last={true}` (controlled by `Step`). */
  last?: string,
  /** Styles applied to the Transition component. */
  transition?: string,
}

type slots = {
  /**
    * The component that renders the transition slot.
    * [Follow this guide](https://mui.com/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Collapse
    */
  transition?: OverridableComponent.t<Transition.props>,
}

type slotProps = {
  /**
    * Props forwarded to the transition slot.
    */
  transition?: Transition.props,
}

type props = {
  ...CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
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
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * Adjust the duration of the content expand transition.
    * Passed as a prop to the transition component.
    *
    * Set to 'auto' to automatically calculate transition time based on height.
    * @default 'auto'
    */
  transitionDuration?: Transition.durationWithAuto,
}

@module("@mui/material/StepContent")
external make: React.component<props> = "default"
