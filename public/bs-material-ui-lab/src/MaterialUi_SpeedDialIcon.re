module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "icon": option(option(string)),
    "iconOpen": option(option(string)),
    "iconWithOpenIconOpen": option(option(string)),
    "openIcon": option(option(string)),
    "openIconOpen": option(option(string)),
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
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~icon: option(React.element)=?,
    ~_open: option(bool)=?,
    ~openIcon: option(React.element)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "SpeedDialIcon";
