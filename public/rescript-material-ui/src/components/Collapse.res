module CollapsedSize = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Easing_shape = {
  type t = {"enter": option<string>, "exit": option<string>}
  @obj external make: (~enter: string=?, ~exit: string=?, unit) => t = ""
}

module Easing = {
  type t
  external shape: Easing_shape.t => t = "%identity"
  external string: string => t = "%identity"
}

type orientation = [#horizontal | #vertical]

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

type timeout_enum = [#auto]

module Timeout_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module Timeout = {
  type t
  external enum: timeout_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: Timeout_shape.t => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~addEndListener: Any.t=?,
  ~children: React.element=?,
  ~className: string=?,
  ~collapsedSize: CollapsedSize.t=?,
  ~component: Component.t=?,
  ~easing: Easing.t=?,
  ~\"in": bool=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~orientation: orientation=?,
  ~style: ReactDOM.Style.t=?,
  ~sx: Sx.t=?,
  ~timeout: Timeout.t=?,
  ~id: string=?,
  ~mountOnEnter: bool=?,
  ~unmountOnExit: bool=?,
  ~appear: bool=?,
  ~enter: bool=?,
  ~exit: bool=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Collapse"
