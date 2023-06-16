type color_enum = [#error | #grey | #info | #inherit | #primary | #secondary | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

type variant_enum = [#filled | #outlined]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/lab")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~sx: Sx.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TimelineDot"
