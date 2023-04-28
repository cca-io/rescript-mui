type color_enum = [
  | #inherit
  | #action
  | #disabled
  | #primary
  | #secondary
  | #error
  | #info
  | #success
  | #warning
]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

type fontSize_enum = [#inherit | #large | #medium | #small]

module FontSize = {
  type t
  external enum: fontSize_enum => t = "%identity"
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
  ~className: string=?,
  ~color: Color.t=?,
  ~component: React.element=?,
  ~fontSize: FontSize.t=?,
  ~htmlColor: string=?,
  ~inheritViewBox: bool=?,
  ~shapeRendering: string=?,
  ~sx: Sx.t=?,
  ~titleAccess: string=?,
  ~viewBox: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SvgIcon"
