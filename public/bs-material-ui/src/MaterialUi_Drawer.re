type anchor = [ | `Bottom | `Left | `Right | `Top];

module Classes = {
  type t = {
    .
    "root": option(string),
    "docked": option(string),
    "paper": option(string),
    "paperAnchorLeft": option(string),
    "paperAnchorRight": option(string),
    "paperAnchorTop": option(string),
    "paperAnchorBottom": option(string),
    "paperAnchorDockedLeft": option(string),
    "paperAnchorDockedTop": option(string),
    "paperAnchorDockedRight": option(string),
    "paperAnchorDockedBottom": option(string),
    "modal": option(string),
  };
  [@bs.obj]
  external make:
    (
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
      unit
    ) =>
    t;
};

module TransitionDuration_shape = {
  type t = {
    .
    "appear": option(MaterialUi_Types.Number.t),
    "enter": option(MaterialUi_Types.Number.t),
    "exit": option(MaterialUi_Types.Number.t),
  };
  [@bs.obj]
  external make:
    (
      ~appear: MaterialUi_Types.Number.t=?,
      ~enter: MaterialUi_Types.Number.t=?,
      ~exit: MaterialUi_Types.Number.t=?,
      unit
    ) =>
    t;
};

module TransitionDuration: {
  type t;
  let int: int => t;
  let float: float => t;
  let shape: TransitionDuration_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: TransitionDuration_shape.t) => Any(v);
};

type variant = [ | `Permanent | `Persistent | `Temporary];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~anchor: [@bs.string] [
               | [@bs.as "bottom"] `Bottom
               | [@bs.as "left"] `Left
               | [@bs.as "right"] `Right
               | [@bs.as "top"] `Top
             ]
               =?,
    ~_BackdropProps: Js.t({..})=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~_ModalProps: Js.t({..})=?,
    ~onClose: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool=?,
    ~_PaperProps: Js.t({..})=?,
    ~_SlideProps: Js.t({..})=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "permanent"] `Permanent
                | [@bs.as "persistent"] `Persistent
                | [@bs.as "temporary"] `Temporary
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Drawer";
