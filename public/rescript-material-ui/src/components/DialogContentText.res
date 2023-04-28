type align = [#center | #inherit | #justify | #left | #right]

type variant_enum = [
  | #body1
  | #body2
  | #button
  | #caption
  | #h1
  | #h2
  | #h3
  | #h4
  | #h5
  | #h6
  | #inherit
  | #overline
  | #subtitle1
  | #subtitle2
]

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
  ~align: align=?,
  ~component: React.element=?,
  ~gutterBottom: bool=?,
  ~noWrap: bool=?,
  ~paragraph: bool=?,
  ~variant: Variant.t=?,
  ~variantMapping: {..}=?,
  ~children: React.element=?,
  ~className: string=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "DialogContentText"
