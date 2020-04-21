module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "text": option(option(string)),
    "active": option(option(string)),
    "completed": option(option(string)),
    "error": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~text: string=?,
      ~active: string=?,
      ~completed: string=?,
      ~error: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~active: option(bool)=?,
    ~classes: option(Classes.t)=?,
    ~completed: option(bool)=?,
    ~error: option(bool)=?,
    ~icon: option(React.element)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "StepIcon";
