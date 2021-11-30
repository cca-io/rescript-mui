module Classes = {
  type t = {
    "root": option<string>,
    "contained": option<string>,
    "disableElevation": option<string>,
    "disabled": option<string>,
    "fullWidth": option<string>,
    "vertical": option<string>,
    "grouped": option<string>,
    "groupedHorizontal": option<string>,
    "groupedVertical": option<string>,
    "groupedText": option<string>,
    "groupedTextHorizontal": option<string>,
    "groupedTextVertical": option<string>,
    "groupedTextPrimary": option<string>,
    "groupedTextSecondary": option<string>,
    "groupedOutlined": option<string>,
    "groupedOutlinedHorizontal": option<string>,
    "groupedOutlinedVertical": option<string>,
    "groupedOutlinedPrimary": option<string>,
    "groupedOutlinedSecondary": option<string>,
    "groupedContained": option<string>,
    "groupedContainedHorizontal": option<string>,
    "groupedContainedVertical": option<string>,
    "groupedContainedPrimary": option<string>,
    "groupedContainedSecondary": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~contained: string=?,
    ~disableElevation: string=?,
    ~disabled: string=?,
    ~fullWidth: string=?,
    ~vertical: string=?,
    ~grouped: string=?,
    ~groupedHorizontal: string=?,
    ~groupedVertical: string=?,
    ~groupedText: string=?,
    ~groupedTextHorizontal: string=?,
    ~groupedTextVertical: string=?,
    ~groupedTextPrimary: string=?,
    ~groupedTextSecondary: string=?,
    ~groupedOutlined: string=?,
    ~groupedOutlinedHorizontal: string=?,
    ~groupedOutlinedVertical: string=?,
    ~groupedOutlinedPrimary: string=?,
    ~groupedOutlinedSecondary: string=?,
    ~groupedContained: string=?,
    ~groupedContainedHorizontal: string=?,
    ~groupedContainedVertical: string=?,
    ~groupedContainedPrimary: string=?,
    ~groupedContainedSecondary: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #inherit | #primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type orientation = [#horizontal | #vertical]

type size = [#large | #medium | #small]

type variant = [#contained | #outlined | #text]

@react.component @module("@material-ui/core")
external make: (
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~disabled: bool=?,
  ~disableElevation: bool=?,
  ~disableFocusRipple: bool=?,
  ~disableRipple: bool=?,
  ~fullWidth: bool=?,
  ~orientation: orientation=?,
  ~size: size=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ButtonGroup"
