type horizontal = [#center | #left | #right]

type vertical = [#bottom | #top]

module AnchorOrigin = {
  type t = {"horizontal": option<horizontal>, "vertical": option<vertical>}
  @obj external make: (~horizontal: horizontal=?, ~vertical: vertical=?, unit) => t = ""
}

module Classes = {
  type t = {
    "root": option<string>,
    "anchorOriginTopCenter": option<string>,
    "anchorOriginBottomCenter": option<string>,
    "anchorOriginTopRight": option<string>,
    "anchorOriginBottomRight": option<string>,
    "anchorOriginTopLeft": option<string>,
    "anchorOriginBottomLeft": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~anchorOriginTopCenter: string=?,
    ~anchorOriginBottomCenter: string=?,
    ~anchorOriginTopRight: string=?,
    ~anchorOriginBottomRight: string=?,
    ~anchorOriginTopLeft: string=?,
    ~anchorOriginBottomLeft: string=?,
    unit,
  ) => t = ""
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: MaterialUi_Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

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
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~action: React.element=?,
  ~anchorOrigin: AnchorOrigin.t=?,
  ~autoHideDuration: MaterialUi_Types.Number.t=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~\"ClickAwayListenerProps": {..}=?,
  ~\"ContentProps": {..}=?,
  ~disableWindowBlurListener: bool=?,
  ~key: string=?,
  ~message: React.element=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onEnter: ReactEvent.Synthetic.t => unit=?,
  ~onEntered: ReactEvent.Synthetic.t => unit=?,
  ~onEntering: ReactEvent.Synthetic.t => unit=?,
  ~onExit: ReactEvent.Synthetic.t => unit=?,
  ~onExited: ReactEvent.Synthetic.t => unit=?,
  ~onExiting: ReactEvent.Synthetic.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~\"open": bool=?,
  ~resumeHideDuration: MaterialUi_Types.Number.t=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Snackbar"
