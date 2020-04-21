module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "ul": option(option(string)),
  };
  [@bs.obj] external make: (~root: string=?, ~ul: string=?, unit) => t;
};

type color = [ | `Primary | `Secondary | `Standard];

type shape = [ | `Round | `Rounded];

type size = [ | `Large | `Medium | `Small];

type variant = [ | `Outlined | `Text];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~boundaryCount: option(MaterialUi_Types.Number.t)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
                | [@bs.as "standard"] `Standard
              ],
            )
              =?,
    ~count: option(MaterialUi_Types.Number.t)=?,
    ~defaultPage: option(MaterialUi_Types.Number.t)=?,
    ~disabled: option(bool)=?,
    ~getItemAriaLabel: option((string, int, bool) => string)=?,
    ~hideNextButton: option(bool)=?,
    ~hidePrevButton: option(bool)=?,
    ~onChange: option((ReactEvent.Form.t, int) => unit)=?,
    ~page: option(MaterialUi_Types.Number.t)=?,
    ~renderItem: option(unit => MaterialUi_Types.any)=?,
    ~shape: option(
              [@bs.string] [
                | [@bs.as "round"] `Round
                | [@bs.as "rounded"] `Rounded
              ],
            )
              =?,
    ~showFirstButton: option(bool)=?,
    ~showLastButton: option(bool)=?,
    ~siblingCount: option(MaterialUi_Types.Number.t)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "large"] `Large
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "text"] `Text
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Pagination";
