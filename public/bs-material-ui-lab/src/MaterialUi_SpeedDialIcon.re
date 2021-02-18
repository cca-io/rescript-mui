module Classes = {
  type t = {
    .
    "root": option(string),
    "icon": option(string),
    "iconOpen": option(string),
    "iconWithOpenIconOpen": option(string),
    "openIcon": option(string),
    "openIconOpen": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~icon: string=?,
      ~iconOpen: string=?,
      ~iconWithOpenIconOpen: string=?,
      ~openIcon: string=?,
      ~openIconOpen: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~classes: Classes.t=?,
    ~className: string=?,
    ~icon: React.element=?,
    ~_open: bool=?,
    ~openIcon: React.element=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "SpeedDialIcon";
