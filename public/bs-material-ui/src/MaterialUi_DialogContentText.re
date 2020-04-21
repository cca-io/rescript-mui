type align = [ | `Inherit | `Left | `Center | `Right | `Justify];

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

module Classes = {
  type t = {. "root": option(option(string))};
  [@bs.obj] external make: (~root: string=?, unit) => t;
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
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "DialogContentText";
