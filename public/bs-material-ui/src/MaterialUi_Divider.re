module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "absolute": option(option(string)),
    "inset": option(option(string)),
    "light": option(option(string)),
    "middle": option(option(string)),
    "vertical": option(option(string)),
    "flexItem": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~absolute: string=?,
      ~inset: string=?,
      ~light: string=?,
      ~middle: string=?,
      ~vertical: string=?,
      ~flexItem: string=?,
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

type orientation = [ | `Horizontal | `Vertical];

type variant = [ | `FullWidth | `Inset | `Middle];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~absolute: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~flexItem: option(bool)=?,
    ~light: option(bool)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "horizontal"] `Horizontal
                      | [@bs.as "vertical"] `Vertical
                    ],
                  )
                    =?,
    ~role: option(string)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "fullWidth"] `FullWidth
                  | [@bs.as "inset"] `Inset
                  | [@bs.as "middle"] `Middle
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Divider";
