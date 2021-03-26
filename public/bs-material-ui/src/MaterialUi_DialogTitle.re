module Classes = {
  type t = {. "root": option(string)};
  [@bs.obj] external make: (~root: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disableTypography: bool=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "DialogTitle";
