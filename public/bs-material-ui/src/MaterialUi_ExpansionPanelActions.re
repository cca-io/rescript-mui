module Classes = {
  type t = {
    .
    "root": option(string),
    "spacing": option(string),
  };
  [@bs.obj] external make: (~root: string=?, ~spacing: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disableSpacing: bool=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ExpansionPanelActions";
