module Classes = {
  type t = {
    .
    "root": option(string),
    "text": option(string),
    "active": option(string),
    "completed": option(string),
    "error": option(string),
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
    ~active: bool=?,
    ~classes: Classes.t=?,
    ~completed: bool=?,
    ~error: bool=?,
    ~icon: React.element=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "StepIcon";
