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
