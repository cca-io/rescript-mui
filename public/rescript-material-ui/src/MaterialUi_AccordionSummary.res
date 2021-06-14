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
    "expanded": option<string>,
    "focused": option<string>,
    "disabled": option<string>,
    "content": option<string>,
    "expandIcon": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~expanded: string=?,
    ~focused: string=?,
    ~disabled: string=?,
    ~content: string=?,
    ~expandIcon: string=?,
    unit,
  ) => t = ""
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
  ~onDragLeave: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
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
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~expandIcon: React.element=?,
  ~\"IconButtonProps": {..}=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocusVisible: MaterialUi_Types.any=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "AccordionSummary"
