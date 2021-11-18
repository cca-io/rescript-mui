module Classes = {
  type t = {
    "root": option<string>,
    "padding": option<string>,
    "dense": option<string>,
    "subheader": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~padding: string=?,
    ~dense: string=?,
    ~subheader: string=?,
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
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~dense: bool=?,
  ~disablePadding: bool=?,
  ~subheader: React.element=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "List"
