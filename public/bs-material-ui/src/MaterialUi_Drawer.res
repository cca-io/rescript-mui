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

module TransitionDuration: {
  type t
  let int: int => t
  let float: float => t
  let shape: TransitionDuration_shape.t => t
} = {
  @unboxed
  type rec t = Any('a): t
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let shape = (v: TransitionDuration_shape.t) => Any(v)
}

type variant = [#permanent | #persistent | #temporary]

@react.component @module("@material-ui/core")
external make: (
  ~anchor: anchor=?,
  ~\"BackdropProps": {..}=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~elevation: MaterialUi_Types.Number.t=?,
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
