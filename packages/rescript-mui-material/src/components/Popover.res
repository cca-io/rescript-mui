type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the Paper component. */
  paper?: string,
}

type actions = {updatePosition: unit => unit}

@unboxed
type anchorEl =
  | @as(null) Null
  | Virtual(Popper.virtualElement)
  | Element(unit => Js.nullable<Dom.element>)

@unboxed
type verticalOrigin =
  | @as("top") Top
  | @as("center") Center
  | @as("bottom") Bottom
  | Number(float)

@unboxed
type horizontalOrigin =
  | @as("left") Left
  | @as("center") Center
  | @as("right") Right
  | Number(float)

type origin = {
  vertical: verticalOrigin,
  horizontal: horizontalOrigin,
}

type position = {
  left: int,
  top: int,
}

type reference =
  | @as("anchorEl") AnchorEl
  | @as("anchorPosition") AnchorPosition
  | @as("none") None

type slots = {
  root?: OverridableComponent.t<Modal.props>,
  paper?: OverridableComponent.t<Paper.props>,
  transition?: OverridableComponent.t<Transition.props>,
  backdrop?: OverridableComponent.t<Backdrop.props>,
}

type slotProps = {
  root?: Modal.props,
  paper?: Paper.props,
  /**
    * Props forwarded to the transition slot.
    * By default, the avaible props are based on the [Grow](https://mui.com/material-ui/api/grow/#props) component.
    */
  transition?: Transition.props,
  /**
    * Props forwarded to the backdrop slot.
    * By default, the avaible props are based on the [Backdrop](https://mui.com/material-ui/api/backdrop/#props) component.
    */
  backdrop?: Backdrop.props,
}

type publicProps = {
  ...Modal.publicProps,
  /**
    * If `true`, the component is shown.
    */
  @as("open")
  open_: bool,
  /**
    * A ref for imperative actions.
    * It currently only supports updatePosition() action.
    */
  action?: React.ref<actions>,
  /**
    * An HTML element, [PopoverVirtualElement](/material-ui/react-popover/#virtual-element),
    * or a function that returns either.
    * It's used to set the position of the popover.
    */
  anchorEl?: anchorEl,
  /**
    * This is the point on the anchor where the popover's
    * `anchorEl` will attach to. This is not used when the
    * anchorReference is 'anchorPosition'.
    *
    * Options:
    * vertical: [top, center, bottom];
    * horizontal: [left, center, right].
    * @default {
    *   vertical: 'top',
    *   horizontal: 'left',
    * }
    */
  anchorOrigin?: origin,
  /**
    * This is the position that may be used to set the position of the popover.
    * The coordinates are relative to the application's client area.
    */
  anchorPosition?: position,
  /**
    * This determines which anchor prop to refer to when setting
    * the position of the popover.
    * @default 'anchorEl'
    */
  anchorReference?: reference,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * An HTML element, component instance, or function that returns either.
    * The `container` will passed to the Modal component.
    *
    * By default, it uses the body of the anchorEl's top-level document object,
    * so it's simply `document.body` most of the time.
    */
  container?: React.element,
  /**
    * The elevation of the popover.
    * @default 8
    */
  elevation?: int,
  /**
    * Specifies how close to the edge of the window the popover can appear.
    * @default 16
    */
  marginThreshold?: int,
  onClose?: Modal.onClose,
  /**
    * This is the point on the popover which
    * will attach to the anchor's origin.
    *
    * Options:
    * vertical: [top, center, bottom, x(px)];
    * horizontal: [left, center, right, x(px)].
    * @default {
    *   vertical: 'top',
    *   horizontal: 'left',
    * }
    */
  transformOrigin?: origin,
  /**
    * The component used for the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Grow
    */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
    * Set to 'auto' to automatically calculate transition time based on height.
    * @default 'auto'
    */
  transitionDuration?: Transition.durationWithAuto,
  /**
    * Props applied to the transition element.
    * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
    * @default {}
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
    * The components used for each slot inside.
    *
    * @default {}
    */
  slots?: slots,
  /**
    * The extra props for the slot components.
    * You can override the existing props or add new ones.
    *
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
}

@module("@mui/material/Popover")
external make: React.component<props> = "default"
