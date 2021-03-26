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

type variant = [ | `Elevation | `Outlined];

module Classes = {
  type t = {
    .
    "root": option(string),
    "positionFixed": option(string),
    "positionAbsolute": option(string),
    "positionSticky": option(string),
    "positionStatic": option(string),
    "positionRelative": option(string),
    "colorDefault": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "colorInherit": option(string),
    "colorTransparent": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~positionFixed: string=?,
      ~positionAbsolute: string=?,
      ~positionSticky: string=?,
      ~positionStatic: string=?,
      ~positionRelative: string=?,
      ~colorDefault: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~colorInherit: string=?,
      ~colorTransparent: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Inherit | `Primary | `Secondary | `Transparent];

type position = [ | `Absolute | `Fixed | `Relative | `Static | `Sticky];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: Component.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~square: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "elevation"] `Elevation
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "default"] `Default
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
              | [@bs.as "transparent"] `Transparent
            ]
              =?,
    ~position: [@bs.string] [
                 | [@bs.as "absolute"] `Absolute
                 | [@bs.as "fixed"] `Fixed
                 | [@bs.as "relative"] `Relative
                 | [@bs.as "static"] `Static
                 | [@bs.as "sticky"] `Sticky
               ]
                 =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "AppBar";
