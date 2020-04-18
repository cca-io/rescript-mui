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
  [@bs.deriving abstract]
  type t = {
    horizontal: Horizontal.t,
    vertical: Vertical.t,
  };
  let make = t;
};

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    badge: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    colorError: string,
    [@bs.optional]
    dot: string,
    [@bs.optional]
    anchorOriginTopRightRectangle: string,
    [@bs.optional]
    anchorOriginBottomRightRectangle: string,
    [@bs.optional]
    anchorOriginTopLeftRectangle: string,
    [@bs.optional]
    anchorOriginBottomLeftRectangle: string,
    [@bs.optional]
    anchorOriginTopRightCircle: string,
    [@bs.optional]
    anchorOriginBottomRightCircle: string,
    [@bs.optional]
    anchorOriginTopLeftCircle: string,
    [@bs.optional]
    anchorOriginBottomLeftCircle: string,
    [@bs.optional]
    invisible: string,
  };
  let make = t;
};

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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~anchorOrigin: option(AnchorOrigin.t)=?,
    ~badgeContent: option(React.element)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "error"] `Error
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~invisible: option(bool)=?,
    ~max: option(MaterialUi_Types.Number.t)=?,
    ~overlap: option(
                [@bs.string] [
                  | [@bs.as "circle"] `Circle
                  | [@bs.as "rectangle"] `Rectangle
                ],
              )
                =?,
    ~showZero: option(bool)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "dot"] `Dot
                  | [@bs.as "standard"] `Standard
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Badge";
