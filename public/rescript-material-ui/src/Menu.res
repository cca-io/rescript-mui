module BackdropComponent = {
  type t
  external string: string => t = "%identity"
  external backdropComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
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
  type t = {"left": option<Number.t>, "top": option<Number.t>}
  @obj external make: (~left: Number.t=?, ~top: Number.t=?, unit) => t = ""
}

type anchorReference = [#anchorEl | #anchorPosition | #none]

module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external element: React.element => t = "%identity"
  external container_func: Any.t => t = "%identity"
}

module TransformOrigin = {
  type t = {"horizontal": option<Horizontal.t>, "vertical": option<Vertical.t>}
  @obj external make: (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t = ""
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module Classes = {
  type t = {"paper": option<string>, "list": option<string>}
  @obj external make: (~paper: string=?, ~list: string=?, unit) => t = ""
}

type transitionDuration_enum = [#auto]

module TransitionDuration_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module TransitionDuration = {
  type t
  external enum: transitionDuration_enum => t = "%identity"
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
  ~anchorOrigin: AnchorOrigin.t=?,
  ~anchorPosition: AnchorPosition.t=?,
  ~anchorReference: anchorReference=?,
  ~className: string=?,
  ~container: Container.t=?,
  ~elevation: Number.t=?,
  ~getContentAnchorEl: Any.t=?,
  ~marginThreshold: Number.t=?,
  ~transformOrigin: TransformOrigin.t=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~anchorEl: Any.t=?,
  ~autoFocus: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~disableAutoFocusItem: bool=?,
  ~\"MenuListProps": {..}=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~\"open": bool,
  ~\"PaperProps": {..}=?,
  ~\"PopoverClasses": {..}=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Menu"
