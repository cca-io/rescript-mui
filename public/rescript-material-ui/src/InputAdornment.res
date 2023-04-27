type position = [#end | #start]

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

type variant = [#filled | #outlined | #standard]

@react.component @module("@mui/material")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~component: React.element=?,
  ~disablePointerEvents: bool=?,
  ~disableTypography: bool=?,
  ~position: position,
  ~sx: Sx.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "InputAdornment"
