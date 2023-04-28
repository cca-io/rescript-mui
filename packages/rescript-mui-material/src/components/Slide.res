type direction = [#down | #left | #right | #up]

module Easing_shape = {
  type t = {"enter": option<string>, "exit": option<string>}
  @obj external make: (~enter: string=?, ~exit: string=?, unit) => t = ""
}

module Easing = {
  type t
  external shape: Easing_shape.t => t = "%identity"
  external string: string => t = "%identity"
}

module Timeout_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module Timeout = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: Timeout_shape.t => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~addEndListener: Any.t=?,
  ~appear: bool=?,
  ~children: React.element=?,
  ~direction: direction=?,
  ~easing: Easing.t=?,
  ~\"in": bool=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~style: ReactDOM.Style.t=?,
  ~timeout: Timeout.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Slide"
