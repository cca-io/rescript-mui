type horizontal = [#left | #right]

type vertical = [#bottom | #top]

module AnchorOrigin = {
  type t = {"horizontal": option<horizontal>, "vertical": option<vertical>}
  @obj external make: (~horizontal: horizontal=?, ~vertical: vertical=?, unit) => t = ""
}

type color = [#default | #error | #primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type overlap = [#circle | #rectangle | #circular | #rectangular]

type variant = [#dot | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~anchorOrigin: AnchorOrigin.t=?,
  ~badgeContent: React.element=?,
  ~children: 'children=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~invisible: bool=?,
  ~max: Number.t=?,
  ~overlap: overlap=?,
  ~showZero: bool=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Badge"
