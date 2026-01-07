type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `anchorOrigin={{ 'top', 'center' }}`. */
  anchorOriginTopCenter?: string,
  /** Styles applied to the root element if `anchorOrigin={{ 'bottom', 'center' }}`. */
  anchorOriginBottomCenter?: string,
  /** Styles applied to the root element if `anchorOrigin={{ 'top', 'right' }}`. */
  anchorOriginTopRight?: string,
  /** Styles applied to the root element if `anchorOrigin={{ 'bottom', 'right' }}`. */
  anchorOriginBottomRight?: string,
  /** Styles applied to the root element if `anchorOrigin={{ 'top', 'left' }}`. */
  anchorOriginTopLeft?: string,
  /** Styles applied to the root element if `anchorOrigin={{ 'bottom', 'left' }}`. */
  anchorOriginBottomLeft?: string,
}

type slots = {
  /**
    * The component that renders the root slot.
    * @default 'div'
    */
  root?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the content slot.
    * @default SnackbarContent
    */
  content?: OverridableComponent.t<SnackbarContent.props>,
  /**
    * The component that renders the clickAwayListener slot.
    * @default ClickAwayListener
    */
  clickAwayListener?: OverridableComponent.t<JsxDOM.domProps>,
  /**
    * The component that renders the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Grow
    */
  transition?: OverridableComponent.t<Transition.props>,
}

type slotProps = {
  /**
    * Props forwarded to the root slot.
    * By default, the avaible props are based on the div element.
    */
  root?: JsxDOM.domProps,
  /**
    * Props forwarded to the content slot.
    * By default, the avaible props are based on the [SnackbarContent](https://mui.com/material-ui/api/snackbar-content/#props) component.
    */
  content?: SnackbarContent.props,
  /**
    * Props forwarded to the clickAwayListener slot.
    * By default, the avaible props are based on the [ClickAwayListener](https://mui.com/material-ui/api/click-away-listener/#props) component.
    */
  clickAwayListener?: JsxDOM.domProps,
  /**
    * Props applied to the transition element.
    * By default, the element is based on the [Grow](https://mui.com/material-ui/api/grow/#props) component.
    */
  transition?: Transition.props,
}

type vertical =
  | @as("top") Top
  | @as("bottom") Bottom

type horizontal =
  | @as("left") Left
  | @as("center") Center
  | @as("right") Right

type origin = {
  vertical: vertical,
  horizontal: horizontal,
}

@unboxed
type autoHideDuration =
  | Number(float)
  | @as(null) Null

type closeReason =
  | @as("timeout") Timeout
  | @as("clickaway") Clickaway
  | @as("escapeKeyDown") EscapeKeyDown

type props = {
  ...CommonProps.t,
  /**
    * The action to display. It renders after the message, at the end of the snackbar.
    */
  action?: SnackbarContent.action,
  /**
    * The anchor of the `Snackbar`.
    * On smaller screens, the component grows to occupy all the available width,
    * the horizontal alignment is ignored.
    * @default { vertical: 'bottom', horizontal: 'left' }
    */
  anchorOrigin?: origin,
  /**
    * The number of milliseconds to wait before automatically calling the
    * `onClose` function. `onClose` should then set the state of the `open`
    * prop to hide the Snackbar. This behavior is disabled by default with
    * the `null` value.
    * @default null
    */
  autoHideDuration?: autoHideDuration,
  /**
    * Replace the `SnackbarContent` component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * Props applied to the `ClickAwayListener` element.
    * @deprecated Use `slotProps.clickAwayListener` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    */
  @as("ClickAwayListenerProps")
  clickAwayListenerProps?: unknown,
  /**
    * Props applied to the [`SnackbarContent`](/material-ui/api/snackbar-content/) element.
    * @deprecated Use `slotProps.content` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    */
  @as("ContentProps")
  contentProps?: SnackbarContent.props,
  /**
    * When displaying multiple consecutive Snackbars from a parent rendering a single
    * <Snackbar/>, add the key prop to ensure independent treatment of each message.
    * e.g. <Snackbar key={message} />, otherwise, the message may update-in-place and
    * features such as autoHideDuration may be canceled.
    */
  key?: string,
  /**
    * If `true`, the `autoHideDuration` timer will expire even if the window is not focused.
    * @default false
    */
  disableWindowBlurListener?: bool,
  /**
    * The message to display.
    */
  message?: SnackbarContent.message,
  onBlur?: ReactEvent.Focus.t => unit,
  /**
    * Callback fired when the component requests to be closed.
    * Typically `onClose` is used to set state in the parent component,
    * which is used to control the `Snackbar` `open` prop.
    * The `reason` parameter can optionally be used to control the response to `onClose`,
    * for example ignoring `clickaway`.
    *
    * @param {React.SyntheticEvent<any> | Event} event The event source of the callback.
    * @param {string} reason Can be: `"timeout"` (`autoHideDuration` expired), `"clickaway"`, or `"escapeKeyDown"`.
    */
  onClose?: (ReactEvent.Synthetic.t, closeReason) => unit,
  onFocus?: ReactEvent.Focus.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  /**
    * If `true`, the component is shown.
    */
  @as("open")
  open_?: bool,
  /**
    * The number of milliseconds to wait before dismissing after user interaction.
    * If `autoHideDuration` prop isn't specified, it does nothing.
    * If `autoHideDuration` prop is specified but `resumeHideDuration` isn't,
    * we default to `autoHideDuration / 2` ms.
    */
  resumeHideDuration?: int,
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
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The component used for the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @deprecated Use `slots.transition` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    * @default Grow
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
    * @deprecated Use `slotProps.transition` instead. This prop will be removed in v7. See [Migrating from deprecated APIs](/material-ui/migration/migrating-from-deprecated-apis/) for more details.
    * @default {}
    */
  @as("TransitionProps")
  transitionProps?: Transition.props,
}

@module("@mui/material/Snackbar")
external make: React.component<props> = "default"
