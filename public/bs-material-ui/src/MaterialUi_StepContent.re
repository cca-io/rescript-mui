module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    last: string,
    [@bs.optional]
    transition: string,
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~transitionDuration: option(TransitionDuration.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "StepContent";
