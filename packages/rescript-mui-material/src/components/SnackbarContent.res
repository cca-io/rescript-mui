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
  ~children: React.element=?,
  ~component: React.element=?,
  ~square: bool=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~action: React.element=?,
  ~className: string=?,
  ~message: React.element=?,
  ~role: string=?,
  ~sx: Sx.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SnackbarContent"
