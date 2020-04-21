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
    "root": option(option(string)),
    "message": option(option(string)),
    "action": option(option(string)),
  };
  [@bs.obj]
  external make:
    (~root: string=?, ~message: string=?, ~action: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~component: option(Component.t)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~square: option(bool)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "elevation"] `Elevation
                  | [@bs.as "outlined"] `Outlined
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~action: option(React.element)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~message: option(React.element)=?,
    ~role: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "SnackbarContent";
