module Classes = {
  type t = {
    .
    "root": option(string),
    "multiline": option(string),
    "dense": option(string),
    "inset": option(string),
    "primary": option(string),
    "secondary": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~multiline: string=?,
      ~dense: string=?,
      ~inset: string=?,
      ~primary: string=?,
      ~secondary: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disableTypography: bool=?,
    ~inset: bool=?,
    ~primary: React.element=?,
    ~primaryTypographyProps: Js.t({..})=?,
    ~secondary: React.element=?,
    ~secondaryTypographyProps: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ListItemText";
