module Classes = {
  type t = {
    .
    "root": option(string),
    "row": option(string),
  };
  [@bs.obj] external make: (~root: string=?, ~row: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~row: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "FormGroup";
