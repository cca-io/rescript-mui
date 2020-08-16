module Classes = {
  type t = {
    .
    "root": option(string),
    "ol": option(string),
    "li": option(string),
    "separator": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~ol: string=?,
      ~li: string=?,
      ~separator: string=?,
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
    ~expandText: string=?,
    ~itemsAfterCollapse: MaterialUi_Types.Number.t=?,
    ~itemsBeforeCollapse: MaterialUi_Types.Number.t=?,
    ~maxItems: MaterialUi_Types.Number.t=?,
    ~separator: React.element=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Breadcrumbs";
