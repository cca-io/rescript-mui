type align = [#center | #inherit | #justify | #left | #right]

module Classes = {
  type t = {
    "root": option<string>,
    "head": option<string>,
    "body": option<string>,
    "footer": option<string>,
    "sizeSmall": option<string>,
    "paddingCheckbox": option<string>,
    "paddingNone": option<string>,
    "alignLeft": option<string>,
    "alignCenter": option<string>,
    "alignRight": option<string>,
    "alignJustify": option<string>,
    "stickyHeader": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~head: string=?,
    ~body: string=?,
    ~footer: string=?,
    ~sizeSmall: string=?,
    ~paddingCheckbox: string=?,
    ~paddingNone: string=?,
    ~alignLeft: string=?,
    ~alignCenter: string=?,
    ~alignRight: string=?,
    ~alignJustify: string=?,
    ~stickyHeader: string=?,
    unit,
  ) => t = ""
}

module Component: {
  type t
  let string: string => t
  let callback: (unit => React.element) => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let callback = (v: unit => React.element) => Any(v)
  let element = (v: React.element) => Any(v)
}

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

@react.component @module("@material-ui/core")
external make: (
  ~align: align=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~padding: padding=?,
  ~scope: string=?,
  ~size: size=?,
  ~sortDirection: SortDirection.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~colSpan: int=?,
  ~rowSpan: int=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TableCell"
