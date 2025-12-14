type classes = {
  /** Styles applied to the Fab component. */
  fab?: string,
  /** Styles applied to the Fab component if `open={false}`. */
  fabClosed?: string,
  /** Styles applied to the root element if `tooltipOpen={true}`. */
  staticTooltip?: string,
  /** Styles applied to the root element if `tooltipOpen={true}` and `open={false}`. */
  staticTooltipClosed?: string,
  /** Styles applied to the static tooltip label if `tooltipOpen={true}`. */
  staticTooltipLabel?: string,
  /** Styles applied to the root element if `tooltipOpen={true}` and `tooltipPlacement="left"`` */
  tooltipPlacementLeft?: string,
  /** Styles applied to the root element if `tooltipOpen={true}` and `tooltipPlacement="right"`` */
  tooltipPlacementRight?: string,
}

type slots = {
  /**
    * The component that renders the fab.
    * @default Fab
    */
  fab?: OverridableComponent.t<Fab.props>,
  /**
    * The component that renders the tooltip.
    * @default Tooltip
    */
  tooltip?: OverridableComponent.t<Tooltip.props>,
  /**
    * The component that renders the static tooltip.
    * @default 'span'
    */
  staticTooltip?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the static tooltip label.
    * @default 'span'
    */
  staticTooltipLabel?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  /**
    * Props forwarded to the fab slot.
    */
  fab?: Fab.props,
  /**
    * Props forwarded to the tooltip slot.
    */
  tooltip?: Tooltip.props,
  /**
    * Props forwarded to the static tooltip slot.
    */
  staticTooltip?: JsxDOM.domProps,
  /**
    * Props forwarded to the static tooltip label slot.
    */
  staticTooltipLabel?: JsxDOM.domProps,
}

type props = {
  ...Tooltip.publicProps,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Props applied to the [`Fab`](/material-ui/api/fab/) component.
    * @deprecated Use `slotProps.fab` instead. This prop will be removed in v7.
    * @default {}
    */
  @as("FabProps")
  fabProps?: Fab.props,
  /**
    * Adds a transition delay, to allow a series of SpeedDialActions to be animated.
    * @default 0
    */
  delay?: float,
  /**
    * The icon to display in the SpeedDial Fab.
    */
  icon?: React.element,
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
    * `classes` prop applied to the [`Tooltip`](/material-ui/api/tooltip/) element.
    * @deprecated Use `slotProps.tooltip.classes` instead. This prop will be removed in v7.
    */
  @as("TooltipClasses")
  tooltipClasses?: Tooltip.classes,
  /**
    * Placement of the tooltip.
    * @deprecated Use `slotProps.tooltip.placement` instead. This prop will be removed in v7.
    * @default 'left'
    */
  tooltipPlacement?: Tooltip.placement,
  /**
    * Label to display in the tooltip.
    * @deprecated Use `slotProps.tooltip.title` instead. This prop will be removed in v7.
    */
  tooltipTitle?: React.element,
  /**
    * Make the tooltip always visible when the SpeedDial is open.
    * @deprecated Use `slotProps.tooltip.open` instead. This prop will be removed in v7.
    * @default false
    */
  tooltipOpen?: bool,
}

@module("@mui/material/SpeedDialAction")
external make: React.component<props> = "default"
