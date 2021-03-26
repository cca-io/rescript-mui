module Classes = {
  type t = {
    .
    "root": option(string),
    "horizontal": option(string),
    "vertical": option(string),
    "alternativeLabel": option(string),
    "active": option(string),
    "completed": option(string),
    "disabled": option(string),
    "line": option(string),
    "lineHorizontal": option(string),
    "lineVertical": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~horizontal: string=?,
      ~vertical: string=?,
      ~alternativeLabel: string=?,
      ~active: string=?,
      ~completed: string=?,
      ~disabled: string=?,
      ~line: string=?,
      ~lineHorizontal: string=?,
      ~lineVertical: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~classes: Classes.t=?,
    ~className: string=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "StepConnector";
