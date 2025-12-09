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

type slots = {
  /**
    * The component that renders the root.
    * @default Paper
    */
  root?: OverridableComponent.t<Paper.props>,
  /**
    * The component that renders the heading.
    * @default 'h3'
    */
  heading?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the transition.
    * [Follow this guide](https://mui.com/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Collapse
    */
  transition?: OverridableComponent.t<Transition.props>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    * By default, the avaible props are based on the Paper element.
    */
  root?: Paper.props,
  /**
    * Props forwarded to the heading slot.
    * By default, the avaible props are based on the h3 element.
    */
  heading?: JsxDOM.domProps,
  /**
    * Props forwarded to the transition slot.
    * By default, the avaible props are based on the [Collapse](https://mui.com/material-ui/api/collapse/#props) component.
    */
  transition?: Transition.props,
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
    * The component used for the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @deprecated Use `slots.transition` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    * @default Collapse
    */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
    * Props applied to the transition element.
    * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
    * @deprecated Use `slotProps.transition` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    */
  @as("TransitionProps")
  transitionProps?: Transition.props,
  /**
    * The variant to use.
    * @default 'elevation'
    */
  variant?: Paper.variant,
}

@module("@mui/material/Accordion")
external make: React.component<props> = "default"
