module Classes = {
  type t = {
    "root": option<string>,
    "horizontal": option<string>,
    "vertical": option<string>,
    "label": option<string>,
    "active": option<string>,
    "completed": option<string>,
    "error": option<string>,
    "disabled": option<string>,
    "iconContainer": option<string>,
    "alternativeLabel": option<string>,
    "labelContainer": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~horizontal: string=?,
    ~vertical: string=?,
    ~label: string=?,
    ~active: string=?,
    ~completed: string=?,
    ~error: string=?,
    ~disabled: string=?,
    ~iconContainer: string=?,
    ~alternativeLabel: string=?,
    ~labelContainer: string=?,
    unit,
  ) => t = ""
}

module StepIconComponent = {
  type t
  external string: string => t = "%identity"
  external stepIconComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~icon: React.element=?,
  ~optional: React.element=?,
  ~\"StepIconComponent": StepIconComponent.t=?,
  ~\"StepIconProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "StepLabel"
