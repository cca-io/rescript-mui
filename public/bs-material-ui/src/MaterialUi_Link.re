[@bs.deriving jsConverter]
type align = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
  | [@bs.as "justify"] `Justify
];

[@bs.deriving jsConverter]
type display = [
  | [@bs.as "initial"] `Initial
  | [@bs.as "block"] `Block
  | [@bs.as "inline"] `Inline
];

[@bs.deriving jsConverter]
type color = [
  | [@bs.as "initial"] `Initial
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "textPrimary"] `TextPrimary
  | [@bs.as "textSecondary"] `TextSecondary
  | [@bs.as "error"] `Error
];

[@bs.deriving jsConverter]
type underline = [
  | [@bs.as "none"] `None
  | [@bs.as "hover"] `Hover
  | [@bs.as "always"] `Always
];

[@bs.deriving jsConverter]
type rel = [
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
];

module Classes = {
  type classesType =
    | Root(string)
    | UnderlineNone(string)
    | UnderlineHover(string)
    | UnderlineAlways(string)
    | Button(string)
    | FocusVisible(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | UnderlineNone(_) => "underlineNone"
    | UnderlineHover(_) => "underlineHover"
    | UnderlineAlways(_) => "underlineAlways"
    | Button(_) => "button"
    | FocusVisible(_) => "focusVisible";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | UnderlineNone(className)
                         | UnderlineHover(className)
                         | UnderlineAlways(className)
                         | Button(className)
                         | FocusVisible(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~align: string=?,
    ~display: string=?,
    ~gutterBottom: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~variantMapping: Js.t({..})=?,
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_rqn7=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~_TypographyClasses: Js.t({..})=?,
    ~underline: string=?,
    ~variant: string=?,
    ~id: string=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~href: string=?,
    ~target: string=?,
    ~rel: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~align: option(align)=?,
      ~display: option(display)=?,
      ~gutterBottom: option(bool)=?,
      ~noWrap: option(bool)=?,
      ~paragraph: option(bool)=?,
      ~variantMapping: option(Js.t({..}))=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~_TypographyClasses: option(Js.t({..}))=?,
      ~underline: option(underline)=?,
      ~variant: option(string)=?,
      ~id: option(string)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~href: option(string)=?,
      ~target: option(string)=?,
      ~rel: option(rel)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~align=?align->Belt.Option.map(v => alignToJs(v)),
    ~display=?display->Belt.Option.map(v => displayToJs(v)),
    ~gutterBottom?,
    ~noWrap?,
    ~paragraph?,
    ~variantMapping?,
    ~children?,
    ~className?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~onBlur?,
    ~onFocus?,
    ~_TypographyClasses?,
    ~underline=?underline->Belt.Option.map(v => underlineToJs(v)),
    ~variant?,
    ~id?,
    ~onClick?,
    ~href?,
    ~target?,
    ~rel=?rel->Belt.Option.map(v => relToJs(v)),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Link";
