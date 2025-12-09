@unboxed
type allowSwipeInChildren =
  | @as(true) True
  | @as(false) False
  | Func((ReactEvent.Touch.t, Dom.element, Dom.element) => bool)

type slots = {
  ...Drawer.slots,
  /**
    * The component used for the swipeArea slot.
    * @default 'div'
    */
  swipeArea?: OverridableComponent.t<JsxDOM.domProps>,
}

type slotProps = {
  ...Drawer.slotProps,
  /**
    * Props forwarded to the swipeArea slot.
    */
  swipeArea?: JsxDOM.domProps,
}

type props = {
  ...Drawer.publicProps,
  /**
    * If set to true, the swipe event will open the drawer even if the user begins the swipe on one of the drawer's children.
    * This can be useful in scenarios where the drawer is partially visible.
    * You can customize it further with a callback that determines which children the user can drag over to open the drawer
    * (for example, to ignore other elements that handle touch move events, like sliders).
    *
    * @param {TouchEvent} event The 'touchstart' event
    * @param {HTMLDivElement} swipeArea The swipe area element
    * @param {HTMLDivElement} paper The drawer's paper element
    *
    * @default false
    */
  allowSwipeInChildren?: allowSwipeInChildren,
  /**
    * Disable the backdrop transition.
    * This can improve the FPS on low-end devices.
    * @default false
    */
  disableBackdropTransition?: bool,
  /**
    * If `true`, touching the screen near the edge of the drawer will not slide in the drawer a bit
    * to promote accidental discovery of the swipe gesture.
    * @default false
    */
  disableDiscovery?: bool,
  /**
    * If `true`, swipe to open is disabled. This is useful in browsers where swiping triggers
    * navigation actions. Swipe to open is disabled on iOS browsers by default.
    * @default typeof navigator !== 'undefined' && /iPad|iPhone|iPod/.test(navigator.userAgent)
    */
  disableSwipeToOpen?: bool,
  /**
    * Affects how far the drawer must be opened/closed to change its state.
    * Specified as percent (0-1) of the width of the drawer
    * @default 0.52
    */
  hysteresis?: float,
  /**
    * Defines, from which (average) velocity on, the swipe is
    * defined as complete although hysteresis isn't reached.
    * Good threshold is between 250 - 1000 px/s
    * @default 450
    */
  minFlingVelocity?: float,
  /**
    * Callback fired when the component requests to be opened.
    *
    * @param {React.SyntheticEvent<{}>} event The event source of the callback.
    */
  onOpen: ReactEvent.Synthetic.t => unit,
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
    * The element is used to intercept the touch events on the edge.
    * @deprecated Use `slotProps.swipeArea` instead. This prop will be removed in v7.
    */
  @as("SwipeAreaProps")
  swipeAreaProps?: unknown,
  /**
    * The width of the left most (or right most) area in `px` that
    * the drawer can be swiped open from.
    * @default 20
    */
  swipeAreaWidth?: float,
}

@module("@mui/material/SwipeableDrawer")
external make: React.component<props> = "default"
