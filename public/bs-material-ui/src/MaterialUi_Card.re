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

type variant = [ | `Elevation | `Outlined];

module Classes = {
  type t = {. "root": option(string)};
  [@bs.obj] external make: (~root: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: Component.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~square: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "elevation"] `Elevation
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~raised: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Card";
