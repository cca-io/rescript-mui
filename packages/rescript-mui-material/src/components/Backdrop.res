type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `invisible={true}`. */
  invisible?: string,
}

type slots = {@as("Root") root?: React.element}

type slotProps = {root?: unknown}

type props = {
  ...Fade.publicProps,
  /**
       * If `true`, the component is shown.
       */
  @as("open")
  open_?: bool,
  /**
       * The content of the component.
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
       * If `true`, the backdrop is invisible.
       * It can be used when rendering a popover or a custom select component.
       * @default false
       */
  invisible?: bool,
  /**
       * The extra props for the slot components.
       * You can override the existing props or add new ones.
       * @default {}
       */
  slotProps?: slotProps,
  /**
       * The components used for each slot inside.
       * @default {}
       */
  slots?: slots,
  /**
       * The system prop that allows defining system overrides as well as additional CSS styles.
       */
  sx?: Sx.props,
  /**
       * The component used for the transition.
       * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
       * @default Fade
       */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
       * The duration for the transition, in milliseconds.
       * You may specify a single timeout for all transitions, or individually with an object.
       */
  transitionDuration?: Transition.duration,
}

@module("@mui/material/Backdrop")
external make: React.component<props> = "default"
