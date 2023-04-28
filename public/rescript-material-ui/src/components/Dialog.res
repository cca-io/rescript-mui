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

module MaxWidth_enum: {
  type t
  let xs: t
  let sm: t
  let md: t
  let lg: t
  let xl: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let xs = Any("xs")
  let sm = Any("sm")
  let md = Any("md")
  let lg = Any("lg")
  let xl = Any("xl")
  let \"false" = Any(false)
}

module MaxWidth = {
  type t
  external enum: MaxWidth_enum.t => t = "%identity"
  external string: string => t = "%identity"
}

type scroll = [#body | #paper]

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

module TransitionDuration_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module TransitionDuration = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~closeAfterTransition: bool=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~container: Container.t=?,
  ~disableAutoFocus: bool=?,
  ~disableEnforceFocus: bool=?,
  ~disablePortal: bool=?,
  ~disableRestoreFocus: bool=?,
  ~disableScrollLock: bool=?,
  ~hideBackdrop: bool=?,
  ~keepMounted: bool=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~\"aria-describedby": string=?,
  ~\"aria-labelledby": string=?,
  ~\"BackdropComponent": React.element=?,
  ~\"BackdropProps": {..}=?,
  ~children: React.element=?,
  ~className: string=?,
  ~disableEscapeKeyDown: bool=?,
  ~fullScreen: bool=?,
  ~fullWidth: bool=?,
  ~maxWidth: MaxWidth.t=?,
  ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~\"open": bool,
  ~\"PaperComponent": React.element=?,
  ~\"PaperProps": {..}=?,
  ~scroll: scroll=?,
  ~sx: Sx.t=?,
  ~\"TransitionComponent": React.element=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Dialog"
