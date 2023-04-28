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

module TransformOrigin = {
  type t = {"horizontal": option<Horizontal.t>, "vertical": option<Vertical.t>}
  @obj external make: (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t = ""
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
  ~anchorOrigin: AnchorOrigin.t=?,
  ~anchorPosition: AnchorPosition.t=?,
  ~anchorReference: anchorReference=?,
  ~className: string=?,
  ~container: Container.t=?,
  ~marginThreshold: Number.t=?,
  ~transformOrigin: TransformOrigin.t=?,
  ~\"TransitionComponent": React.element=?,
  ~anchorEl: Any.t=?,
  ~autoFocus: bool=?,
  ~children: React.element=?,
  ~disableAutoFocusItem: bool=?,
  ~\"MenuListProps": {..}=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~\"open": bool,
  ~\"PaperProps": {..}=?,
  ~\"PopoverClasses": {..}=?,
  ~sx: Sx.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Menu"
