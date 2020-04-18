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

module Horizontal_enum: {
  type t;
  let left: t;
  let center: t;
  let right: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let left = Any("left");
  let center = Any("center");
  let right = Any("right");
};

module Horizontal: {
  type t;
  let int: int => t;
  let float: float => t;
  let enum: Horizontal_enum.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let enum = (v: Horizontal_enum.t) => Any(v);
};

module Vertical_enum: {
  type t;
  let top: t;
  let center: t;
  let bottom: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let top = Any("top");
  let center = Any("center");
  let bottom = Any("bottom");
};

module Vertical: {
  type t;
  let int: int => t;
  let float: float => t;
  let enum: Vertical_enum.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let enum = (v: Vertical_enum.t) => Any(v);
};

module AnchorOrigin = {
  [@bs.deriving abstract]
  type t = {
    horizontal: Horizontal.t,
    vertical: Vertical.t,
  };
  let make = t;
};

module AnchorPosition = {
  [@bs.deriving abstract]
  type t = {
    left: MaterialUi_Types.Number.t,
    top: MaterialUi_Types.Number.t,
  };
  let make = t;
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

module TransformOrigin = {
  [@bs.deriving abstract]
  type t = {
    horizontal: Horizontal.t,
    vertical: Vertical.t,
  };
  let make = t;
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

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    paper: string,
    [@bs.optional]
    list: string,
  };
  let make = t;
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
    ~className: option(string)=?,
    ~container: option(Container.t)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~getContentAnchorEl: option(MaterialUi_Types.any)=?,
    ~marginThreshold: option(MaterialUi_Types.Number.t)=?,
    ~transformOrigin: option(TransformOrigin.t)=?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~anchorEl: option(MaterialUi_Types.any)=?,
    ~autoFocus: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~disableAutoFocusItem: option(bool)=?,
    ~_MenuListProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: bool,
    ~_PaperProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_PopoverClasses: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "menu"] `Menu
                  | [@bs.as "selectedMenu"] `SelectedMenu
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Menu";
