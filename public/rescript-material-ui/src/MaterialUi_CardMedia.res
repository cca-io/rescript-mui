module Classes = {
  type t = {"root": option<string>, "media": option<string>, "img": option<string>}
  @obj external make: (~root: string=?, ~media: string=?, ~img: string=?, unit) => t = ""
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
  ~image: string=?,
  ~src: string=?,
  ~style: ReactDOM.Style.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "CardMedia"
