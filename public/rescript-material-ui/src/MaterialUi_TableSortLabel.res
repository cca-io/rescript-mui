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

module Classes = {
  type t = {
    "root": option<string>,
    "active": option<string>,
    "icon": option<string>,
    "iconDirectionDesc": option<string>,
    "iconDirectionAsc": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~active: string=?,
    ~icon: string=?,
    ~iconDirectionDesc: string=?,
    ~iconDirectionAsc: string=?,
    unit,
  ) => t = ""
}

type direction = [#asc | #desc]

module IconComponent = {
  type t
  external string: string => t = "%identity"
  external iconComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~centerRipple: bool=?,
  ~component: Component.t=?,
  ~disabled: bool=?,
  ~disableRipple: bool=?,
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
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~active: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~direction: direction=?,
  ~hideSortIcon: bool=?,
  ~\"IconComponent": IconComponent.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TableSortLabel"
