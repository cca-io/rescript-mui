module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    determinate: string,
    [@bs.optional]
    indeterminate: string,
    [@bs.optional]
    buffer: string,
    [@bs.optional]
    query: string,
    [@bs.optional]
    dashed: string,
    [@bs.optional]
    dashedColorPrimary: string,
    [@bs.optional]
    dashedColorSecondary: string,
    [@bs.optional]
    bar: string,
    [@bs.optional]
    barColorPrimary: string,
    [@bs.optional]
    barColorSecondary: string,
    [@bs.optional]
    bar1Indeterminate: string,
    [@bs.optional]
    bar1Determinate: string,
    [@bs.optional]
    bar1Buffer: string,
    [@bs.optional]
    bar2Indeterminate: string,
    [@bs.optional]
    bar2Buffer: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~value: option(MaterialUi_Types.Number.t)=?,
    ~valueBuffer: option(MaterialUi_Types.Number.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "buffer"] `Buffer
                  | [@bs.as "determinate"] `Determinate
                  | [@bs.as "indeterminate"] `Indeterminate
                  | [@bs.as "query"] `Query
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "LinearProgress";
