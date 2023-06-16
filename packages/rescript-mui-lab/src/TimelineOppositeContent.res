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

@react.component @module("@mui/lab")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TimelineOppositeContent"
