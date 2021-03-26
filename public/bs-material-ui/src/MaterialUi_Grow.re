module Timeout_enum: {
  type t;
  let auto: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let auto = Any("auto");
};

module Timeout_shape = {
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

module Timeout: {
  type t;
  let enum: Timeout_enum.t => t;
  let int: int => t;
  let float: float => t;
  let shape: Timeout_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Timeout_enum.t) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: Timeout_shape.t) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~disableStrictModeCompat: bool=?,
    ~_in: bool=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~style: ReactDOM.Style.t=?,
    ~timeout: Timeout.t=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Grow";
