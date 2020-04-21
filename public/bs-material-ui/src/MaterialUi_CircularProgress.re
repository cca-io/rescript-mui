module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "static": option(option(string)),
    "indeterminate": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "svg": option(option(string)),
    "circle": option(option(string)),
    "circleStatic": option(option(string)),
    "circleIndeterminate": option(option(string)),
    "circleDisableShrink": option(option(string)),
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
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~size: option(Size.t)=?,
    ~thickness: option(MaterialUi_Types.Number.t)=?,
    ~value: option(MaterialUi_Types.Number.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "determinate"] `Determinate
                  | [@bs.as "indeterminate"] `Indeterminate
                  | [@bs.as "static"] `Static
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "CircularProgress";
