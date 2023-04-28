module ComponentsProps = {
  type t = {"label": option<Any.t>}
  @obj external make: (~label: Any.t=?, unit) => t = ""
}

module SlotProps = {
  type t = {"label": option<Any.t>}
  @obj external make: (~label: Any.t=?, unit) => t = ""
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
  ~children: React.element=?,
  ~className: string=?,
  ~componentsProps: ComponentsProps.t=?,
  ~error: bool=?,
  ~icon: React.element=?,
  ~optional: React.element=?,
  ~slotProps: SlotProps.t=?,
  ~\"StepIconComponent": React.element=?,
  ~\"StepIconProps": {..}=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "StepLabel"
