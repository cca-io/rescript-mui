type variant_enum = [#elevation | #outlined]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
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
  ~component: React.element=?,
  ~variant: Variant.t=?,
  ~children: React.element=?,
  ~className: string=?,
  ~defaultExpanded: bool=?,
  ~disabled: bool=?,
  ~disableGutters: bool=?,
  ~expanded: bool=?,
  ~onChange: (ReactEvent.Form.t, bool) => unit=?,
  ~square: bool=?,
  ~sx: Sx.t=?,
  ~\"TransitionComponent": React.element=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Accordion"
