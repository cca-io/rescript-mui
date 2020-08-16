module Horizontal: {
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

module Vertical: {
  type t;
  let bottom: t;
  let top: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let bottom = Any("bottom");
  let top = Any("top");
};

module AnchorOrigin = {
  type t = {
    .
    "horizontal": option(Horizontal.t),
    "vertical": option(Vertical.t),
  };
  [@bs.obj]
  external make:
    (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t;
};

module Classes = {
  type t = {
    .
    "root": option(string),
    "anchorOriginTopCenter": option(string),
    "anchorOriginBottomCenter": option(string),
    "anchorOriginTopRight": option(string),
    "anchorOriginBottomRight": option(string),
    "anchorOriginTopLeft": option(string),
    "anchorOriginBottomLeft": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~anchorOriginTopCenter: string=?,
      ~anchorOriginBottomCenter: string=?,
      ~anchorOriginTopRight: string=?,
      ~anchorOriginBottomRight: string=?,
      ~anchorOriginTopLeft: string=?,
      ~anchorOriginBottomLeft: string=?,
      unit
    ) =>
    t;
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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~action: React.element=?,
    ~anchorOrigin: AnchorOrigin.t=?,
    ~autoHideDuration: MaterialUi_Types.Number.t=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~_ClickAwayListenerProps: Js.t({..})=?,
    ~_ContentProps: Js.t({..})=?,
    ~disableWindowBlurListener: bool=?,
    ~key: string=?,
    ~message: React.element=?,
    ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~_open: bool=?,
    ~resumeHideDuration: MaterialUi_Types.Number.t=?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~_TransitionProps: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Snackbar";
