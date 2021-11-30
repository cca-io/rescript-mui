module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type variant = [#elevation | #outlined]

module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~elevation: Number.t=?,
  ~square: bool=?,
  ~variant: variant=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~raised: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Card"
