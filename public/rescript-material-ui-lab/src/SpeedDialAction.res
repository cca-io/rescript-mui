module Classes = {
  type t = {
    "fab": option<string>,
    "fabClosed": option<string>,
    "staticTooltip": option<string>,
    "staticTooltipClosed": option<string>,
    "staticTooltipLabel": option<string>,
    "tooltipPlacementLeft": option<string>,
    "tooltipPlacementRight": option<string>,
  }
  @obj
  external make: (
    ~fab: string=?,
    ~fabClosed: string=?,
    ~staticTooltip: string=?,
    ~staticTooltipClosed: string=?,
    ~staticTooltipLabel: string=?,
    ~tooltipPlacementLeft: string=?,
    ~tooltipPlacementRight: string=?,
    unit,
  ) => t = ""
}

type tooltipPlacement = [
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

@react.component @module("@material-ui/lab")
external make: (
  ~classes: Classes.t=?,
  ~className: string=?,
  ~delay: Mui.Number.t=?,
  ~\"FabProps": {..}=?,
  ~icon: React.element=?,
  ~id: string=?,
  ~\"open": bool=?,
  ~\"TooltipClasses": {..}=?,
  ~tooltipOpen: bool=?,
  ~tooltipPlacement: tooltipPlacement=?,
  ~tooltipTitle: React.element=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SpeedDialAction"
