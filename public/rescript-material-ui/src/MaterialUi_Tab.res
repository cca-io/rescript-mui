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
    "labelIcon": option<string>,
    "textColorInherit": option<string>,
    "textColorPrimary": option<string>,
    "textColorSecondary": option<string>,
    "selected": option<string>,
    "disabled": option<string>,
    "fullWidth": option<string>,
    "wrapped": option<string>,
    "wrapper": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~labelIcon: string=?,
    ~textColorInherit: string=?,
    ~textColorPrimary: string=?,
    ~textColorSecondary: string=?,
    ~selected: string=?,
    ~disabled: string=?,
    ~fullWidth: string=?,
    ~wrapped: string=?,
    ~wrapper: string=?,
    unit,
  ) => t = ""
}

type textColor = [#secondary | #primary | #inherit]

@react.component @module("@material-ui/core")
external make: (
  ~centerRipple: bool=?,
  ~component: Component.t=?,
  ~disableTouchRipple: bool=?,
  ~focusRipple: bool=?,
  ~focusVisibleClassName: string=?,
  ~href: string=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onDragLeave: ReactEvent.Mouse.t => unit=?,
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
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disabled: bool=?,
  ~disableFocusRipple: bool=?,
  ~disableRipple: bool=?,
  ~fullWidth: bool=?,
  ~icon: React.element=?,
  ~indicator: React.element=?,
  ~label: React.element=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~selected: bool=?,
  ~selectionFollowsFocus: bool=?,
  ~textColor: textColor=?,
  ~value: MaterialUi_Types.any=?,
  ~wrapped: bool=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tab"
