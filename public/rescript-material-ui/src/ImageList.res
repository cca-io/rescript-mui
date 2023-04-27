type rowHeight_enum = [#auto]

module RowHeight = {
  type t
  external enum: rowHeight_enum => t = "%identity"
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

type variant_enum = [#masonry | #quilted | #standard | #woven]

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
  ~gap: Number.t=?,
  ~rowHeight: RowHeight.t=?,
  ~style: ReactDOM.Style.t=?,
  ~sx: Sx.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ImageList"
