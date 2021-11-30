type align = [#inherit | #left | #center | #right | #justify]

type color = [#initial | #inherit | #primary | #secondary | #textPrimary | #textSecondary | #error]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
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
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "DialogContentText"
