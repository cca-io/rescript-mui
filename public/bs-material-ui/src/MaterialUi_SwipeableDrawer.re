module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    docked: string,
    [@bs.optional]
    paper: string,
    [@bs.optional]
    paperAnchorLeft: string,
    [@bs.optional]
    paperAnchorRight: string,
    [@bs.optional]
    paperAnchorTop: string,
    [@bs.optional]
    paperAnchorBottom: string,
    [@bs.optional]
    paperAnchorDockedLeft: string,
    [@bs.optional]
    paperAnchorDockedTop: string,
    [@bs.optional]
    paperAnchorDockedRight: string,
    [@bs.optional]
    paperAnchorDockedBottom: string,
    [@bs.optional]
    modal: string,
  };
  let make = t;
};

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
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    component: Component.t,
  };
  let make = t;
};

module ModalProps = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "BackdropProps"]
    _BackdropProps: BackdropProps.t,
  };
  let make = t;
};

module PaperProps = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    component: Component.t,
    [@bs.optional]
    style: Js.Dict.t(MaterialUi_Types.any),
  };
  let make = t;
};

module TransitionDuration_shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    enter: MaterialUi_Types.Number.t,
    [@bs.optional]
    exit: MaterialUi_Types.Number.t,
  };
  let make = t;
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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~_BackdropProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~_SlideProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~anchor: option(
               [@bs.string] [
                 | [@bs.as "left"] `Left
                 | [@bs.as "top"] `Top
                 | [@bs.as "right"] `Right
                 | [@bs.as "bottom"] `Bottom
               ],
             )
               =?,
    ~children: option('children)=?,
    ~disableBackdropTransition: option(bool)=?,
    ~disableDiscovery: option(bool)=?,
    ~disableSwipeToOpen: option(bool)=?,
    ~hideBackdrop: option(bool)=?,
    ~hysteresis: option(MaterialUi_Types.Number.t)=?,
    ~minFlingVelocity: option(MaterialUi_Types.Number.t)=?,
    ~_ModalProps: option(ModalProps.t)=?,
    ~onClose: ReactEvent.Synthetic.t => unit,
    ~onOpen: ReactEvent.Synthetic.t => unit,
    ~_open: bool,
    ~_PaperProps: option(PaperProps.t)=?,
    ~_SwipeAreaProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~swipeAreaWidth: option(MaterialUi_Types.Number.t)=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "permanent"] `Permanent
                  | [@bs.as "persistent"] `Persistent
                  | [@bs.as "temporary"] `Temporary
                ],
              )
                =?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "SwipeableDrawer";
