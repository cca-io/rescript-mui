module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "tile": option(option(string)),
    "imgFullHeight": option(option(string)),
    "imgFullWidth": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~tile: string=?,
      ~imgFullHeight: string=?,
      ~imgFullWidth: string=?,
      unit
    ) =>
    t;
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~cols: option(MaterialUi_Types.Number.t)=?,
    ~component: option(Component.t)=?,
    ~rows: option(MaterialUi_Types.Number.t)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "GridListTile";
