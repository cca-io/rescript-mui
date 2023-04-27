module Components = {
  type t = {
    "Arrow": option<React.element>,
    "Popper": option<React.element>,
    "Tooltip": option<React.element>,
    "Transition": option<React.element>,
  }
  @obj
  external make: (
    ~\"Arrow": React.element=?,
    ~\"Popper": React.element=?,
    ~\"Tooltip": React.element=?,
    ~\"Transition": React.element=?,
    unit,
  ) => t = ""
}

module ComponentsProps = {
  type t = {
    "arrow": option<Any.t>,
    "popper": option<Any.t>,
    "tooltip": option<Any.t>,
    "transition": option<Any.t>,
  }
  @obj
  external make: (
    ~arrow: Any.t=?,
    ~popper: Any.t=?,
    ~tooltip: Any.t=?,
    ~transition: Any.t=?,
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

module SlotProps = {
  type t = {
    "arrow": option<Any.t>,
    "popper": option<Any.t>,
    "tooltip": option<Any.t>,
    "transition": option<Any.t>,
  }
  @obj
  external make: (
    ~arrow: Any.t=?,
    ~popper: Any.t=?,
    ~tooltip: Any.t=?,
    ~transition: Any.t=?,
    unit,
  ) => t = ""
}

module Slots = {
  type t = {
    "arrow": option<React.element>,
    "popper": option<React.element>,
    "tooltip": option<React.element>,
    "transition": option<React.element>,
  }
  @obj
  external make: (
    ~arrow: React.element=?,
    ~popper: React.element=?,
    ~tooltip: React.element=?,
    ~transition: React.element=?,
    unit,
  ) => t = ""
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~arrow: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~describeChild: bool=?,
  ~disableFocusListener: bool=?,
  ~disableHoverListener: bool=?,
  ~disableInteractive: bool=?,
  ~disableTouchListener: bool=?,
  ~enterDelay: Number.t=?,
  ~enterNextDelay: Number.t=?,
  ~enterTouchDelay: Number.t=?,
  ~followCursor: bool=?,
  ~id: string=?,
  ~leaveDelay: Number.t=?,
  ~leaveTouchDelay: Number.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~onOpen: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~placement: placement=?,
  ~\"PopperComponent": React.element=?,
  ~\"PopperProps": {..}=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~title: React.element=?,
  ~\"TransitionComponent": React.element=?,
  ~\"TransitionProps": {..}=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tooltip"
