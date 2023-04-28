type horizontal = [#left | #right]

type vertical = [#bottom | #top]

module AnchorOrigin = {
  type t = {"horizontal": option<horizontal>, "vertical": option<vertical>}
  @obj external make: (~horizontal: horizontal=?, ~vertical: vertical=?, unit) => t = ""
}

type color_enum = [#default | #primary | #secondary | #error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Components = {
  type t = {"Badge": option<React.element>, "Root": option<React.element>}
  @obj external make: (~\"Badge": React.element=?, ~\"Root": React.element=?, unit) => t = ""
}

module Badge = {
  type t
  external badge_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Root = {
  type t
  external root_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module ComponentsProps = {
  type t = {"badge": option<Badge.t>, "root": option<Root.t>}
  @obj external make: (~badge: Badge.t=?, ~root: Root.t=?, unit) => t = ""
}

type overlap = [#circular | #rectangular]

module SlotProps = {
  type t = {"badge": option<Badge.t>, "root": option<Root.t>}
  @obj external make: (~badge: Badge.t=?, ~root: Root.t=?, unit) => t = ""
}

module Slots = {
  type t = {"badge": option<React.element>, "root": option<React.element>}
  @obj external make: (~badge: React.element=?, ~root: React.element=?, unit) => t = ""
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

type variant_enum = [#dot | #standard]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~anchorOrigin: AnchorOrigin.t=?,
  ~badgeContent: React.element=?,
  ~children: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~invisible: bool=?,
  ~max: Number.t=?,
  ~overlap: overlap=?,
  ~showZero: bool=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Badge"
