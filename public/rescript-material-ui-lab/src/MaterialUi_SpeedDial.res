module Classes = {
  type t = {
    "root": option<string>,
    "fab": option<string>,
    "directionUp": option<string>,
    "directionDown": option<string>,
    "directionLeft": option<string>,
    "directionRight": option<string>,
    "actions": option<string>,
    "actionsClosed": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~fab: string=?,
    ~directionUp: string=?,
    ~directionDown: string=?,
    ~directionLeft: string=?,
    ~directionRight: string=?,
    ~actions: string=?,
    ~actionsClosed: string=?,
    unit,
  ) => t = ""
}

type direction = [#down | #left | #right | #up]

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module TransitionDuration_shape = {
  type t = {
    "appear": option<MaterialUi_Types.Number.t>,
    "enter": option<MaterialUi_Types.Number.t>,
    "exit": option<MaterialUi_Types.Number.t>,
  }
  @obj
  external make: (
    ~appear: MaterialUi_Types.Number.t=?,
    ~enter: MaterialUi_Types.Number.t=?,
    ~exit: MaterialUi_Types.Number.t=?,
    unit,
  ) => t = ""
}

module TransitionDuration = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

@react.component @module("@material-ui/lab")
external make: (
  ~ariaLabel: string,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~direction: direction=?,
  ~\"FabProps": {..}=?,
  ~hidden: bool=?,
  ~icon: React.element=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onOpen: (ReactEvent.Synthetic.t, string) => unit=?,
  ~\"open": bool,
  ~openIcon: React.element=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SpeedDial"
