module Classes = {
  type t = {
    .
    "root": option(string),
    "fab": option(string),
    "directionUp": option(string),
    "directionDown": option(string),
    "directionLeft": option(string),
    "directionRight": option(string),
    "actions": option(string),
    "actionsClosed": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~fab: string=?,
      ~directionUp: string=?,
      ~directionDown: string=?,
      ~directionLeft: string=?,
      ~directionRight: string=?,
      ~actions: string=?,
      ~actionsClosed: string=?,
      unit
    ) =>
    t;
};

type direction = [ | `Down | `Left | `Right | `Up];

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

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~ariaLabel: string,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~direction: [@bs.string] [
                  | [@bs.as "down"] `Down
                  | [@bs.as "left"] `Left
                  | [@bs.as "right"] `Right
                  | [@bs.as "up"] `Up
                ]
                  =?,
    ~_FabProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~hidden: bool=?,
    ~icon: React.element=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onOpen: (ReactEvent.Synthetic.t, string) => unit=?,
    ~_open: bool,
    ~openIcon: React.element=?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~transitionDuration: TransitionDuration.t=?,
    ~_TransitionProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "SpeedDial";
