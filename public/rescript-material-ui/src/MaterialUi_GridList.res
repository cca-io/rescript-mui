module CellHeight_enum: {
  type t
  let auto: t
} = {
  @unboxed
  type rec t = Any('a): t

  let auto = Any("auto")
}

module CellHeight = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external enum: CellHeight_enum.t => t = "%identity"
}

module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~cellHeight: CellHeight.t=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~cols: MaterialUi_Types.Number.t=?,
  ~component: Component.t=?,
  ~spacing: MaterialUi_Types.Number.t=?,
  ~style: ReactDOM.Style.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "GridList"
