module Classes = {
  type t = {
    .
    "root": option(string),
    "vertical": option(string),
    "disabled": option(string),
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
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~direction: [@bs.string] [
                  | [@bs.as "left"] `Left
                  | [@bs.as "right"] `Right
                ],
    ~disabled: bool=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ],
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "TabScrollButton";
