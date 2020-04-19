module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "AlertTitle";
