module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    static: string,
    [@bs.optional]
    indeterminate: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    svg: string,
    [@bs.optional]
    circle: string,
    [@bs.optional]
    circleStatic: string,
    [@bs.optional]
    circleIndeterminate: string,
    [@bs.optional]
    circleDisableShrink: string,
  };
  let make = t;
};

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
