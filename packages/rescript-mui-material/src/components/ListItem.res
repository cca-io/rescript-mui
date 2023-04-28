type alignItems = [#center | #"flex-start"]

module Components = {
  type t = {"Root": option<React.element>}
  @obj external make: (~\"Root": React.element=?, unit) => t = ""
}

module ComponentsProps = {
  type t = {"root": option<Any.t>}
  @obj external make: (~root: Any.t=?, unit) => t = ""
}

module ContainerComponent = {
  type t
  external string: string => t = "%identity"
  external containerComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module SlotProps = {
  type t = {"root": option<Any.t>}
  @obj external make: (~root: Any.t=?, unit) => t = ""
}

module Slots = {
  type t = {"root": option<React.element>}
  @obj external make: (~root: React.element=?, unit) => t = ""
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

module Value = {
  type t
  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external arrayOf: array<string> => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~alignItems: alignItems=?,
  ~autoFocus: bool=?,
  ~button: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~\"ContainerComponent": ContainerComponent.t=?,
  ~\"ContainerProps": {..}=?,
  ~dense: bool=?,
  ~disabled: bool=?,
  ~disableGutters: bool=?,
  ~disablePadding: bool=?,
  ~divider: bool=?,
  ~focusVisibleClassName: string=?,
  ~secondaryAction: React.element=?,
  ~selected: bool=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~value: Value.t=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ListItem"
