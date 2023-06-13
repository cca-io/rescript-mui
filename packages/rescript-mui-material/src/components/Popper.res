type classes = {
  /** Class name applied to the root element. */
  root: string,
}

type components = {@as("Root") root?: React.element}

type basePopperSlotProps = {root?: unknown}

type virtualElement = {
  getBoundingClientRect: unit => Dom.domRect,
  contextElement?: React.element,
}

@unboxed
type anchorEl =
  | @as(null) Null
  | Virtual(virtualElement)
  | Element(unit => React.element)

type phase =
  | @as("afterMain") AfterMain
  | @as("afterRead") AfterRead
  | @as("afterWrite") AfterWrite
  | @as("beforeMain") BeforeMain
  | @as("beforeRead") BeforeRead
  | @as("beforeWrite") BeforeWrite
  | @as("main") Main
  | @as("read") Read
  | @as("write") Write

type modifier = {
  data?: Js.Dict.t<string>,
  effect?: unit => unit,
  enabled?: bool,
  fn?: unit => unit,
  name?: string,
  options?: Js.Dict.t<string>,
  phase: phase,
}

type direction =
  | @as("ltr") Ltr
  | @as("rtl") Rtl

type placement =
  | @as("auto-end") AutoEnd
  | @as("auto-start") AutoStart
  | @as("auto") Auto
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
  | @as("top") Top

type strategy =
  | @as("absolute") Absolute
  | @as("fixed") Fixed

type options = {
  modifiers?: array<modifier>,
  onFirstUpdate?: unit => unit,
  placement?: placement,
  strategy?: strategy,
}

type slotProps = {root?: unknown}

type slots = {root?: React.element}

type props = {
  ...CommonProps.t,
  /**
   * If `true`, the component is shown.
   */
  @as("open")
  open_: bool,
  /**
   * An HTML element, [virtualElement](https://popper.js.org/docs/v2/virtual-elements/),
   * or a function that returns either.
   * It's used to set the position of the popper.
   * The return value will passed as the reference object of the Popper instance.
   */
  anchorEl?: anchorEl,
  /**
   * Popper render function or node.
   */
  children?: React.element,
  /**
   * The component used for the root node.
   * Either a string to use a HTML element or a component.
   */
  component?: React.element,
  /**
   * The components used for each slot inside the Popper.
   * Either a string to use a HTML element or a component.
   * @default {}
   */
  components?: components,
  /**
   * The props used for each slot inside the Popper.
   * @default {}
   */
  componentsProps?: basePopperSlotProps,
  /**
   * An HTML element or function that returns one.
   * The `container` will have the portal children appended to it.
   *
   * By default, it uses the body of the top-level document object,
   * so it's simply `document.body` most of the time.
   */
  container?: React.element,
  /**
   * Direction of the text.
   * @default 'ltr'
   */
  direction?: direction,
  /**
   * The `children` will be under the DOM hierarchy of the parent component.
   * @default false
   */
  disablePortal?: bool,
  /**
   * Always keep the children in the DOM.
   * This prop can be useful in SEO situation or
   * when you want to maximize the responsiveness of the Popper.
   * @default false
   */
  keepMounted?: bool,
  /**
   * Popper.js is based on a "plugin-like" architecture,
   * most of its features are fully encapsulated "modifiers".
   *
   * A modifier is a function that is called each time Popper.js needs to
   * compute the position of the popper.
   * For this reason, modifiers should be very performant to avoid bottlenecks.
   * To learn how to create a modifier, [read the modifiers documentation](https://popper.js.org/docs/v2/modifiers/).
   */
  modifiers?: array<modifier>,
  /**
   * Popper placement.
   * @default 'bottom'
   */
  placement?: placement,
  /**
   * Options provided to the [`Popper.js`](https://popper.js.org/docs/v2/constructors/#options) instance.
   * @default {}
   */
  popperOptions?: options,
  /**
   * A ref that points to the used popper instance.
   */
  popperRef?: React.ref<unknown>,
  /**
   * The props used for each slot inside the Popper.
   * @default {}
   */
  slotProps?: slotProps,
  /**
   * The components used for each slot inside the Popper.
   * Either a string to use a HTML element or a component.
   * @default {}
   */
  slots?: slots,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Sx.props,
  /**
   * Help supporting a react-transition-group/Transition component.
   * @default false
   */
  transition?: bool,
}

@module("@mui/material")
external make: props => React.element = "Popper"
