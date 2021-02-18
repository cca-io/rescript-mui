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
    "horizontal": option(Horizontal.t),
    "vertical": option(Vertical.t),
  };
  [@bs.obj]
  external make:
    (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t;
};

module AnchorPosition = {
  type t = {
    .
    "left": option(MaterialUi_Types.Number.t),
    "top": option(MaterialUi_Types.Number.t),
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

module Container: {
  type t;
  let custom: Dom.element => t;
  let element: React.element => t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let custom = (v: Dom.element) => Any(v);
  let element = (v: React.element) => Any(v);
  let container_func = (v: MaterialUi_Types.any) => Any(v);
};

module TransformOrigin = {
  type t = {
    .
    "horizontal": option(Horizontal.t),
    "vertical": option(Vertical.t),
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

module Classes = {
  type t = {
    .
    "paper": option(string),
    "list": option(string),
  };
  [@bs.obj] external make: (~paper: string=?, ~list: string=?, unit) => t;
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

type variant = [ | `Menu | `SelectedMenu];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~_BackdropComponent: BackdropComponent.t=?,
    ~_BackdropProps: Js.t({..})=?,
    ~closeAfterTransition: bool=?,
    ~disableAutoFocus: bool=?,
    ~disableBackdropClick: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~disablePortal: bool=?,
    ~disableRestoreFocus: bool=?,
    ~disableScrollLock: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~anchorOrigin: AnchorOrigin.t=?,
    ~anchorPosition: AnchorPosition.t=?,
    ~anchorReference: [@bs.string] [
                        | [@bs.as "anchorEl"] `AnchorEl
                        | [@bs.as "anchorPosition"] `AnchorPosition
                        | [@bs.as "none"] `None
                      ]
                        =?,
    ~className: string=?,
    ~container: Container.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~getContentAnchorEl: MaterialUi_Types.any=?,
    ~marginThreshold: MaterialUi_Types.Number.t=?,
    ~transformOrigin: TransformOrigin.t=?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~_TransitionProps: Js.t({..})=?,
    ~anchorEl: MaterialUi_Types.any=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~disableAutoFocusItem: bool=?,
    ~_MenuListProps: Js.t({..})=?,
    ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_PopoverClasses: Js.t({..})=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "menu"] `Menu
                | [@bs.as "selectedMenu"] `SelectedMenu
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Menu";
