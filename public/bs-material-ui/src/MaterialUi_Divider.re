module Classes = {
  type t = {
    .
    "root": option(string),
    "absolute": option(string),
    "inset": option(string),
    "light": option(string),
    "middle": option(string),
    "vertical": option(string),
    "flexItem": option(string),
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
    ~absolute: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~flexItem: bool=?,
    ~light: bool=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ]
                    =?,
    ~role: string=?,
    ~variant: [@bs.string] [
                | [@bs.as "fullWidth"] `FullWidth
                | [@bs.as "inset"] `Inset
                | [@bs.as "middle"] `Middle
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Divider";
