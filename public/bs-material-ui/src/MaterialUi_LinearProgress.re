module Classes = {
  type t = {
    .
    "root": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "determinate": option(string),
    "indeterminate": option(string),
    "buffer": option(string),
    "query": option(string),
    "dashed": option(string),
    "dashedColorPrimary": option(string),
    "dashedColorSecondary": option(string),
    "bar": option(string),
    "barColorPrimary": option(string),
    "barColorSecondary": option(string),
    "bar1Indeterminate": option(string),
    "bar1Determinate": option(string),
    "bar1Buffer": option(string),
    "bar2Indeterminate": option(string),
    "bar2Buffer": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~determinate: string=?,
      ~indeterminate: string=?,
      ~buffer: string=?,
      ~query: string=?,
      ~dashed: string=?,
      ~dashedColorPrimary: string=?,
      ~dashedColorSecondary: string=?,
      ~bar: string=?,
      ~barColorPrimary: string=?,
      ~barColorSecondary: string=?,
      ~bar1Indeterminate: string=?,
      ~bar1Determinate: string=?,
      ~bar1Buffer: string=?,
      ~bar2Indeterminate: string=?,
      ~bar2Buffer: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Primary | `Secondary];

type variant = [ | `Buffer | `Determinate | `Indeterminate | `Query];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~value: MaterialUi_Types.Number.t=?,
    ~valueBuffer: MaterialUi_Types.Number.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "buffer"] `Buffer
                | [@bs.as "determinate"] `Determinate
                | [@bs.as "indeterminate"] `Indeterminate
                | [@bs.as "query"] `Query
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "LinearProgress";
