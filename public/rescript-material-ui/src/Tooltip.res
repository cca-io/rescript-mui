module Classes = {
  type t = {
    "popper": option<string>,
    "popperInteractive": option<string>,
    "popperArrow": option<string>,
    "tooltip": option<string>,
    "tooltipArrow": option<string>,
    "arrow": option<string>,
    "touch": option<string>,
    "tooltipPlacementLeft": option<string>,
    "tooltipPlacementRight": option<string>,
    "tooltipPlacementTop": option<string>,
    "tooltipPlacementBottom": option<string>,
  }
  @obj
  external make: (
    ~popper: string=?,
    ~popperInteractive: string=?,
    ~popperArrow: string=?,
    ~tooltip: string=?,
    ~tooltipArrow: string=?,
    ~arrow: string=?,
    ~touch: string=?,
    ~tooltipPlacementLeft: string=?,
    ~tooltipPlacementRight: string=?,
    ~tooltipPlacementTop: string=?,
    ~tooltipPlacementBottom: string=?,
    unit,
  ) => t = ""
}

type placement = [
  | #"bottom-end"
  | #"bottom-start"
  | #bottom
  | #"left-end"
  | #"left-start"
  | #left
  | #"right-end"
  | #"right-start"
  | #right
  | #"top-end"
  | #"top-start"
  | #top
]

module PopperComponent = {
  type t
  external string: string => t = "%identity"
  external popperComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~arrow: bool=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disableFocusListener: bool=?,
  ~disableHoverListener: bool=?,
  ~disableTouchListener: bool=?,
  ~enterDelay: Number.t=?,
  ~enterNextDelay: Number.t=?,
  ~enterTouchDelay: Number.t=?,
  ~id: string=?,
  ~interactive: bool=?,
  ~leaveDelay: Number.t=?,
  ~leaveTouchDelay: Number.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~onOpen: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~placement: placement=?,
  ~\"PopperComponent": PopperComponent.t=?,
  ~\"PopperProps": {..}=?,
  ~title: React.element,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~\"TransitionProps": {..}=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tooltip"
