type cellHeight = [#auto]

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

type rowHeight_enum = [#auto]

module RowHeight = {
  type t
  external enum: rowHeight_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~cellHeight: cellHeight=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~cols: Number.t=?,
  ~component: Component.t=?,
  ~gap: Number.t=?,
  ~rowHeight: RowHeight.t=?,
  ~spacing: Number.t=?,
  ~style: ReactDOM.Style.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ImageList"
