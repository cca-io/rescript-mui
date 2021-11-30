module Classes = {
  type t = {
    "root": option<string>,
    "colorPrimary": option<string>,
    "colorInherit": option<string>,
    "gutters": option<string>,
    "inset": option<string>,
    "sticky": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~colorPrimary: string=?,
    ~colorInherit: string=?,
    ~gutters: string=?,
    ~inset: string=?,
    ~sticky: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #primary | #inherit]

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
  ~color: color=?,
  ~component: Component.t=?,
  ~disableGutters: bool=?,
  ~disableSticky: bool=?,
  ~inset: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ListSubheader"
