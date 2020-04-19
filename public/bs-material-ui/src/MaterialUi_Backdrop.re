module Timeout_shape = {
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

module Timeout: {
  type t;
  let int: int => t;
  let float: float => t;
  let shape: Timeout_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: Timeout_shape.t) => Any(v);
};

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    invisible: string,
  };
  let make = t;
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
    ~_in: option(bool)=?,
    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
    ~timeout: option(Timeout.t)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~invisible: option(bool)=?,
    ~_open: bool,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Backdrop";
