module Classes = {
  type t = {
    .
    "root": option(string),
    "stickyHeader": option(string),
  };
  [@bs.obj]
  external make: (~root: string=?, ~stickyHeader: string=?, unit) => t;
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

type padding = [ | `Default | `Checkbox | `None];

type size = [ | `Small | `Medium];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~padding: [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "checkbox"] `Checkbox
                | [@bs.as "none"] `None
              ]
                =?,
    ~size: [@bs.string] [
             | [@bs.as "small"] `Small
             | [@bs.as "medium"] `Medium
           ]
             =?,
    ~stickyHeader: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Table";
