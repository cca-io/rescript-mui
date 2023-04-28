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
  ~action: React.element=?,
  ~avatar: React.element=?,
  ~children: React.element=?,
  ~className: string=?,
  ~component: React.element=?,
  ~disableTypography: bool=?,
  ~subheader: React.element=?,
  ~subheaderTypographyProps: {..}=?,
  ~sx: Sx.t=?,
  ~title: React.element=?,
  ~titleTypographyProps: {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "CardHeader"
