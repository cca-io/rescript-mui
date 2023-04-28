type align = [#center | #inherit | #justify | #left | #right]

type padding = [#checkbox | #none | #normal]

type size_enum = [#medium | #small]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

module SortDirection: {
  type t
  let asc: t
  let desc: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let asc = Any("asc")
  let desc = Any("desc")
  let \"false" = Any(false)
}

type variant_enum = [#body | #footer | #head]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Event = {
  type t
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
  ~align: align=?,
  ~children: React.element=?,
  ~padding: padding=?,
  ~scope: string=?,
  ~size: Size.t=?,
  ~sortDirection: SortDirection.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~\"ActionsComponent": React.element=?,
  ~backIconButtonProps: {..}=?,
  ~className: string=?,
  ~colSpan: Number.t=?,
  ~component: React.element=?,
  ~getItemAriaLabel: string => string=?,
  ~labelDisplayedRows: {"from": int, "to": int, "count": int} => string=?,
  ~labelRowsPerPage: {"from": int, "to": int, "count": int, "page": int} => React.element=?,
  ~nextIconButtonProps: {..}=?,
  ~onPageChange: (Event.t, int) => unit,
  ~onRowsPerPageChange: {..} => unit=?,
  ~page: int=?,
  ~rowsPerPageOptions: array<int>=?,
  ~\"SelectProps": {..}=?,
  ~showFirstButton: bool=?,
  ~showLastButton: bool=?,
  ~sx: Sx.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TablePagination"
