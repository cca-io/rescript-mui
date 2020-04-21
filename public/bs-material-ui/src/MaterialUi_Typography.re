type align = [ | `Inherit | `Left | `Center | `Right | `Justify];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "body2": option(option(string)),
    "body1": option(option(string)),
    "caption": option(option(string)),
    "button": option(option(string)),
    "h1": option(option(string)),
    "h2": option(option(string)),
    "h3": option(option(string)),
    "h4": option(option(string)),
    "h5": option(option(string)),
    "h6": option(option(string)),
    "subtitle1": option(option(string)),
    "subtitle2": option(option(string)),
    "overline": option(option(string)),
    "srOnly": option(option(string)),
    "alignLeft": option(option(string)),
    "alignCenter": option(option(string)),
    "alignRight": option(option(string)),
    "alignJustify": option(option(string)),
    "noWrap": option(option(string)),
    "gutterBottom": option(option(string)),
    "paragraph": option(option(string)),
    "colorInherit": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "colorTextPrimary": option(option(string)),
    "colorTextSecondary": option(option(string)),
    "colorError": option(option(string)),
    "displayInline": option(option(string)),
    "displayBlock": option(option(string)),
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
    ~align: option(
              [@bs.string] [
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "left"] `Left
                | [@bs.as "center"] `Center
                | [@bs.as "right"] `Right
                | [@bs.as "justify"] `Justify
              ],
            )
              =?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "initial"] `Initial
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
                | [@bs.as "textPrimary"] `TextPrimary
                | [@bs.as "textSecondary"] `TextSecondary
                | [@bs.as "error"] `Error
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~display: option(
                [@bs.string] [
                  | [@bs.as "initial"] `Initial
                  | [@bs.as "block"] `Block
                  | [@bs.as "inline"] `Inline
                ],
              )
                =?,
    ~gutterBottom: option(bool)=?,
    ~noWrap: option(bool)=?,
    ~paragraph: option(bool)=?,
    ~variant: option(
                [@bs.string] [
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
                ],
              )
                =?,
    ~variantMapping: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Typography";
