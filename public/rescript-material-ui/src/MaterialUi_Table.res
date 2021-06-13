module Classes = {
  type t = {"root": option<string>, "stickyHeader": option<string>}
  @obj external make: (~root: string=?, ~stickyHeader: string=?, unit) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type padding = [#default | #checkbox | #none]

type size = [#small | #medium]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~padding: padding=?,
  ~size: size=?,
  ~stickyHeader: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Table"
