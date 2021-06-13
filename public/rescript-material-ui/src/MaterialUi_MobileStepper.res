module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "positionBottom": option<string>,
    "positionTop": option<string>,
    "positionStatic": option<string>,
    "dots": option<string>,
    "dot": option<string>,
    "dotActive": option<string>,
    "progress": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~positionBottom: string=?,
    ~positionTop: string=?,
    ~positionStatic: string=?,
    ~dots: string=?,
    ~dot: string=?,
    ~dotActive: string=?,
    ~progress: string=?,
    unit,
  ) => t = ""
}

type position = [#bottom | #static | #top]

type variant = [#dots | #progress | #text]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~component: Component.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~square: bool=?,
  ~activeStep: MaterialUi_Types.Number.t=?,
  ~backButton: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~\"LinearProgressProps": {..}=?,
  ~nextButton: React.element=?,
  ~position: position=?,
  ~steps: MaterialUi_Types.Number.t,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "MobileStepper"
