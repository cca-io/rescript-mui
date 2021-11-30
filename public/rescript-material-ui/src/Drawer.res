type anchor = [#bottom | #left | #right | #top]

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

module TransitionDuration_shape = {
  type t = {"appear": option<Number.t>, "enter": option<Number.t>, "exit": option<Number.t>}
  @obj external make: (~appear: Number.t=?, ~enter: Number.t=?, ~exit: Number.t=?, unit) => t = ""
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
  ~anchor: anchor=?,
  ~\"BackdropProps": {..}=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~elevation: Number.t=?,
  ~\"ModalProps": {..}=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~\"PaperProps": {..}=?,
  ~\"SlideProps": {..}=?,
  ~transitionDuration: TransitionDuration.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Drawer"
