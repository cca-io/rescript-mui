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

type variant = [#elevation | #outlined]

module Classes = {
  type t = {
    "root": option<string>,
    "horizontal": option<string>,
    "vertical": option<string>,
    "alternativeLabel": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~horizontal: string=?,
    ~vertical: string=?,
    ~alternativeLabel: string=?,
    unit,
  ) => t = ""
}

type orientation = [#horizontal | #vertical]

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~square: bool=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~activeStep: MaterialUi_Types.Number.t=?,
  ~alternativeLabel: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~connector: React.element=?,
  ~nonLinear: bool=?,
  ~orientation: orientation=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Stepper"
