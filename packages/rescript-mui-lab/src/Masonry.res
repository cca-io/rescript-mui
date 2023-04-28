module Columns_arrayOf = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module Columns = {
  type t
  external arrayOf: array<Columns_arrayOf.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external obj: {..} => t = "%identity"
  external string: string => t = "%identity"
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
  ~columns: Columns.t=?,
  ~component: React.element=?,
  ~defaultColumns: Mui.Number.t=?,
  ~defaultHeight: Mui.Number.t=?,
  ~defaultSpacing: Mui.Number.t=?,
  ~spacing: Spacing.t=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Masonry"
