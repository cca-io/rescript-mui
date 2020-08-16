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
  let obj: Js.t({..}) => t;
  let anchorEl_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let obj = (v: Js.t({..})) => Any(v);
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

module Classes = {
  type t = {
    .
    "root": option(string),
    "paper": option(string),
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
  type t = {. "component": option(Component.t)};
  [@bs.obj] external make: (~component: Component.t=?, unit) => t;
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
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~anchorEl: AnchorEl.t=?,
    ~anchorOrigin: AnchorOrigin.t=?,
    ~anchorPosition: AnchorPosition.t=?,
    ~anchorReference: [@bs.string] [
                        | [@bs.as "anchorEl"] `AnchorEl
                        | [@bs.as "anchorPosition"] `AnchorPosition
                        | [@bs.as "none"] `None
                      ]
                        =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~container: Container.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~getContentAnchorEl: MaterialUi_Types.any=?,
    ~marginThreshold: MaterialUi_Types.Number.t=?,
    ~onClose: ReactEvent.Synthetic.t => unit=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: PaperProps.t=?,
    ~transformOrigin: TransformOrigin.t=?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~_TransitionProps: Js.t({..})=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Popover";
