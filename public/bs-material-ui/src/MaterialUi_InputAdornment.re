module Classes = {
  type t = {
    .
    "root": option(string),
    "filled": option(string),
    "positionStart": option(string),
    "positionEnd": option(string),
    "disablePointerEvents": option(string),
    "hiddenLabel": option(string),
    "marginDense": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~filled: string=?,
      ~positionStart: string=?,
      ~positionEnd: string=?,
      ~disablePointerEvents: string=?,
      ~hiddenLabel: string=?,
      ~marginDense: string=?,
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

type position = [ | `Start | `End];

type variant = [ | `Standard | `Outlined | `Filled];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~disablePointerEvents: bool=?,
    ~disableTypography: bool=?,
    ~muiFormControl: Js.t({..})=?,
    ~position: [@bs.string] [ | [@bs.as "start"] `Start | [@bs.as "end"] `End]
                 =?,
    ~variant: [@bs.string] [
                | [@bs.as "standard"] `Standard
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "filled"] `Filled
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "InputAdornment";
