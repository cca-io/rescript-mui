type horizontal = [#center | #left | #right]

type vertical = [#bottom | #top]

module AnchorOrigin = {
  type t = {"horizontal": option<horizontal>, "vertical": option<vertical>}
  @obj external make: (~horizontal: horizontal=?, ~vertical: vertical=?, unit) => t = ""
}

module Event = {
  type t
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
  ~action: React.element=?,
  ~anchorOrigin: AnchorOrigin.t=?,
  ~autoHideDuration: Number.t=?,
  ~children: React.element=?,
  ~className: string=?,
  ~\"ClickAwayListenerProps": {..}=?,
  ~\"ContentProps": {..}=?,
  ~disableWindowBlurListener: bool=?,
  ~key: string=?,
  ~message: React.element=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClose: (Event.t, string) => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~\"open": bool=?,
  ~resumeHideDuration: Number.t=?,
  ~sx: Sx.t=?,
  ~\"TransitionComponent": React.element=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Snackbar"
