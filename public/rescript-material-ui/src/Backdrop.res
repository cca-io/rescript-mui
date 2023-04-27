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

module Components = {
  type t = {"Root": option<React.element>}
  @obj external make: (~\"Root": React.element=?, unit) => t = ""
}

module ComponentsProps = {
  type t = {"root": option<Any.t>}
  @obj external make: (~root: Any.t=?, unit) => t = ""
}

module SlotProps = {
  type t = {"root": option<Any.t>}
  @obj external make: (~root: Any.t=?, unit) => t = ""
}

module Slots = {
  type t = {"root": option<React.element>}
  @obj external make: (~root: React.element=?, unit) => t = ""
}

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
  ~addEndListener: Any.t=?,
  ~appear: bool=?,
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
  ~children: React.element=?,
  ~className: string=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~invisible: bool=?,
  ~\"open": bool,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Backdrop"
