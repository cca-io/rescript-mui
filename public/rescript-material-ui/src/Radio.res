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

type color_enum = [#default | #primary | #secondary | #error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

type size_enum = [#medium | #small]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
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

@react.component @module("@mui/material")
external make: (
  ~centerRipple: bool=?,
  ~children: React.element=?,
  ~component: Component.t=?,
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
  ~tabIndex: Number.t=?,
  ~\"TouchRippleProps": {..}=?,
  ~touchRippleRef: TouchRippleRef.t=?,
  ~\"type": Type.t=?,
  ~style: ReactDOM.Style.t=?,
  ~checked: bool=?,
  ~checkedIcon: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~disabled: bool=?,
  ~disableRipple: bool=?,
  ~icon: React.element=?,
  ~id: string=?,
  ~inputProps: {..}=?,
  ~inputRef: ReactDOM.domRef=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~required: bool=?,
  ~size: Size.t=?,
  ~sx: Sx.t=?,
  ~value: Any.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Radio"
