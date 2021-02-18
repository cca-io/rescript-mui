type align = [ | `Inherit | `Left | `Center | `Right | `Justify];

type display = [ | `Initial | `Block | `Inline];

module Classes = {
  type t = {
    .
    "root": option(string),
    "underlineNone": option(string),
    "underlineHover": option(string),
    "underlineAlways": option(string),
    "button": option(string),
    "focusVisible": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~underlineNone: string=?,
      ~underlineHover: string=?,
      ~underlineAlways: string=?,
      ~button: string=?,
      ~focusVisible: string=?,
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

type underline = [ | `None | `Hover | `Always];

type rel = [
  | `Alternate
  | `Author
  | `Bookmark
  | `External
  | `Help
  | `License
  | `Next
  | `Nofollow
  | `Noreferrer
  | `Noopener
  | `Prev
  | `Search
  | `Tag
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
    ~display: [@bs.string] [
                | [@bs.as "initial"] `Initial
                | [@bs.as "block"] `Block
                | [@bs.as "inline"] `Inline
              ]
                =?,
    ~gutterBottom: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~variantMapping: Js.t({..})=?,
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
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~_TypographyClasses: Js.t({..})=?,
    ~underline: [@bs.string] [
                  | [@bs.as "none"] `None
                  | [@bs.as "hover"] `Hover
                  | [@bs.as "always"] `Always
                ]
                  =?,
    ~variant: string=?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~href: string=?,
    ~target: string=?,
    ~rel: [@bs.string] [
            | [@bs.as "alternate"] `Alternate
            | [@bs.as "author"] `Author
            | [@bs.as "bookmark"] `Bookmark
            | [@bs.as "external"] `External
            | [@bs.as "help"] `Help
            | [@bs.as "license"] `License
            | [@bs.as "next"] `Next
            | [@bs.as "nofollow"] `Nofollow
            | [@bs.as "noreferrer"] `Noreferrer
            | [@bs.as "noopener"] `Noopener
            | [@bs.as "prev"] `Prev
            | [@bs.as "search"] `Search
            | [@bs.as "tag"] `Tag
          ]
            =?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Link";
