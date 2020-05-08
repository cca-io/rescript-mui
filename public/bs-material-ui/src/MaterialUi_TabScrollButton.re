module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "vertical": option(option(string)),
    "disabled": option(option(string)),
  };
  [@bs.obj]
  external make:
    (~root: string=?, ~vertical: string=?, ~disabled: string=?, unit) => t;
};

type direction = [ | `Left | `Right];

type orientation = [ | `Horizontal | `Vertical];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~direction: [@bs.string] [
                  | [@bs.as "left"] `Left
                  | [@bs.as "right"] `Right
                ],
    ~disabled: option(bool)=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ],
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TabScrollButton";
