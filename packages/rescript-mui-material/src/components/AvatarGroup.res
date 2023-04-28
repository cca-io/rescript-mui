module ComponentsProps = {
  type t = {"additionalAvatar": option<Any.t>}
  @obj external make: (~additionalAvatar: Any.t=?, unit) => t = ""
}

module SlotProps = {
  type t = {"additionalAvatar": option<Any.t>}
  @obj external make: (~additionalAvatar: Any.t=?, unit) => t = ""
}

type spacing_enum = [#medium | #small]

module Spacing = {
  type t
  external enum: spacing_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
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

type variant_enum = [#circular | #rounded | #square]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~component: React.element=?,
  ~componentsProps: ComponentsProps.t=?,
  ~max: Number.t=?,
  ~slotProps: SlotProps.t=?,
  ~spacing: Spacing.t=?,
  ~sx: Sx.t=?,
  ~total: Number.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "AvatarGroup"
