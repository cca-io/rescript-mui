module Classes = {
  type t = {
    .
    "root": option(string),
    "static": option(string),
    "indeterminate": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "svg": option(string),
    "circle": option(string),
    "circleStatic": option(string),
    "circleIndeterminate": option(string),
    "circleDisableShrink": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~static: string=?,
      ~indeterminate: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~svg: string=?,
      ~circle: string=?,
      ~circleStatic: string=?,
      ~circleIndeterminate: string=?,
      ~circleDisableShrink: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Inherit | `Primary | `Secondary];

module Size: {
  type t;
  let int: int => t;
  let float: float => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let string = (v: string) => Any(v);
};

type variant = [ | `Determinate | `Indeterminate | `Static];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~disableShrink: bool=?,
    ~size: Size.t=?,
    ~style: ReactDOMRe.Style.t=?,
    ~thickness: MaterialUi_Types.Number.t=?,
    ~value: MaterialUi_Types.Number.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "determinate"] `Determinate
                | [@bs.as "indeterminate"] `Indeterminate
                | [@bs.as "static"] `Static
              ]
                =?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "CircularProgress";
