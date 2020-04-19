module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    icon: string,
    [@bs.optional]
    iconOpen: string,
    [@bs.optional]
    iconWithOpenIconOpen: string,
    [@bs.optional]
    openIcon: string,
    [@bs.optional]
    openIconOpen: string,
  };
  let make = t;
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
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "SpeedDialIcon";
