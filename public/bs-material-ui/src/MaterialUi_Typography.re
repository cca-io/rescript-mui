module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    body2: string,
    [@bs.optional]
    body1: string,
    [@bs.optional]
    caption: string,
    [@bs.optional]
    button: string,
    [@bs.optional]
    h1: string,
    [@bs.optional]
    h2: string,
    [@bs.optional]
    h3: string,
    [@bs.optional]
    h4: string,
    [@bs.optional]
    h5: string,
    [@bs.optional]
    h6: string,
    [@bs.optional]
    subtitle1: string,
    [@bs.optional]
    subtitle2: string,
    [@bs.optional]
    overline: string,
    [@bs.optional]
    srOnly: string,
    [@bs.optional]
    alignLeft: string,
    [@bs.optional]
    alignCenter: string,
    [@bs.optional]
    alignRight: string,
    [@bs.optional]
    alignJustify: string,
    [@bs.optional]
    noWrap: string,
    [@bs.optional]
    gutterBottom: string,
    [@bs.optional]
    paragraph: string,
    [@bs.optional]
    colorInherit: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    colorTextPrimary: string,
    [@bs.optional]
    colorTextSecondary: string,
    [@bs.optional]
    colorError: string,
    [@bs.optional]
    displayInline: string,
    [@bs.optional]
    displayBlock: string,
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
