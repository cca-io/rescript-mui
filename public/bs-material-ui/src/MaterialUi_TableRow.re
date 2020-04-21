module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "selected": option(option(string)),
    "hover": option(option(string)),
    "head": option(option(string)),
    "footer": option(option(string)),
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~hover: option(bool)=?,
    ~selected: option(bool)=?,
    ~id: option(string)=?,
    ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TableRow";
