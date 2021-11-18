module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module TabIndex = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

type type_enum = [#button | #reset | #submit]

module Type = {
  type t
  external enum: type_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Edge: {
  type t
  let start: t
  let end: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let start = Any("start")
  let end = Any("end")
  let \"false" = Any(false)
}

module Classes = {
  type t = {
    "root": option<string>,
    "checked": option<string>,
    "disabled": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~checked: string=?,
    ~disabled: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #primary | #secondary]

type size = [#medium | #small]

@react.component @module("@material-ui/core")
external make: (
  ~centerRipple: bool=?,
  ~component: Component.t=?,
  ~disableTouchRipple: bool=?,
  ~focusRipple: bool=?,
  ~focusVisibleClassName: string=?,
  ~href: string=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onDragLeave: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onFocusVisible: Types.any=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
  ~onTouchEnd: ReactEvent.Touch.t => unit=?,
  ~onTouchMove: ReactEvent.Touch.t => unit=?,
  ~onTouchStart: ReactEvent.Touch.t => unit=?,
  ~tabIndex: TabIndex.t=?,
  ~\"TouchRippleProps": {..}=?,
  ~\"type": Type.t=?,
  ~style: ReactDOM.Style.t=?,
  ~children: 'children=?,
  ~className: string=?,
  ~disableFocusRipple: bool=?,
  ~edge: Edge.t=?,
  ~checked: bool=?,
  ~checkedIcon: React.element=?,
  ~classes: Classes.t=?,
  ~color: color=?,
  ~disabled: bool=?,
  ~disableRipple: bool=?,
  ~icon: React.element=?,
  ~id: string=?,
  ~inputProps: {..}=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~required: bool=?,
  ~size: size=?,
  ~value: Types.any=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Radio"
