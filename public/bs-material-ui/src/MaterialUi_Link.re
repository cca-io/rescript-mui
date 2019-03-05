[@bs.deriving jsConverter]
type color = [
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

module Classes = {
  type classesType =
    | Root(string)
    | UnderlineNone(string)
    | UnderlineHover(string)
    | UnderlineAlways(string)
    | Button(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | UnderlineNone(_) => "underlineNone"
    | UnderlineHover(_) => "underlineHover"
    | UnderlineAlways(_) => "underlineAlways"
    | Button(_) => "button";
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
                         | Button(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makeProps:
  (
    ~block: bool=?,
    ~className: string=?,
    ~color: string=?,
    ~_TypographyClasses: Js.t({..})=?,
    ~underline: string=?,
    ~variant: string=?,
    ~align: string=?,
    ~gutterBottom: bool=?,
    ~headlineMapping: Js.t({..})=?,
    ~inline: bool=?,
    ~internalDeprecatedVariant: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~theme: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Link";
let make =
    (
      ~block: option(bool)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~_TypographyClasses: option(Js.t({..}))=?,
      ~underline: option(underline)=?,
      ~variant: option(string)=?,
      ~align: option(align)=?,
      ~gutterBottom: option(bool)=?,
      ~headlineMapping: option(Js.t({..}))=?,
      ~inline: option(bool)=?,
      ~internalDeprecatedVariant: option(bool)=?,
      ~noWrap: option(bool)=?,
      ~paragraph: option(bool)=?,
      ~theme: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~block?,
        ~className?,
        ~color=?color->(Belt.Option.map(v => colorToJs(v))),
        ~_TypographyClasses?,
        ~underline=?underline->(Belt.Option.map(v => underlineToJs(v))),
        ~variant?,
        ~align=?align->(Belt.Option.map(v => alignToJs(v))),
        ~gutterBottom?,
        ~headlineMapping?,
        ~inline?,
        ~internalDeprecatedVariant?,
        ~noWrap?,
        ~paragraph?,
        ~theme?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
