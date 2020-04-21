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
    "horizontal": option(option(Horizontal.t)),
    "vertical": option(option(Vertical.t)),
  };
  [@bs.obj]
  external make:
    (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t;
};

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "anchorOriginTopCenter": option(option(string)),
    "anchorOriginBottomCenter": option(option(string)),
    "anchorOriginTopRight": option(option(string)),
    "anchorOriginBottomRight": option(option(string)),
    "anchorOriginTopLeft": option(option(string)),
    "anchorOriginBottomLeft": option(option(string)),
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
    ~action: option(React.element)=?,
    ~anchorOrigin: option(AnchorOrigin.t)=?,
    ~autoHideDuration: option(MaterialUi_Types.Number.t)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~_ClickAwayListenerProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_ContentProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~disableWindowBlurListener: option(bool)=?,
    ~key: option(string)=?,
    ~message: option(React.element)=?,
    ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
    ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~_open: option(bool)=?,
    ~resumeHideDuration: option(MaterialUi_Types.Number.t)=?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Snackbar";
