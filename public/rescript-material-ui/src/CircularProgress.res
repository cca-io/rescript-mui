type color_enum = [#inherit | #primary | #secondary | #error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Size = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
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

type variant = [#determinate | #indeterminate]

@react.component @module("@mui/material")
external make: (
  ~className: string=?,
  ~color: Color.t=?,
  ~disableShrink: bool=?,
  ~size: Size.t=?,
  ~style: ReactDOM.Style.t=?,
  ~sx: Sx.t=?,
  ~thickness: Number.t=?,
  ~value: Number.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "CircularProgress"
