type align = [#center | #inherit | #justify | #left | #right]

type padding = [#normal | #checkbox | #none | #default]

type size = [#medium | #small]

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

type variant = [#body | #footer | #head]

module ActionsComponent = {
  type t
  external string: string => t = "%identity"
  external actionsComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "toolbar": option<string>,
    "spacer": option<string>,
    "caption": option<string>,
    "selectRoot": option<string>,
    "select": option<string>,
    "selectIcon": option<string>,
    "input": option<string>,
    "menuItem": option<string>,
    "actions": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~toolbar: string=?,
    ~spacer: string=?,
    ~caption: string=?,
    ~selectRoot: string=?,
    ~select: string=?,
    ~selectIcon: string=?,
    ~input: string=?,
    ~menuItem: string=?,
    ~actions: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~align: align=?,
  ~children: 'children=?,
  ~padding: padding=?,
  ~scope: string=?,
  ~size: size=?,
  ~sortDirection: SortDirection.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~\"ActionsComponent": ActionsComponent.t=?,
  ~backIconButtonProps: {..}=?,
  ~backIconButtonText: string=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~colSpan: Number.t=?,
  ~component: Component.t=?,
  ~count: Number.t,
  ~labelDisplayedRows: {"from": int, "to": int, "count": int} => string=?,
  ~labelRowsPerPage: {"from": int, "to": int, "count": int, "page": int} => React.element=?,
  ~nextIconButtonProps: {..}=?,
  ~nextIconButtonText: string=?,
  ~onPageChange: ({..}, int) => unit,
  ~onRowsPerPageChange: {..} => unit=?,
  ~page: int=?,
  ~rowsPerPage: Number.t,
  ~rowsPerPageOptions: array<int>=?,
  ~\"SelectProps": {..}=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TablePagination"
