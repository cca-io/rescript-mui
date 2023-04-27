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
  ~component: React.element=?,
  ~hover: bool=?,
  ~selected: bool=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TableRow"
