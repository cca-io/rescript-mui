module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
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

module Icon = {
  type t
  external element: React.element => t = "%identity"
  external string: string => t = "%identity"
}

type iconPosition = [#bottom | #end | #start | #top]

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

@react.component @module("@mui/material")
external make: (
  ~centerRipple: bool=?,
  ~component: Component.t=?,
  ~disableTouchRipple: bool=?,
  ~focusRipple: bool=?,
  ~focusVisibleClassName: string=?,
  ~href: Any.t=?,
  ~\"LinkComponent": React.element=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onContextMenu: ReactEvent.Mouse.t => unit=?,
  ~onDragLeave: ReactEvent.Mouse.t => unit=?,
  ~onFocusVisible: Any.t=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
  ~onTouchEnd: ReactEvent.Touch.t => unit=?,
  ~onTouchMove: ReactEvent.Touch.t => unit=?,
  ~onTouchStart: ReactEvent.Touch.t => unit=?,
  ~tabIndex: Number.t=?,
  ~\"TouchRippleProps": {..}=?,
  ~touchRippleRef: TouchRippleRef.t=?,
  ~\"type": Type.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~children: React.element=?,
  ~className: string=?,
  ~disabled: bool=?,
  ~disableFocusRipple: bool=?,
  ~disableRipple: bool=?,
  ~icon: Icon.t=?,
  ~iconPosition: iconPosition=?,
  ~label: React.element=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~sx: Sx.t=?,
  ~value: Any.t=?,
  ~wrapped: bool=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tab"