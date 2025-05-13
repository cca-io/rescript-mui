type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element unless `square={true}`. */
  rounded?: string,
  /** State class applied to the root element if `expanded={true}`. */
  expanded?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element unless `disableGutters={true}`. */
  gutters?: string,
  /** Styles applied to the region element, the container of the children. */
  region?: string,
}

type headingSlotProps = {component?: string}

type slotProps = {
  /**
    * Props applied to the heading element that wraps the AccordionSummary.
    * For example: {component: "h4"}
    */
  heading?: headingSlotProps,
}

type props = {
  ...Paper.publicProps,
  /**
    * The content of the component.
    */
  children: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, expands the accordion by default.
    * @default false
    */
  defaultExpanded?: bool,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, it removes the margin between two expanded accordion items and the increase of height.
    * @default false
    */
  disableGutters?: bool,
  /**
    * If `true`, expands the accordion, otherwise collapses it.
    * Setting this prop enables control over the accordion.
    */
  expanded?: bool,
  /**
    * Callback fired when the expand/collapse state is changed.
    *
    * @param {React.SyntheticEvent} event The event source of the callback. **Warning**: This is a generic event not a change event.
    * @param {boolean} expanded The `expanded` state of the accordion.
    */
  onChange?: (ReactEvent.Form.t, bool) => unit,
  /**
    * The component used for the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Collapse
    */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
    * Props applied to the transition element.
    * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
    */
  @as("TransitionProps")
  transitionProps?: Transition.props,
  /**
    * The variant to use.
    * @default 'elevation'
    */
  variant?: Paper.variant,
  /**
    * The extra props for the slot components, e.g. heading.
    * @default {}
    */
  slotProps?: slotProps,
}

@module("@mui/material/Accordion")
external make: React.component<props> = "default"
