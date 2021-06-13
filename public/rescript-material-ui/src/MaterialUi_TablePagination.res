type align = [#center | #inherit | #justify | #left | #right]

type padding = [#checkbox | #default | #none]

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
  external actionsComponent_func: MaterialUi_Types.any => t = "%identity"
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
  ~colSpan: MaterialUi_Types.Number.t=?,
  ~component: Component.t=?,
  ~count: MaterialUi_Types.Number.t,
  ~labelDisplayedRows: {"from": int, "to": int, "count": int} => string=?,
  ~labelRowsPerPage: {"from": int, "to": int, "count": int, "page": int} => React.element=?,
  ~nextIconButtonProps: {..}=?,
  ~nextIconButtonText: string=?,
  ~onChangePage: (ReactEvent.Mouse.t, int) => unit,
  ~onChangeRowsPerPage: ReactEvent.Form.t => unit=?,
  ~page: int=?,
  ~rowsPerPage: MaterialUi_Types.Number.t,
  ~rowsPerPageOptions: array<int>=?,
  ~\"SelectProps": {..}=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TablePagination"
