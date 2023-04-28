type anchor = [#bottom | #left | #right | #top]

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
  ~anchor: anchor=?,
  ~\"BackdropProps": {..}=?,
  ~children: React.element=?,
  ~className: string=?,
  ~hideBackdrop: bool=?,
  ~\"ModalProps": {..}=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~\"PaperProps": {..}=?,
  ~\"SlideProps": {..}=?,
  ~sx: Sx.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Drawer"
