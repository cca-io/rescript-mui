module Classes = {
  type t = {
    .
    "root": option(string),
    "ul": option(string),
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
    ~boundaryCount: MaterialUi_Types.Number.t=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
              | [@bs.as "standard"] `Standard
            ]
              =?,
    ~count: MaterialUi_Types.Number.t=?,
    ~defaultPage: MaterialUi_Types.Number.t=?,
    ~disabled: bool=?,
    ~getItemAriaLabel: (string, int, bool) => string=?,
    ~hideNextButton: bool=?,
    ~hidePrevButton: bool=?,
    ~onChange: (ReactEvent.Form.t, int) => unit=?,
    ~page: MaterialUi_Types.Number.t=?,
    ~renderItem: unit => MaterialUi_Types.any=?,
    ~shape: [@bs.string] [
              | [@bs.as "round"] `Round
              | [@bs.as "rounded"] `Rounded
            ]
              =?,
    ~showFirstButton: bool=?,
    ~showLastButton: bool=?,
    ~siblingCount: MaterialUi_Types.Number.t=?,
    ~size: [@bs.string] [
             | [@bs.as "large"] `Large
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~variant: [@bs.string] [
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "text"] `Text
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Pagination";
