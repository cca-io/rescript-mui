module Classes = {
  type t = {"root": option<string>, "last": option<string>, "transition": option<string>}
  @obj external make: (~root: string=?, ~last: string=?, ~transition: string=?, unit) => t = ""
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

type transitionDuration_enum = [#auto]

module TransitionDuration_shape = {
  type t = {
    "appear": option<MaterialUi_Types.Number.t>,
    "enter": option<MaterialUi_Types.Number.t>,
    "exit": option<MaterialUi_Types.Number.t>,
  }
  @obj
  external make: (
    ~appear: MaterialUi_Types.Number.t=?,
    ~enter: MaterialUi_Types.Number.t=?,
    ~exit: MaterialUi_Types.Number.t=?,
    unit,
  ) => t = ""
}

module TransitionDuration = {
  type t
  external enum: transitionDuration_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "StepContent"
