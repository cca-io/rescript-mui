module CellHeight_enum: {
  type t;
  let auto: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let auto = Any("auto");
};

module CellHeight: {
  type t;
  let int: int => t;
  let float: float => t;
  let enum: CellHeight_enum.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let enum = (v: CellHeight_enum.t) => Any(v);
};

module Classes = {
  type t = {. "root": option(option(string))};
  [@bs.obj] external make: (~root: string=?, unit) => t;
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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~cellHeight: option(CellHeight.t)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~cols: option(MaterialUi_Types.Number.t)=?,
    ~component: option(Component.t)=?,
    ~spacing: option(MaterialUi_Types.Number.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "GridList";
