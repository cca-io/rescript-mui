type classes = {
  /** Styles applied to the Fab component. */
  fab: string,
  /** Styles applied to the Fab component if `open={false}`. */
  fabClosed: string,
  /** Styles applied to the root element if `tooltipOpen={true}`. */
  staticTooltip: string,
  /** Styles applied to the root element if `tooltipOpen={true}` and `open={false}`. */
  staticTooltipClosed: string,
  /** Styles applied to the static tooltip label if `tooltipOpen={true}`. */
  staticTooltipLabel: string,
  /** Styles applied to the root element if `tooltipOpen={true}` and `tooltipPlacement="left"`` */
  tooltipPlacementLeft: string,
  /** Styles applied to the root element if `tooltipOpen={true}` and `tooltipPlacement="right"`` */
  tooltipPlacementRight: string,
}

type props = {
  ...Tooltip.publicProps,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * Props applied to the [`Fab`](/material-ui/api/fab/) component.
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
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * `classes` prop applied to the [`Tooltip`](/material-ui/api/tooltip/) element.
   */
  @as("TooltipClasses")
  tooltipClasses?: Tooltip.classes,
  /**
   * Placement of the tooltip.
   * @default 'left'
   */
  tooltipPlacement?: Tooltip.placement,
  /**
   * Label to display in the tooltip.
   */
  tooltipTitle?: React.element,
  /**
   * Make the tooltip always visible when the SpeedDial is open.
   * @default false
   */
  tooltipOpen?: bool,
}

@module("@mui/material")
external make: props => React.element = "SpeedDialAction"
