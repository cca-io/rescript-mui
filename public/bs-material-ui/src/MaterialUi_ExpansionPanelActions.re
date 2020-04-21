module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "spacing": option(option(string)),
  };
  [@bs.obj] external make: (~root: string=?, ~spacing: string=?, unit) => t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disableSpacing: option(bool)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ExpansionPanelActions";
