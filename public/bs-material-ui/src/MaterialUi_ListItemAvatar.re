module Classes = {
  type t = {
    .
    "root": option(string),
    "alignItemsFlexStart": option(string),
  };
  [@bs.obj]
  external make: (~root: string=?, ~alignItemsFlexStart: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ListItemAvatar";
