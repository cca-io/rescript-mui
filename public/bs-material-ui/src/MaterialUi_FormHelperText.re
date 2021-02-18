module Classes = {
  type t = {
    .
    "root": option(string),
    "error": option(string),
    "disabled": option(string),
    "marginDense": option(string),
    "contained": option(string),
    "focused": option(string),
    "filled": option(string),
    "required": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~error: string=?,
      ~disabled: string=?,
      ~marginDense: string=?,
      ~contained: string=?,
      ~focused: string=?,
      ~filled: string=?,
      ~required: string=?,
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

type margin = [ | `Dense];

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~filled: bool=?,
    ~focused: bool=?,
    ~margin: [@bs.string] [ | [@bs.as "dense"] `Dense]=?,
    ~required: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "filled"] `Filled
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "FormHelperText";
