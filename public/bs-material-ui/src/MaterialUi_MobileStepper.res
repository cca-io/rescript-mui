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
