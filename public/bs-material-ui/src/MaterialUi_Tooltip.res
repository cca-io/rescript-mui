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

module PopperComponent: {
  type t
  let string: string => t
  let popperComponent_func: MaterialUi_Types.any => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let popperComponent_func = (v: MaterialUi_Types.any) => Any(v)
  let element = (v: React.element) => Any(v)
}

module TransitionComponent: {
  type t
  let string: string => t
  let transitionComponent_func: MaterialUi_Types.any => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v)
  let element = (v: React.element) => Any(v)
}

@react.component @module("@material-ui/core")
external make: (
  ~arrow: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disableFocusListener: bool=?,
  ~disableHoverListener: bool=?,
  ~disableTouchListener: bool=?,
  ~enterDelay: MaterialUi_Types.Number.t=?,
  ~enterNextDelay: MaterialUi_Types.Number.t=?,
  ~enterTouchDelay: MaterialUi_Types.Number.t=?,
  ~id: string=?,
  ~interactive: bool=?,
  ~leaveDelay: MaterialUi_Types.Number.t=?,
  ~leaveTouchDelay: MaterialUi_Types.Number.t=?,
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
