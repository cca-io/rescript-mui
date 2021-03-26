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
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "CardActions";
