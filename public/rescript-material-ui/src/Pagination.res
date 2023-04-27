type color_enum = [#primary | #secondary | #standard]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

type color = [#primary | #secondary | #standard]

type shape = [#round | #rounded]

type size = [#large | #medium | #small]

type variant = [#outlined | #text]

type shape = [#circular | #rounded]

type size_enum = [#small | #medium | #large]

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

type variant_enum = [#outlined | #text]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~className: string=?,
  ~color: Color.t=?,
  ~disabled: bool=?,
  ~getItemAriaLabel: (string, int, bool) => string=?,
  ~hideNextButton: bool=?,
  ~hidePrevButton: bool=?,
  ~onChange: (ReactEvent.Form.t, int) => unit=?,
  ~renderItem: {
    "color": color,
    "shape": shape,
    "size": size,
    "variant": variant,
    "page": int,
    "selected": bool,
    "disabled": bool,
  } => React.element=?,
  ~shape: shape=?,
  ~showFirstButton: bool=?,
  ~showLastButton: bool=?,
  ~size: Size.t=?,
  ~sx: Sx.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Pagination"
