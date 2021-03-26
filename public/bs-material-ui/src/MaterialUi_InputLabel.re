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

module Classes = {
  type t = {
    .
    "root": option(string),
    "focused": option(string),
    "disabled": option(string),
    "error": option(string),
    "required": option(string),
    "asterisk": option(string),
    "formControl": option(string),
    "marginDense": option(string),
    "shrink": option(string),
    "animated": option(string),
    "filled": option(string),
    "outlined": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~focused: string=?,
      ~disabled: string=?,
      ~error: string=?,
      ~required: string=?,
      ~asterisk: string=?,
      ~formControl: string=?,
      ~marginDense: string=?,
      ~shrink: string=?,
      ~animated: string=?,
      ~filled: string=?,
      ~outlined: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Primary | `Secondary];

type margin = [ | `Dense];

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: Component.t=?,
    ~filled: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~disableAnimation: bool=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~focused: bool=?,
    ~margin: [@bs.string] [ | [@bs.as "dense"] `Dense]=?,
    ~required: bool=?,
    ~shrink: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "filled"] `Filled
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~htmlFor: string,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "InputLabel";
