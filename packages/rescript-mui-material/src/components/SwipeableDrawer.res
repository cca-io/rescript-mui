module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

type anchor = [#bottom | #left | #right | #top]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module BackdropProps = {
  type t = {"component": option<Component.t>}
  @obj external make: (~component: Component.t=?, unit) => t = ""
}

module ModalProps = {
  type t = {"BackdropProps": option<BackdropProps.t>}
  @obj external make: (~\"BackdropProps": BackdropProps.t=?, unit) => t = ""
}

module PaperProps = {
  type t = {"component": option<Component.t>, "style": option<Any.t>}
  @obj external make: (~component: Component.t=?, ~style: Any.t=?, unit) => t = ""
}

module TransitionDuration_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module TransitionDuration = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

type variant = [#permanent | #persistent | #temporary]

@react.component @module("@mui/material")
external make: (
  ~\"BackdropProps": {..}=?,
  ~className: string=?,
  ~\"SlideProps": {..}=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~anchor: anchor=?,
  ~children: React.element=?,
  ~disableBackdropTransition: bool=?,
  ~disableDiscovery: bool=?,
  ~disableSwipeToOpen: bool=?,
  ~hideBackdrop: bool=?,
  ~hysteresis: Number.t=?,
  ~minFlingVelocity: Number.t=?,
  ~\"ModalProps": ModalProps.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit,
  ~onOpen: ReactEvent.Synthetic.t => unit,
  ~\"open": bool,
  ~\"PaperProps": PaperProps.t=?,
  ~\"SwipeAreaProps": {..}=?,
  ~swipeAreaWidth: Number.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~variant: variant=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SwipeableDrawer"
