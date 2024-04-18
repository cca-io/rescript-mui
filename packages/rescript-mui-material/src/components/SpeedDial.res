type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the Fab component. */
  fab?: string,
  /** Styles applied to the root element if direction="up" */
  directionUp?: string,
  /** Styles applied to the root element if direction="down" */
  directionDown?: string,
  /** Styles applied to the root element if direction="left" */
  directionLeft?: string,
  /** Styles applied to the root element if direction="right" */
  directionRight?: string,
  /** Styles applied to the actions (`children` wrapper) element. */
  actions?: string,
  /** Styles applied to the actions (`children` wrapper) element if `open={false}`. */
  actionsClosed?: string,
}

type direction =
  | @as("up") Up
  | @as("down") Down
  | @as("left") Left
  | @as("right") Right

type closeReason =
  | @as("toggle") Toggle
  | @as("blur") Blur
  | @as("mouseLeave") MouseLeave
  | @as("escapeKeyDown") EscapeKeyDown

type openReason =
  | @as("toggle") Toggle
  | @as("focus") Focus
  | @as("mouseEnter") MouseEnter

type props = {
  ...CommonProps.t,
  /**
    * SpeedDialActions to display when the SpeedDial is `open`.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The direction the actions open relative to the floating action button.
    * @default 'up'
    */
  direction?: direction,
  /**
    * Props applied to the [`Fab`](/material-ui/api/fab/) element.
    * @default {}
    */
  @as("FabProps")
  fabProps?: Fab.props,
  /**
    * If `true`, the SpeedDial is hidden.
    * @default false
    */
  hidden?: bool,
  /**
    * The icon to display in the SpeedDial Fab. The `SpeedDialIcon` component
    * provides a default Icon with animation.
    */
  icon?: React.element,
  onBlur?: ReactEvent.Focus.t => unit,
  /**
    * Callback fired when the component requests to be closed.
    *
    * @param {object} event The event source of the callback.
    * @param {string} reason Can be: `"toggle"`, `"blur"`, `"mouseLeave"`, `"escapeKeyDown"`.
    */
  onClose?: (ReactEvent.Synthetic.t, closeReason) => unit,
  onKeyDown?: ReactEvent.Keyboard.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  /**
    * Callback fired when the component requests to be open.
    *
    * @param {object} event The event source of the callback.
    * @param {string} reason Can be: `"toggle"`, `"focus"`, `"mouseEnter"`.
    */
  onOpen?: (ReactEvent.Synthetic.t, openReason) => unit,
  /**
    * If `true`, the component is shown.
    */
  @as("open")
  open_?: bool,
  /**
    * The icon to display in the SpeedDial Fab when the SpeedDial is open.
    */
  openIcon?: React.element,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The component used for the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Zoom
    */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
    * The duration for the transition, in milliseconds.
    * You may specify a single timeout for all transitions, or individually with an object.
    * @default {
    *   enter: theme.transitions.duration.enteringScreen,
    *   exit: theme.transitions.duration.leavingScreen,
    * }
    */
  transitionDuration?: Transition.duration,
  /**
    * Props applied to the transition element.
    * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
    */
  @as("TransitionProps")
  transitionProps?: Transition.props,
}

@module("@mui/material/SpeedDial")
external make: React.component<props> = "default"
