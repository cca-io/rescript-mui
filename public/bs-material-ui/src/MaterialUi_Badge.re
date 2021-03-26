module Horizontal: {
  type t;
  let left: t;
  let right: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let left = Any("left");
  let right = Any("right");
};

module Vertical: {
  type t;
  let bottom: t;
  let top: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let bottom = Any("bottom");
  let top = Any("top");
};

module AnchorOrigin = {
  type t = {
    .
    "horizontal": option(Horizontal.t),
    "vertical": option(Vertical.t),
  };
  [@bs.obj]
  external make:
    (~horizontal: Horizontal.t=?, ~vertical: Vertical.t=?, unit) => t;
};

module Classes = {
  type t = {
    .
    "root": option(string),
    "badge": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "colorError": option(string),
    "dot": option(string),
    "anchorOriginTopRightRectangle": option(string),
    "anchorOriginBottomRightRectangle": option(string),
    "anchorOriginTopLeftRectangle": option(string),
    "anchorOriginBottomLeftRectangle": option(string),
    "anchorOriginTopRightCircle": option(string),
    "anchorOriginBottomRightCircle": option(string),
    "anchorOriginTopLeftCircle": option(string),
    "anchorOriginBottomLeftCircle": option(string),
    "invisible": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~badge: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~colorError: string=?,
      ~dot: string=?,
      ~anchorOriginTopRightRectangle: string=?,
      ~anchorOriginBottomRightRectangle: string=?,
      ~anchorOriginTopLeftRectangle: string=?,
      ~anchorOriginBottomLeftRectangle: string=?,
      ~anchorOriginTopRightCircle: string=?,
      ~anchorOriginBottomRightCircle: string=?,
      ~anchorOriginTopLeftCircle: string=?,
      ~anchorOriginBottomLeftCircle: string=?,
      ~invisible: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Error | `Primary | `Secondary];

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

type overlap = [ | `Circle | `Rectangle];

type variant = [ | `Dot | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~anchorOrigin: AnchorOrigin.t=?,
    ~badgeContent: React.element=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "default"] `Default
              | [@bs.as "error"] `Error
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~component: Component.t=?,
    ~invisible: bool=?,
    ~max: MaterialUi_Types.Number.t=?,
    ~overlap: [@bs.string] [
                | [@bs.as "circle"] `Circle
                | [@bs.as "rectangle"] `Rectangle
              ]
                =?,
    ~showZero: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "dot"] `Dot
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Badge";
