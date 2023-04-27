type color_enum = [#inherit | #primary | #secondary]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
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

type variant = [#buffer | #determinate | #indeterminate | #query]

@react.component @module("@mui/material")
external make: (
  ~className: string=?,
  ~color: Color.t=?,
  ~sx: Sx.t=?,
  ~value: Number.t=?,
  ~valueBuffer: Number.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "LinearProgress"
