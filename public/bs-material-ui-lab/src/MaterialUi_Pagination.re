module Classes = {
  type t = {
    .
    "root": option(string),
    "ul": option(string),
  };
  [@bs.obj] external make: (~root: string=?, ~ul: string=?, unit) => t;
};

type color = [ | `Primary | `Secondary | `Standard];

module Color: {
  type t;
  let primary: t;
  let secondary: t;
  let standard: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let primary = Any("primary");
  let secondary = Any("secondary");
  let standard = Any("standard");
};

module Shape: {
  type t;
  let round: t;
  let rounded: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let round = Any("round");
  let rounded = Any("rounded");
};

module Size: {
  type t;
  let large: t;
  let medium: t;
  let small: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let large = Any("large");
  let medium = Any("medium");
  let small = Any("small");
};

module Variant: {
  type t;
  let outlined: t;
  let text: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let outlined = Any("outlined");
  let text = Any("text");
};

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
    ~renderItem: {
                   .
                   "color": Color.t,
                   "shape": Shape.t,
                   "size": Size.t,
                   "variant": Variant.t,
                   "page": int,
                   "selected": bool,
                   "disabled": bool,
                 } =>
                 React.element
                   =?,
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
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Pagination";
