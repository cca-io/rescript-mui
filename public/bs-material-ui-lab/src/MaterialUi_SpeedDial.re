module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    fab: string,
    [@bs.optional]
    directionUp: string,
    [@bs.optional]
    directionDown: string,
    [@bs.optional]
    directionLeft: string,
    [@bs.optional]
    directionRight: string,
    [@bs.optional]
    actions: string,
    [@bs.optional]
    actionsClosed: string,
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

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~ariaLabel: string,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~direction: option(
                  [@bs.string] [
                    | [@bs.as "down"] `Down
                    | [@bs.as "left"] `Left
                    | [@bs.as "right"] `Right
                    | [@bs.as "up"] `Up
                  ],
                )
                  =?,
    ~_FabProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~hidden: option(bool)=?,
    ~icon: option(React.element)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onOpen: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~_open: bool,
    ~openIcon: option(React.element)=?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "SpeedDial";
