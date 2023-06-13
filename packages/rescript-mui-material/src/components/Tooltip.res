type classes = {
  /** Styles applied to the Popper component. */
  popper: string,
  /** Styles applied to the Popper component unless `disableInteractive={true}`. */
  popperInteractive: string,
  /** Styles applied to the Popper component if `arrow={true}`. */
  popperArrow: string,
  /** Styles applied to the Popper component unless the tooltip is open. */
  popperClose: string,
  /** Styles applied to the tooltip (label wrapper) element. */
  tooltip: string,
  /** Styles applied to the tooltip (label wrapper) element if `arrow={true}`. */
  tooltipArrow: string,
  /** Styles applied to the arrow element. */
  arrow: string,
  /** Styles applied to the tooltip (label wrapper) element if the tooltip is opened by touch. */
  touch: string,
  /** Styles applied to the tooltip (label wrapper) element if `placement` contains "left". */
  tooltipPlacementLeft: string,
  /** Styles applied to the tooltip (label wrapper) element if `placement` contains "right". */
  tooltipPlacementRight: string,
  /** Styles applied to the tooltip (label wrapper) element if `placement` contains "top". */
  tooltipPlacementTop: string,
  /** Styles applied to the tooltip (label wrapper) element if `placement` contains "bottom". */
  tooltipPlacementBottom: string,
}

type components = {
  @as("Popper") popper?: React.element,
  @as("Transition") transition?: React.element,
  @as("Tooltip") tooltip?: React.element,
  @as("Arrow") arrow?: React.element,
}

type tooltipProps // FIXME
type arrowProps // FIXME

type componentsProps = {
  popper?: Popper.props,
  transition?: Transition.props,
  tooltip?: tooltipProps,
  arrow?: arrowProps,
}

type placement =
  | @as("bottom-end") BottomEnd
  | @as("bottom-start") BottomStart
  | @as("bottom") Bottom
  | @as("left-end") LeftEnd
  | @as("left-start") LeftStart
  | @as("left") Left
  | @as("right-end") RightEnd
  | @as("right-start") RightStart
  | @as("right") Right
  | @as("top-end") TopEnd
  | @as("top-start") TopStart
  | @as("top,") Top

type slotProps = {
  popper?: Popper.props,
  transition?: Transition.props,
  tooltip?: tooltipProps,
  arrow?: arrowProps,
}

type slots = {
  popper?: React.element,
  transition?: React.element,
  tooltip?: React.element,
  arrow?: React.element,
}

type publicProps = {
  ...CommonProps.t_NoId,
  /**
   * Tooltip reference element.
   */
  children: React.element,
  /**
   * If `true`, adds an arrow to the tooltip.
   * @default false
   */
  arrow?: bool,
  /**
   * Set to `true` if the `title` acts as an accessible description.
   * By default the `title` acts as an accessible label for the child.
   * @default false
   */
  describeChild?: bool,
  /**
   * Do not respond to focus-visible events.
   * @default false
   */
  disableFocusListener?: bool,
  /**
   * Do not respond to hover events.
   * @default false
   */
  disableHoverListener?: bool,
  /**
   * Makes a tooltip not interactive, i.e. it will close when the user
   * hovers over the tooltip before the `leaveDelay` is expired.
   * @default false
   */
  disableInteractive?: bool,
  /**
   * Do not respond to long press touch events.
   * @default false
   */
  disableTouchListener?: bool,
  /**
   * The number of milliseconds to wait before showing the tooltip.
   * This prop won't impact the enter touch delay (`enterTouchDelay`).
   * @default 100
   */
  enterDelay?: int,
  /**
   * The number of milliseconds to wait before showing the tooltip when one was already recently opened.
   * @default 0
   */
  enterNextDelay?: int,
  /**
   * The number of milliseconds a user must touch the element before showing the tooltip.
   * @default 700
   */
  enterTouchDelay?: int,
  /**
   * If `true`, the tooltip follow the cursor over the wrapped element.
   * @default false
   */
  followCursor?: bool,
  /**
   * This prop is used to help implement the accessibility logic.
   * If you don't provide this prop. It falls back to a randomly generated id.
   */
  id?: string,
  /**
   * The number of milliseconds to wait before hiding the tooltip.
   * This prop won't impact the leave touch delay (`leaveTouchDelay`).
   * @default 0
   */
  leaveDelay?: int,
  /**
   * The number of milliseconds after the user stops touching an element before hiding the tooltip.
   * @default 1500
   */
  leaveTouchDelay?: int,
  /**
   * Callback fired when the component requests to be closed.
   *
   * @param {React.SyntheticEvent} event The event source of the callback.
   */
  onClose?: ReactEvent.Synthetic.t => unit,
  /**
   * Callback fired when the component requests to be open.
   *
   * @param {React.SyntheticEvent} event The event source of the callback.
   */
  onOpen?: ReactEvent.Synthetic.t => unit,
  /**
   * If `true`, the component is shown.
   */
  @as("open")
  open_?: bool,
  /**
   * Tooltip placement.
   * @default 'bottom'
   */
  placement?: placement,
  /**
   * The component used for the popper.
   * @default Popper
   */
  @as("PopperComponent")
  popperComponent?: React.component<Popper.props>,
  /**
   * Props applied to the [`Popper`](/material-ui/api/popper/) element.
   * @default {}
   */
  @as("PopperProps")
  popperProps?: Popper.props,
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
   * Tooltip title. Zero-length titles string, undefined, null and false are never displayed.
   */
  title: React.element,
  /**
   * The component used for the transition.
   * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
   * @default Grow
   */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
   * Props applied to the transition element.
   * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
   */
  @as("TransitionProps")
  transitionProps?: Transition.props,
}

type props = {
  ...publicProps,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
}

@module("@mui/material")
external make: props => React.element = "Tooltip"
