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
