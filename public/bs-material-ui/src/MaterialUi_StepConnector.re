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
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "StepConnector";
