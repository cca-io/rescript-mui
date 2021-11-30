module Classes = {
  type t = {
    "root": option<string>,
    "vertical": option<string>,
    "flexContainer": option<string>,
    "flexContainerVertical": option<string>,
    "centered": option<string>,
    "scroller": option<string>,
    "fixed": option<string>,
    "scrollable": option<string>,
    "scrollButtons": option<string>,
    "scrollButtonsDesktop": option<string>,
    "indicator": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~vertical: string=?,
    ~flexContainer: string=?,
    ~flexContainerVertical: string=?,
    ~centered: string=?,
    ~scroller: string=?,
    ~fixed: string=?,
    ~scrollable: string=?,
    ~scrollButtons: string=?,
    ~scrollButtonsDesktop: string=?,
    ~indicator: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type indicatorColor = [#primary | #secondary]

type orientation = [#horizontal | #vertical]

module ScrollButtonComponent = {
  type t
  external string: string => t = "%identity"
  external scrollButtonComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

type scrollButtons = [#auto | #desktop | #off | #on]

type textColor = [#inherit | #primary | #secondary]

type variant = [#fullWidth | #scrollable | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~\"aria-label": string=?,
  ~\"aria-labelledby": string=?,
  ~centered: bool=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~indicatorColor: indicatorColor=?,
  ~onChange: (ReactEvent.Form.t, Any.t) => unit=?,
  ~orientation: orientation=?,
  ~\"ScrollButtonComponent": ScrollButtonComponent.t=?,
  ~scrollButtons: scrollButtons=?,
  ~selectionFollowsFocus: bool=?,
  ~\"TabIndicatorProps": {..}=?,
  ~\"TabScrollButtonProps": {..}=?,
  ~textColor: textColor=?,
  ~value: Any.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tabs"
