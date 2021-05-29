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

type indicatorColor = [#primary | #secondary]

type orientation = [#horizontal | #vertical]

module ScrollButtonComponent: {
  type t
  let string: string => t
  let scrollButtonComponent_func: MaterialUi_Types.any => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let scrollButtonComponent_func = (v: MaterialUi_Types.any) => Any(v)
  let element = (v: React.element) => Any(v)
}

type scrollButtons = [#auto | #desktop | #off | #on]

type textColor = [#inherit | #primary | #secondary]

type variant = [#fullWidth | #scrollable | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~\"aria-label": string=?,
  ~\"aria-labelledby": string=?,
  ~centered: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~indicatorColor: indicatorColor=?,
  ~onChange: (ReactEvent.Form.t, MaterialUi_Types.any) => unit=?,
  ~orientation: orientation=?,
  ~\"ScrollButtonComponent": ScrollButtonComponent.t=?,
  ~scrollButtons: scrollButtons=?,
  ~selectionFollowsFocus: bool=?,
  ~\"TabIndicatorProps": {..}=?,
  ~\"TabScrollButtonProps": {..}=?,
  ~textColor: textColor=?,
  ~value: MaterialUi_Types.any=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tabs"
