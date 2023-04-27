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

module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external container_func: Any.t => t = "%identity"
}

module SlotProps = {
  type t = {"backdrop": option<Backdrop.t>, "root": option<Root.t>}
  @obj external make: (~backdrop: Backdrop.t=?, ~root: Root.t=?, unit) => t = ""
}

module Slots = {
  type t = {"backdrop": option<React.element>, "root": option<React.element>}
  @obj external make: (~backdrop: React.element=?, ~root: React.element=?, unit) => t = ""
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

@react.component @module("@mui/material")
external make: (
  ~\"BackdropComponent": React.element=?,
  ~\"BackdropProps": {..}=?,
  ~children: React.element=?,
  ~closeAfterTransition: bool=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~container: Container.t=?,
  ~disableAutoFocus: bool=?,
  ~disableEnforceFocus: bool=?,
  ~disableEscapeKeyDown: bool=?,
  ~disablePortal: bool=?,
  ~disableRestoreFocus: bool=?,
  ~disableScrollLock: bool=?,
  ~hideBackdrop: bool=?,
  ~keepMounted: bool=?,
  ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~\"open": bool,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Modal"
