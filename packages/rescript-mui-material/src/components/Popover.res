module Components = {
  type t = {"Backdrop": option<React.element>, "Root": option<React.element>}
  @obj external make: (~\"Backdrop": React.element=?, ~\"Root": React.element=?, unit) => t = ""
}

module Backdrop = {
  type t
  external backdrop_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Root = {
  type t
  external root_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module ComponentsProps = {
  type t = {"backdrop": option<Backdrop.t>, "root": option<Root.t>}
  @obj external make: (~backdrop: Backdrop.t=?, ~root: Root.t=?, unit) => t = ""
}

module SlotProps = {
  type t = {"backdrop": option<Backdrop.t>, "root": option<Root.t>}
  @obj external make: (~backdrop: Backdrop.t=?, ~root: Root.t=?, unit) => t = ""
}

module Slots = {
  type t = {"backdrop": option<React.element>, "root": option<React.element>}
  @obj external make: (~backdrop: React.element=?, ~root: React.element=?, unit) => t = ""
}

module AnchorEl = {
  type t
  external obj: {..} => t = "%identity"
  external anchorEl_func: Any.t => t = "%identity"
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
  external container_func: Any.t => t = "%identity"
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

module TransformOrigin = {
  type t = {"horizontal": option<Horizontal.t>, "vertical": option<Vertical.t>}
  @obj external make: (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t = ""
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

@react.component @module("@mui/material")
external make: (
  ~\"BackdropComponent": React.element=?,
  ~\"BackdropProps": {..}=?,
  ~closeAfterTransition: bool=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~disableAutoFocus: bool=?,
  ~disableEnforceFocus: bool=?,
  ~disableEscapeKeyDown: bool=?,
  ~disablePortal: bool=?,
  ~disableRestoreFocus: bool=?,
  ~disableScrollLock: bool=?,
  ~hideBackdrop: bool=?,
  ~keepMounted: bool=?,
  ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~anchorEl: AnchorEl.t=?,
  ~anchorOrigin: AnchorOrigin.t=?,
  ~anchorPosition: AnchorPosition.t=?,
  ~anchorReference: anchorReference=?,
  ~children: React.element=?,
  ~className: string=?,
  ~container: Container.t=?,
  ~marginThreshold: Number.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool,
  ~\"PaperProps": PaperProps.t=?,
  ~sx: Sx.t=?,
  ~transformOrigin: TransformOrigin.t=?,
  ~\"TransitionComponent": React.element=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Popover"
