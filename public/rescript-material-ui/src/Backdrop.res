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

module Classes = {
  type t = {"root": option<string>, "invisible": option<string>}
  @obj external make: (~root: string=?, ~invisible: string=?, unit) => t = ""
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

@react.component @module("@material-ui/core")
external make: (
  ~disableStrictModeCompat: bool=?,
  ~\"in": bool=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~style: ReactDOM.Style.t=?,
  ~timeout: Timeout.t=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~invisible: bool=?,
  ~\"open": bool,
  ~transitionDuration: TransitionDuration.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Backdrop"
