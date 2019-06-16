[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "error"] `Error
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "textPrimary"] `TextPrimary
  | [@bs.as "textSecondary"] `TextSecondary
];

[@bs.deriving jsConverter]
type underline = [
  | [@bs.as "none"] `None
  | [@bs.as "hover"] `Hover
  | [@bs.as "always"] `Always
];

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
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~_TypographyClasses: Js.t({..})=?,
    ~underline: string=?,
    ~variant: string=?,
    ~align: string=?,
    ~display: string=?,
    ~gutterBottom: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~theme: Js.t({..})=?,
    ~variantMapping: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Link";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~_TypographyClasses: option(Js.t({..}))=?,
      ~underline: option(underline)=?,
      ~variant: option(string)=?,
      ~align: option(align)=?,
      ~display: option(display)=?,
      ~gutterBottom: option(bool)=?,
      ~noWrap: option(bool)=?,
      ~paragraph: option(bool)=?,
      ~theme: option(Js.t({..}))=?,
      ~variantMapping: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~color=?color->(Belt.Option.map(v => colorToJs(v))),
      ~onBlur?,
      ~onFocus?,
      ~_TypographyClasses?,
      ~underline=?underline->(Belt.Option.map(v => underlineToJs(v))),
      ~variant?,
      ~align=?align->(Belt.Option.map(v => alignToJs(v))),
      ~display=?display->(Belt.Option.map(v => displayToJs(v))),
      ~gutterBottom?,
      ~noWrap?,
      ~paragraph?,
      ~theme?,
      ~variantMapping?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
