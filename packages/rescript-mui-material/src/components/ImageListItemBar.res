type actionPosition = [#left | #right]

type position = [#below | #bottom | #top]

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
  ~actionIcon: React.element=?,
  ~actionPosition: actionPosition=?,
  ~children: React.element=?,
  ~className: string=?,
  ~position: position=?,
  ~subtitle: React.element=?,
  ~sx: Sx.t=?,
  ~title: React.element=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ImageListItemBar"
