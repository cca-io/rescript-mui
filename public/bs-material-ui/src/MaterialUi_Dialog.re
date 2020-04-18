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

module Container: {
  type t;
  let obj: Js.Dict.t(MaterialUi_Types.any) => t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let obj = (v: Js.Dict.t(MaterialUi_Types.any)) => Any(v);
  let container_func = (v: MaterialUi_Types.any) => Any(v);
};

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    scrollPaper: string,
    [@bs.optional]
    scrollBody: string,
    [@bs.optional]
    container: string,
    [@bs.optional]
    paper: string,
    [@bs.optional]
    paperScrollPaper: string,
    [@bs.optional]
    paperScrollBody: string,
    [@bs.optional]
    paperWidthFalse: string,
    [@bs.optional]
    paperWidthXs: string,
    [@bs.optional]
    paperWidthSm: string,
    [@bs.optional]
    paperWidthMd: string,
    [@bs.optional]
    paperWidthLg: string,
    [@bs.optional]
    paperWidthXl: string,
    [@bs.optional]
    paperFullWidth: string,
    [@bs.optional]
    paperFullScreen: string,
  };
  let make = t;
};

module PaperComponent: {
  type t;
  let string: string => t;
  let paperComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let paperComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
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
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    appear: MaterialUi_Types.Number.t,
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
    ~_BackdropComponent: option(BackdropComponent.t)=?,
    ~closeAfterTransition: option(bool)=?,
    ~container: option(Container.t)=?,
    ~disableAutoFocus: option(bool)=?,
    ~disableEnforceFocus: option(bool)=?,
    ~disablePortal: option(bool)=?,
    ~disableRestoreFocus: option(bool)=?,
    ~disableScrollLock: option(bool)=?,
    ~hideBackdrop: option(bool)=?,
    ~keepMounted: option(bool)=?,
    ~manager: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
    ~aria_describedby: option(string)=?,
    ~aria_labelledby: option(string)=?,
    ~_BackdropProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disableBackdropClick: option(bool)=?,
    ~disableEscapeKeyDown: option(bool)=?,
    ~fullScreen: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~maxWidth: option(
                 [@bs.string] [
                   | [@bs.as "lg"] `Lg
                   | [@bs.as "md"] `Md
                   | [@bs.as "sm"] `Sm
                   | [@bs.as "xl"] `Xl
                   | [@bs.as "xs"] `Xs
                   | [@bs.as "false"] `False
                 ],
               )
                 =?,
    ~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: bool,
    ~_PaperComponent: option(PaperComponent.t)=?,
    ~_PaperProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~scroll: option(
               [@bs.string] [
                 | [@bs.as "body"] `Body
                 | [@bs.as "paper"] `Paper
               ],
             )
               =?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Dialog";
