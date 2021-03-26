module Classes = {
  type t = {
    .
    "root": option(string),
    "gutters": option(string),
    "regular": option(string),
    "dense": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~gutters: string=?,
      ~regular: string=?,
      ~dense: string=?,
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

type variant = [ | `Regular | `Dense];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~disableGutters: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "regular"] `Regular
                | [@bs.as "dense"] `Dense
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Toolbar";
