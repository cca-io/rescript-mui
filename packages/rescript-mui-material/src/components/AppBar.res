type variant_enum = [#elevation | #outlined]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

type color_enum = [#default | #inherit | #primary | #secondary | #transparent]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

type position = [#absolute | #fixed | #relative | #static | #sticky]

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
  ~square: bool=?,
  ~variant: Variant.t=?,
  ~children: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~enableColorOnDark: bool=?,
  ~position: position=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "AppBar"
