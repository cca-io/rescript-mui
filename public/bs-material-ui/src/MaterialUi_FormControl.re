module Classes = {
  type t = {
    .
    "root": option(string),
    "marginNormal": option(string),
    "marginDense": option(string),
    "fullWidth": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~marginNormal: string=?,
      ~marginDense: string=?,
      ~fullWidth: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Primary | `Secondary];

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

type margin = [ | `Dense | `None | `Normal];

type size = [ | `Medium | `Small];

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~component: Component.t=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~focused: bool=?,
    ~fullWidth: bool=?,
    ~hiddenLabel: bool=?,
    ~margin: [@bs.string] [
               | [@bs.as "dense"] `Dense
               | [@bs.as "none"] `None
               | [@bs.as "normal"] `Normal
             ]
               =?,
    ~required: bool=?,
    ~size: [@bs.string] [
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
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
  "FormControl";
