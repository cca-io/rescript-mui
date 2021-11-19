type horizontal = [#left | #right]

type vertical = [#bottom | #top]

module AnchorOrigin = {
  type t = {"horizontal": option<horizontal>, "vertical": option<vertical>}
  @obj external make: (~horizontal: horizontal=?, ~vertical: vertical=?, unit) => t = ""
}

module Classes = {
  type t = {
    "root": option<string>,
    "badge": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "colorError": option<string>,
    "dot": option<string>,
    "anchorOriginTopRightRectangle": option<string>,
    "anchorOriginBottomRightRectangle": option<string>,
    "anchorOriginTopLeftRectangle": option<string>,
    "anchorOriginBottomLeftRectangle": option<string>,
    "anchorOriginTopRightCircle": option<string>,
    "anchorOriginBottomRightCircle": option<string>,
    "anchorOriginTopLeftCircle": option<string>,
    "anchorOriginBottomLeftCircle": option<string>,
    "invisible": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~badge: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~colorError: string=?,
    ~dot: string=?,
    ~anchorOriginTopRightRectangle: string=?,
    ~anchorOriginBottomRightRectangle: string=?,
    ~anchorOriginTopLeftRectangle: string=?,
    ~anchorOriginBottomLeftRectangle: string=?,
    ~anchorOriginTopRightCircle: string=?,
    ~anchorOriginBottomRightCircle: string=?,
    ~anchorOriginTopLeftCircle: string=?,
    ~anchorOriginBottomLeftCircle: string=?,
    ~invisible: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #error | #primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type overlap = [#circle | #rectangle]

type variant = [#dot | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~anchorOrigin: AnchorOrigin.t=?,
  ~badgeContent: React.element=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
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
