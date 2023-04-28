module Columns = {
  type t
  external arrayOf: array<Number.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external obj: {..} => t = "%identity"
}

module ColumnSpacing_arrayOf = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module ColumnSpacing = {
  type t
  external arrayOf: array<ColumnSpacing_arrayOf.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external obj: {..} => t = "%identity"
  external string: string => t = "%identity"
}

type direction_enum = [#"column-reverse" | #column | #"row-reverse" | #row]

type direction_arrayOf = [#"column-reverse" | #column | #"row-reverse" | #row]

module Direction = {
  type t
  external enum: direction_enum => t = "%identity"
  external arrayOf: array<direction_arrayOf> => t = "%identity"
  external obj: {..} => t = "%identity"
}

type lg_enum = [#auto]

module Lg = {
  type t
  external enum: lg_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external bool: bool => t = "%identity"
}

type md_enum = [#auto]

module Md = {
  type t
  external enum: md_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external bool: bool => t = "%identity"
}

module RowSpacing_arrayOf = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module RowSpacing = {
  type t
  external arrayOf: array<RowSpacing_arrayOf.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external obj: {..} => t = "%identity"
  external string: string => t = "%identity"
}

type sm_enum = [#auto]

module Sm = {
  type t
  external enum: sm_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external bool: bool => t = "%identity"
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

type wrap = [#nowrap | #"wrap-reverse" | #wrap]

type xl_enum = [#auto]

module Xl = {
  type t
  external enum: xl_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external bool: bool => t = "%identity"
}

type xs_enum = [#auto]

module Xs = {
  type t
  external enum: xs_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external bool: bool => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~columns: Columns.t=?,
  ~columnSpacing: ColumnSpacing.t=?,
  ~component: React.element=?,
  ~container: bool=?,
  ~direction: Direction.t=?,
  ~item: bool=?,
  ~lg: Lg.t=?,
  ~md: Md.t=?,
  ~rowSpacing: RowSpacing.t=?,
  ~sm: Sm.t=?,
  ~spacing: Spacing.t=?,
  ~sx: Sx.t=?,
  ~wrap: wrap=?,
  ~xl: Xl.t=?,
  ~xs: Xs.t=?,
  ~zeroMinWidth: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Grid"
