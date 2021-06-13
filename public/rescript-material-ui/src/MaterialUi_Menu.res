module BackdropComponent = {
  type t
  external string: string => t = "%identity"
  external backdropComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module Horizontal_enum: {
  type t
  let center: t
  let left: t
  let right: t
} = {
  @unboxed
  type rec t = Any('a): t

  let center = Any("center")
  let left = Any("left")
  let right = Any("right")
}

module Horizontal = {
  type t
  external enum: Horizontal_enum.t => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

module Vertical_enum: {
  type t
  let bottom: t
  let center: t
  let top: t
} = {
  @unboxed
  type rec t = Any('a): t

  let bottom = Any("bottom")
  let center = Any("center")
  let top = Any("top")
}

module Vertical = {
  type t
  external enum: Vertical_enum.t => t = "%identity"
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

module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external element: React.element => t = "%identity"
  external container_func: MaterialUi_Types.any => t = "%identity"
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

module Classes = {
  type t = {"paper": option<string>, "list": option<string>}
  @obj external make: (~paper: string=?, ~list: string=?, unit) => t = ""
}

module TransitionDuration_enum: {
  type t
  let auto: t
} = {
  @unboxed
  type rec t = Any('a): t

  let auto = Any("auto")
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
  external enum: TransitionDuration_enum.t => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

type variant = [#menu | #selectedMenu]

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
  ~anchorOrigin: AnchorOrigin.t=?,
  ~anchorPosition: AnchorPosition.t=?,
  ~anchorReference: anchorReference=?,
  ~className: string=?,
  ~container: Container.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~getContentAnchorEl: MaterialUi_Types.any=?,
  ~marginThreshold: MaterialUi_Types.Number.t=?,
  ~transformOrigin: TransformOrigin.t=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~\"TransitionProps": {..}=?,
  ~anchorEl: MaterialUi_Types.any=?,
  ~autoFocus: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~disableAutoFocusItem: bool=?,
  ~\"MenuListProps": {..}=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool,
  ~\"PaperProps": {..}=?,
  ~\"PopoverClasses": {..}=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Menu"
