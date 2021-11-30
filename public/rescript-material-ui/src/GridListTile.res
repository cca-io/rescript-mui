module Classes = {
  type t = {
    "root": option<string>,
    "tile": option<string>,
    "imgFullHeight": option<string>,
    "imgFullWidth": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~tile: string=?,
    ~imgFullHeight: string=?,
    ~imgFullWidth: string=?,
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
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~cols: Number.t=?,
  ~component: Component.t=?,
  ~rows: Number.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "GridListTile"
