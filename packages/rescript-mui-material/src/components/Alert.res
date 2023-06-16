type color_enum = [#error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Components = {
  type t = {"CloseButton": option<React.element>, "CloseIcon": option<React.element>}
  @obj
  external make: (~\"CloseButton": React.element=?, ~\"CloseIcon": React.element=?, unit) => t = ""
}

module ComponentsProps = {
  type t = {"closeButton": option<Any.t>, "closeIcon": option<Any.t>}
  @obj external make: (~closeButton: Any.t=?, ~closeIcon: Any.t=?, unit) => t = ""
}

module IconMapping = {
  type t = {
    "error": option<React.element>,
    "info": option<React.element>,
    "success": option<React.element>,
    "warning": option<React.element>,
  }
  @obj
  external make: (
    ~error: React.element=?,
    ~info: React.element=?,
    ~success: React.element=?,
    ~warning: React.element=?,
    unit,
  ) => t = ""
}

type severity = [#error | #info | #success | #warning]

module SlotProps = {
  type t = {"closeButton": option<Any.t>, "closeIcon": option<Any.t>}
  @obj external make: (~closeButton: Any.t=?, ~closeIcon: Any.t=?, unit) => t = ""
}

module Slots = {
  type t = {"closeButton": option<React.element>, "closeIcon": option<React.element>}
  @obj external make: (~closeButton: React.element=?, ~closeIcon: React.element=?, unit) => t = ""
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

type variant_enum = [#filled | #outlined | #standard]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~component: React.element=?,
  ~square: bool=?,
  ~action: React.element=?,
  ~children: React.element=?,
  ~className: string=?,
  ~closeText: string=?,
  ~color: Color.t=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~icon: React.element=?,
  ~iconMapping: IconMapping.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~role: string=?,
  ~severity: severity=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Alert"
