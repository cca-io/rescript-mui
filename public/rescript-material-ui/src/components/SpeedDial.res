type direction = [#down | #left | #right | #up]

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

@react.component @module("@mui/material")
external make: (
  ~ariaLabel: string,
  ~children: React.element=?,
  ~className: string=?,
  ~direction: direction=?,
  ~\"FabProps": {..}=?,
  ~hidden: bool=?,
  ~icon: React.element=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onOpen: (ReactEvent.Synthetic.t, string) => unit=?,
  ~\"open": bool=?,
  ~openIcon: React.element=?,
  ~sx: Sx.t=?,
  ~\"TransitionComponent": React.element=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SpeedDial"
