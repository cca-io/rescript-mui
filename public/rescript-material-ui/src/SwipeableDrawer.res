module Classes = {
  type t = {
    "root": option<string>,
    "docked": option<string>,
    "paper": option<string>,
    "paperAnchorLeft": option<string>,
    "paperAnchorRight": option<string>,
    "paperAnchorTop": option<string>,
    "paperAnchorBottom": option<string>,
    "paperAnchorDockedLeft": option<string>,
    "paperAnchorDockedTop": option<string>,
    "paperAnchorDockedRight": option<string>,
    "paperAnchorDockedBottom": option<string>,
    "modal": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~docked: string=?,
    ~paper: string=?,
    ~paperAnchorLeft: string=?,
    ~paperAnchorRight: string=?,
    ~paperAnchorTop: string=?,
    ~paperAnchorBottom: string=?,
    ~paperAnchorDockedLeft: string=?,
    ~paperAnchorDockedTop: string=?,
    ~paperAnchorDockedRight: string=?,
    ~paperAnchorDockedBottom: string=?,
    ~modal: string=?,
    unit,
  ) => t = ""
}

type anchor = [#left | #top | #right | #bottom]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module BackdropProps = {
  type t = {"component": option<Component.t>}
  @obj external make: (~component: Component.t=?, unit) => t = ""
}

module ModalProps = {
  type t = {"BackdropProps": option<BackdropProps.t>}
  @obj external make: (~\"BackdropProps": BackdropProps.t=?, unit) => t = ""
}

module PaperProps = {
  type t = {"component": option<Component.t>, "style": option<Types.any>}
  @obj external make: (~component: Component.t=?, ~style: Types.any=?, unit) => t = ""
}

module TransitionDuration_shape = {
  type t = {"enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
}

module TransitionDuration = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external shape: TransitionDuration_shape.t => t = "%identity"
}

type variant = [#permanent | #persistent | #temporary]

@react.component @module("@material-ui/core")
external make: (
  ~\"BackdropProps": {..}=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~elevation: Number.t=?,
  ~\"SlideProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~anchor: anchor=?,
  ~children: 'children=?,
  ~disableBackdropTransition: bool=?,
  ~disableDiscovery: bool=?,
  ~disableSwipeToOpen: bool=?,
  ~hideBackdrop: bool=?,
  ~hysteresis: Number.t=?,
  ~minFlingVelocity: Number.t=?,
  ~\"ModalProps": ModalProps.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit,
  ~onOpen: ReactEvent.Synthetic.t => unit,
  ~\"open": bool,
  ~\"PaperProps": PaperProps.t=?,
  ~\"SwipeAreaProps": {..}=?,
  ~swipeAreaWidth: Number.t=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~variant: variant=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SwipeableDrawer"
