module Component: {
  type t
  let string: string => t
  let callback: (unit => React.element) => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let callback = (v: unit => React.element) => Any(v)
  let element = (v: React.element) => Any(v)
}

module TabIndex: {
  type t
  let int: int => t
  let float: float => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let string = (v: string) => Any(v)
}

module Type_enum: {
  type t
  let button: t
  let reset: t
  let submit: t
} = {
  @unboxed
  type rec t = Any('a): t

  let button = Any("button")
  let reset = Any("reset")
  let submit = Any("submit")
}

module Type: {
  type t
  let enum: Type_enum.t => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let enum = (v: Type_enum.t) => Any(v)
  let string = (v: string) => Any(v)
}

module Classes = {
  type t = {
    "root": option<string>,
    "edgeStart": option<string>,
    "edgeEnd": option<string>,
    "switchBase": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "sizeSmall": option<string>,
    "checked": option<string>,
    "disabled": option<string>,
    "input": option<string>,
    "thumb": option<string>,
    "track": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~edgeStart: string=?,
    ~edgeEnd: string=?,
    ~switchBase: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~sizeSmall: string=?,
    ~checked: string=?,
    ~disabled: string=?,
    ~input: string=?,
    ~thumb: string=?,
    ~track: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #primary | #secondary]

module Edge: {
  type t
  let end: t
  let start: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let end = Any("end")
  let start = Any("start")
  let \"false" = Any(false)
}

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
  ~onFocusVisible: MaterialUi_Types.any=?,
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
  ~disableFocusRipple: bool=?,
  ~checked: bool=?,
  ~checkedIcon: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~defaultChecked: bool=?,
  ~disabled: bool=?,
  ~disableRipple: bool=?,
  ~edge: Edge.t=?,
  ~icon: React.element=?,
  ~id: string=?,
  ~inputProps: {..}=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~required: bool=?,
  ~size: size=?,
  ~value: MaterialUi_Types.any=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Switch"
