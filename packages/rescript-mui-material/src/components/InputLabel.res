type color_enum = [#error | #info | #primary | #secondary | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

type margin = [#dense]

type size_enum = [#normal | #small]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
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

type variant = [#filled | #outlined | #standard]

@react.component @module("@mui/material")
external make: (
  ~component: React.element=?,
  ~filled: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~children: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~disableAnimation: bool=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~focused: bool=?,
  ~margin: margin=?,
  ~required: bool=?,
  ~shrink: bool=?,
  ~size: Size.t=?,
  ~sx: Sx.t=?,
  ~variant: variant=?,
  ~htmlFor: string,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "InputLabel"
