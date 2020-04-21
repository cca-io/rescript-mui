module BackdropComponent: {
  type t;
  let string: string => t;
  let backdropComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let backdropComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module AnchorEl: {
  type t;
  let obj: Js.Dict.t(MaterialUi_Types.any) => t;
  let anchorEl_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let obj = (v: Js.Dict.t(MaterialUi_Types.any)) => Any(v);
  let anchorEl_func = (v: MaterialUi_Types.any) => Any(v);
};

module Horizontal_enum: {
  type t;
  let center: t;
  let left: t;
  let right: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let center = Any("center");
  let left = Any("left");
  let right = Any("right");
};

module Horizontal: {
  type t;
  let enum: Horizontal_enum.t => t;
  let int: int => t;
  let float: float => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Horizontal_enum.t) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
};

module Vertical_enum: {
  type t;
  let bottom: t;
  let center: t;
  let top: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let bottom = Any("bottom");
  let center = Any("center");
  let top = Any("top");
};

module Vertical: {
  type t;
  let enum: Vertical_enum.t => t;
  let int: int => t;
  let float: float => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Vertical_enum.t) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
};

module AnchorOrigin = {
  type t = {
    .
    "horizontal": option(option(Horizontal.t)),
    "vertical": option(option(Vertical.t)),
  };
  [@bs.obj]
  external make:
    (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t;
};

module AnchorPosition = {
  type t = {
    .
    "left": option(option(MaterialUi_Types.Number.t)),
    "top": option(option(MaterialUi_Types.Number.t)),
  };
  [@bs.obj]
  external make:
    (
      ~left: MaterialUi_Types.Number.t=?,
      ~top: MaterialUi_Types.Number.t=?,
      unit
    ) =>
    t;
};

type anchorReference = [ | `AnchorEl | `AnchorPosition | `None];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "paper": option(option(string)),
  };
  [@bs.obj] external make: (~root: string=?, ~paper: string=?, unit) => t;
};

module Container: {
  type t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let container_func = (v: MaterialUi_Types.any) => Any(v);
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

module PaperProps = {
  type t = {. "component": option(option(Component.t))};
  [@bs.obj] external make: (~component: Component.t=?, unit) => t;
};

module TransformOrigin = {
  type t = {
    .
    "horizontal": option(option(Horizontal.t)),
    "vertical": option(option(Vertical.t)),
  };
  [@bs.obj]
  external make:
    (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t;
};

module TransitionComponent: {
  type t;
  let string: string => t;
  let transitionComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module TransitionDuration_enum: {
  type t;
  let auto: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let auto = Any("auto");
};

module TransitionDuration_shape = {
  type t = {
    .
    "appear": option(option(MaterialUi_Types.Number.t)),
    "enter": option(option(MaterialUi_Types.Number.t)),
    "exit": option(option(MaterialUi_Types.Number.t)),
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
  let enum: TransitionDuration_enum.t => t;
  let int: int => t;
  let float: float => t;
  let shape: TransitionDuration_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: TransitionDuration_enum.t) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: TransitionDuration_shape.t) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~_BackdropComponent: option(BackdropComponent.t)=?,
    ~_BackdropProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~closeAfterTransition: option(bool)=?,
    ~disableAutoFocus: option(bool)=?,
    ~disableBackdropClick: option(bool)=?,
    ~disableEnforceFocus: option(bool)=?,
    ~disableEscapeKeyDown: option(bool)=?,
    ~disablePortal: option(bool)=?,
    ~disableRestoreFocus: option(bool)=?,
    ~disableScrollLock: option(bool)=?,
    ~hideBackdrop: option(bool)=?,
    ~keepMounted: option(bool)=?,
    ~manager: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
    ~id: option(string)=?,
    ~anchorEl: option(AnchorEl.t)=?,
    ~anchorOrigin: option(AnchorOrigin.t)=?,
    ~anchorPosition: option(AnchorPosition.t)=?,
    ~anchorReference: option(
                        [@bs.string] [
                          | [@bs.as "anchorEl"] `AnchorEl
                          | [@bs.as "anchorPosition"] `AnchorPosition
                          | [@bs.as "none"] `None
                        ],
                      )
                        =?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~container: option(Container.t)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~getContentAnchorEl: option(MaterialUi_Types.any)=?,
    ~marginThreshold: option(MaterialUi_Types.Number.t)=?,
    ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: bool,
    ~_PaperProps: option(PaperProps.t)=?,
    ~transformOrigin: option(TransformOrigin.t)=?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Popover";
