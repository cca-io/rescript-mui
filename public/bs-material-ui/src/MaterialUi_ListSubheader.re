module Classes = {
  type t = {
    .
    "root": option(string),
    "colorPrimary": option(string),
    "colorInherit": option(string),
    "gutters": option(string),
    "inset": option(string),
    "sticky": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorPrimary: string=?,
      ~colorInherit: string=?,
      ~gutters: string=?,
      ~inset: string=?,
      ~sticky: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Primary | `Inherit];

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
    ~color: [@bs.string] [
              | [@bs.as "default"] `Default
              | [@bs.as "primary"] `Primary
              | [@bs.as "inherit"] `Inherit
            ]
              =?,
    ~component: Component.t=?,
    ~disableGutters: bool=?,
    ~disableSticky: bool=?,
    ~inset: bool=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ListSubheader";
