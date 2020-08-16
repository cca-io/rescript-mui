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

type anchor = [ | `Left | `Top | `Right | `Bottom];

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module BackdropProps = {
  type t = {. "component": option(Component.t)};
  [@bs.obj] external make: (~component: Component.t=?, unit) => t;
};

module ModalProps = {
  type t = {. "BackdropProps": option(BackdropProps.t)};
  [@bs.obj] external make: (~_BackdropProps: BackdropProps.t=?, unit) => t;
};

module PaperProps = {
  type t = {
    .
    "component": option(Component.t),
    "style": option(MaterialUi_Types.any),
  };
  [@bs.obj]
  external make:
    (~component: Component.t=?, ~style: MaterialUi_Types.any=?, unit) => t;
};

module TransitionDuration_shape = {
  type t = {
    .
    "enter": option(MaterialUi_Types.Number.t),
    "exit": option(MaterialUi_Types.Number.t),
  };
  [@bs.obj]
  external make:
    (
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
    ~_BackdropProps: Js.t({..})=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~_SlideProps: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~anchor: [@bs.string] [
               | [@bs.as "left"] `Left
               | [@bs.as "top"] `Top
               | [@bs.as "right"] `Right
               | [@bs.as "bottom"] `Bottom
             ]
               =?,
    ~children: 'children=?,
    ~disableBackdropTransition: bool=?,
    ~disableDiscovery: bool=?,
    ~disableSwipeToOpen: bool=?,
    ~hideBackdrop: bool=?,
    ~hysteresis: MaterialUi_Types.Number.t=?,
    ~minFlingVelocity: MaterialUi_Types.Number.t=?,
    ~_ModalProps: ModalProps.t=?,
    ~onClose: ReactEvent.Synthetic.t => unit,
    ~onOpen: ReactEvent.Synthetic.t => unit,
    ~_open: bool,
    ~_PaperProps: PaperProps.t=?,
    ~_SwipeAreaProps: Js.t({..})=?,
    ~swipeAreaWidth: MaterialUi_Types.Number.t=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "permanent"] `Permanent
                | [@bs.as "persistent"] `Persistent
                | [@bs.as "temporary"] `Temporary
              ]
                =?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "SwipeableDrawer";
