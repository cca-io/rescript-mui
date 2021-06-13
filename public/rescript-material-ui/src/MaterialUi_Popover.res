module BackdropComponent = {
  type t
  external string: string => t = "%identity"
  external backdropComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module AnchorEl = {
  type t
  external obj: {..} => t = "%identity"
  external anchorEl_func: MaterialUi_Types.any => t = "%identity"
}

type horizontal_enum = [#center | #left | #right]

module Horizontal = {
  type t
  external enum: horizontal_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

type vertical_enum = [#bottom | #center | #top]

module Vertical = {
  type t
  external enum: vertical_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

module AnchorOrigin = {
  type t = {"horizontal": option<Horizontal.t>, "vertical": option<Vertical.t>}
  @obj external make: (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t = ""
}

module AnchorPosition = {
  type t = {"left": option<MaterialUi_Types.Number.t>, "top": option<MaterialUi_Types.Number.t>}
  @obj
  external make: (
    ~left: MaterialUi_Types.Number.t=?,
    ~top: MaterialUi_Types.Number.t=?,
    unit,
  ) => t = ""
}

type anchorReference = [#anchorEl | #anchorPosition | #none]

module Classes = {
  type t = {"root": option<string>, "paper": option<string>}
  @obj external make: (~root: string=?, ~paper: string=?, unit) => t = ""
}

module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external element: React.element => t = "%identity"
  external container_func: MaterialUi_Types.any => t = "%identity"
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module PaperProps = {
  type t = {"component": option<Component.t>}
  @obj external make: (~component: Component.t=?, unit) => t = ""
}

module TransformOrigin = {
  type t = {"horizontal": option<Horizontal.t>, "vertical": option<Vertical.t>}
  @obj external make: (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t = ""
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

type transitionDuration_enum = [#auto]

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
  external enum: transitionDuration_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~\"BackdropComponent": BackdropComponent.t=?,
  ~\"BackdropProps": {..}=?,
  ~closeAfterTransition: bool=?,
  ~disableAutoFocus: bool=?,
  ~disableBackdropClick: bool=?,
  ~disableEnforceFocus: bool=?,
  ~disableEscapeKeyDown: bool=?,
  ~disablePortal: bool=?,
  ~disableRestoreFocus: bool=?,
  ~disableScrollLock: bool=?,
  ~hideBackdrop: bool=?,
  ~keepMounted: bool=?,
  ~manager: {..}=?,
  ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
  ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onRendered: ReactEvent.Synthetic.t => unit=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~anchorEl: AnchorEl.t=?,
  ~anchorOrigin: AnchorOrigin.t=?,
  ~anchorPosition: AnchorPosition.t=?,
  ~anchorReference: anchorReference=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~container: Container.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~getContentAnchorEl: MaterialUi_Types.any=?,
  ~marginThreshold: MaterialUi_Types.Number.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool,
  ~\"PaperProps": PaperProps.t=?,
  ~transformOrigin: TransformOrigin.t=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Popover"
