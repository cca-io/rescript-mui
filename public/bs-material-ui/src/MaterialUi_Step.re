module Classes = {
  type t = {
    .
    "root": option(string),
    "horizontal": option(string),
    "vertical": option(string),
    "alternativeLabel": option(string),
    "completed": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~horizontal: string=?,
      ~vertical: string=?,
      ~alternativeLabel: string=?,
      ~completed: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~active: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~completed: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Step";
