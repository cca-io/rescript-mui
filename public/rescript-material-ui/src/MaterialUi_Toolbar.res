module Classes = {
  type t = {
    "root": option<string>,
    "gutters": option<string>,
    "regular": option<string>,
    "dense": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~gutters: string=?,
    ~regular: string=?,
    ~dense: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type variant = [#regular | #dense]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~disableGutters: bool=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Toolbar"
