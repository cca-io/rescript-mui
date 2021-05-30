type align = [#inherit | #left | #center | #right | #justify]

type color = [#initial | #inherit | #primary | #secondary | #textPrimary | #textSecondary | #error]

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

type display = [#initial | #block | #inline]

type variant = [
  | #h1
  | #h2
  | #h3
  | #h4
  | #h5
  | #h6
  | #subtitle1
  | #subtitle2
  | #body1
  | #body2
  | #caption
  | #button
  | #overline
  | #srOnly
  | #inherit
]

module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~align: align=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~display: display=?,
  ~gutterBottom: bool=?,
  ~noWrap: bool=?,
  ~paragraph: bool=?,
  ~variant: variant=?,
  ~variantMapping: {..}=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "DialogContentText"
