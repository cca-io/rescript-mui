module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorInherit": option(option(string)),
    "gutters": option(option(string)),
    "inset": option(option(string)),
    "sticky": option(option(string)),
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "primary"] `Primary
                | [@bs.as "inherit"] `Inherit
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~disableGutters: option(bool)=?,
    ~disableSticky: option(bool)=?,
    ~inset: option(bool)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ListSubheader";
