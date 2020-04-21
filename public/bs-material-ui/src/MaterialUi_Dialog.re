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
  type t = {
    .
    "root": option(option(string)),
    "scrollPaper": option(option(string)),
    "scrollBody": option(option(string)),
    "container": option(option(string)),
    "paper": option(option(string)),
    "paperScrollPaper": option(option(string)),
    "paperScrollBody": option(option(string)),
    "paperWidthFalse": option(option(string)),
    "paperWidthXs": option(option(string)),
    "paperWidthSm": option(option(string)),
    "paperWidthMd": option(option(string)),
    "paperWidthLg": option(option(string)),
    "paperWidthXl": option(option(string)),
    "paperFullWidth": option(option(string)),
    "paperFullScreen": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~scrollPaper: string=?,
      ~scrollBody: string=?,
      ~container: string=?,
      ~paper: string=?,
      ~paperScrollPaper: string=?,
      ~paperScrollBody: string=?,
      ~paperWidthFalse: string=?,
      ~paperWidthXs: string=?,
      ~paperWidthSm: string=?,
      ~paperWidthMd: string=?,
      ~paperWidthLg: string=?,
      ~paperWidthXl: string=?,
      ~paperFullWidth: string=?,
      ~paperFullScreen: string=?,
      unit
    ) =>
    t;
};

module MaxWidth: {
  type t;
  let lg: t;
  let md: t;
  let sm: t;
  let xl: t;
  let xs: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let lg = Any("lg");
  let md = Any("md");
  let sm = Any("sm");
  let xl = Any("xl");
  let xs = Any("xs");
  let _false = Any(false);
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

type scroll = [ | `Body | `Paper];

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
    ~maxWidth: option(MaxWidth.t)=?,
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
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Dialog";
