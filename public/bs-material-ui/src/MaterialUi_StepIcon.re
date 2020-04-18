module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    text: string,
    [@bs.optional]
    active: string,
    [@bs.optional]
    completed: string,
    [@bs.optional]
    error: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~active: option(bool)=?,
    ~classes: option(Classes.t)=?,
    ~completed: option(bool)=?,
    ~error: option(bool)=?,
    ~icon: React.element,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "StepIcon";
