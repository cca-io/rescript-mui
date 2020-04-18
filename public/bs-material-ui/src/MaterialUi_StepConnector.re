module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    horizontal: string,
    [@bs.optional]
    vertical: string,
    [@bs.optional]
    alternativeLabel: string,
    [@bs.optional]
    active: string,
    [@bs.optional]
    completed: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    line: string,
    [@bs.optional]
    lineHorizontal: string,
    [@bs.optional]
    lineVertical: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~active: option(bool)=?,
    ~alternativeLabel: option(bool)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~completed: option(bool)=?,
    ~disabled: option(bool)=?,
    ~index: option(MaterialUi_Types.Number.t)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "horizontal"] `Horizontal
                      | [@bs.as "vertical"] `Vertical
                    ],
                  )
                    =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "StepConnector";
