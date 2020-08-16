type align = [ | `Inherit | `Left | `Center | `Right | `Justify];

module Classes = {
  type t = {
    .
    "root": option(string),
    "body2": option(string),
    "body1": option(string),
    "caption": option(string),
    "button": option(string),
    "h1": option(string),
    "h2": option(string),
    "h3": option(string),
    "h4": option(string),
    "h5": option(string),
    "h6": option(string),
    "subtitle1": option(string),
    "subtitle2": option(string),
    "overline": option(string),
    "srOnly": option(string),
    "alignLeft": option(string),
    "alignCenter": option(string),
    "alignRight": option(string),
    "alignJustify": option(string),
    "noWrap": option(string),
    "gutterBottom": option(string),
    "paragraph": option(string),
    "colorInherit": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "colorTextPrimary": option(string),
    "colorTextSecondary": option(string),
    "colorError": option(string),
    "displayInline": option(string),
    "displayBlock": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~body2: string=?,
      ~body1: string=?,
      ~caption: string=?,
      ~button: string=?,
      ~h1: string=?,
      ~h2: string=?,
      ~h3: string=?,
      ~h4: string=?,
      ~h5: string=?,
      ~h6: string=?,
      ~subtitle1: string=?,
      ~subtitle2: string=?,
      ~overline: string=?,
      ~srOnly: string=?,
      ~alignLeft: string=?,
      ~alignCenter: string=?,
      ~alignRight: string=?,
      ~alignJustify: string=?,
      ~noWrap: string=?,
      ~gutterBottom: string=?,
      ~paragraph: string=?,
      ~colorInherit: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~colorTextPrimary: string=?,
      ~colorTextSecondary: string=?,
      ~colorError: string=?,
      ~displayInline: string=?,
      ~displayBlock: string=?,
      unit
    ) =>
    t;
};

type color = [
  | `Initial
  | `Inherit
  | `Primary
  | `Secondary
  | `TextPrimary
  | `TextSecondary
  | `Error
];

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

type display = [ | `Initial | `Block | `Inline];

type variant = [
  | `H1
  | `H2
  | `H3
  | `H4
  | `H5
  | `H6
  | `Subtitle1
  | `Subtitle2
  | `Body1
  | `Body2
  | `Caption
  | `Button
  | `Overline
  | `SrOnly
  | `Inherit
];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~align: [@bs.string] [
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "left"] `Left
              | [@bs.as "center"] `Center
              | [@bs.as "right"] `Right
              | [@bs.as "justify"] `Justify
            ]
              =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "initial"] `Initial
              | [@bs.as "inherit"] `Inherit
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
              | [@bs.as "textPrimary"] `TextPrimary
              | [@bs.as "textSecondary"] `TextSecondary
              | [@bs.as "error"] `Error
            ]
              =?,
    ~component: Component.t=?,
    ~display: [@bs.string] [
                | [@bs.as "initial"] `Initial
                | [@bs.as "block"] `Block
                | [@bs.as "inline"] `Inline
              ]
                =?,
    ~gutterBottom: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "h1"] `H1
                | [@bs.as "h2"] `H2
                | [@bs.as "h3"] `H3
                | [@bs.as "h4"] `H4
                | [@bs.as "h5"] `H5
                | [@bs.as "h6"] `H6
                | [@bs.as "subtitle1"] `Subtitle1
                | [@bs.as "subtitle2"] `Subtitle2
                | [@bs.as "body1"] `Body1
                | [@bs.as "body2"] `Body2
                | [@bs.as "caption"] `Caption
                | [@bs.as "button"] `Button
                | [@bs.as "overline"] `Overline
                | [@bs.as "srOnly"] `SrOnly
                | [@bs.as "inherit"] `Inherit
              ]
                =?,
    ~variantMapping: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Typography";
