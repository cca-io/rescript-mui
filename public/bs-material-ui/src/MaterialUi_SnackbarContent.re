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
  type t = {
    .
    "root": option(string),
    "message": option(string),
    "action": option(string),
  };
  [@bs.obj]
  external make:
    (~root: string=?, ~message: string=?, ~action: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~component: Component.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~square: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "elevation"] `Elevation
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~action: React.element=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~message: React.element=?,
    ~role: string=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "SnackbarContent";
