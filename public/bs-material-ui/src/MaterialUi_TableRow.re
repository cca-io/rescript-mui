module Classes = {
  type t = {
    .
    "root": option(string),
    "selected": option(string),
    "hover": option(string),
    "head": option(string),
    "footer": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~selected: string=?,
      ~hover: string=?,
      ~head: string=?,
      ~footer: string=?,
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
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~hover: bool=?,
    ~selected: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "TableRow";
