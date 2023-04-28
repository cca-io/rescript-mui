module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
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

module Current = {
  type t = {"pulsate": option<Any.t>, "start": option<Any.t>, "stop": option<Any.t>}
  @obj external make: (~pulsate: Any.t=?, ~start: Any.t=?, ~stop: Any.t=?, unit) => t = ""
}

module TouchRippleRef_shape = {
  type t = {"current": option<Current.t>}
  @obj external make: (~current: Current.t=?, unit) => t = ""
}

module TouchRippleRef = {
  type t
  external touchRippleRef_func: Any.t => t = "%identity"
  external shape: TouchRippleRef_shape.t => t = "%identity"
}

type type_enum = [#button | #reset | #submit]

module Type = {
  type t
  external enum: type_enum => t = "%identity"
  external string: string => t = "%identity"
}

type rel = [
  | #alternate
  | #author
  | #bookmark
  | #"external"
  | #help
  | #license
  | #next
  | #nofollow
  | #noreferrer
  | #noopener
  | #prev
  | #search
  | #tag
]

@react.component @module("@mui/material")
external make: (
  ~centerRipple: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~disabled: bool=?,
  ~disableRipple: bool=?,
  ~disableTouchRipple: bool=?,
  ~focusRipple: bool=?,
  ~focusVisibleClassName: string=?,
  ~href: Any.t=?,
  ~\"LinkComponent": React.element=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onContextMenu: ReactEvent.Mouse.t => unit=?,
  ~onDragLeave: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onFocusVisible: Any.t=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
  ~onTouchEnd: ReactEvent.Touch.t => unit=?,
  ~onTouchMove: ReactEvent.Touch.t => unit=?,
  ~onTouchStart: ReactEvent.Touch.t => unit=?,
  ~sx: Sx.t=?,
  ~tabIndex: Number.t=?,
  ~\"TouchRippleProps": {..}=?,
  ~touchRippleRef: TouchRippleRef.t=?,
  ~\"type": Type.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~target: string=?,
  ~rel: rel=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ButtonBase"
