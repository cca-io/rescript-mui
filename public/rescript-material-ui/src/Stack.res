type direction_enum = [#"column-reverse" | #column | #"row-reverse" | #row]

type direction_arrayOf = [#"column-reverse" | #column | #"row-reverse" | #row]

module Direction = {
  type t
  external enum: direction_enum => t = "%identity"
  external arrayOf: array<direction_arrayOf> => t = "%identity"
  external obj: {..} => t = "%identity"
}

module Spacing_arrayOf = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module Spacing = {
  type t
  external arrayOf: array<Spacing_arrayOf.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external obj: {..} => t = "%identity"
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
  ~direction: Direction.t=?,
  ~divider: React.element=?,
  ~spacing: Spacing.t=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Stack"
