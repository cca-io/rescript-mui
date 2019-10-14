[@bs.deriving jsConverter]
type align = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
  | [@bs.as "justify"] `Justify
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
type display = [
  | [@bs.as "initial"] `Initial
  | [@bs.as "block"] `Block
  | [@bs.as "inline"] `Inline
];

[@bs.deriving jsConverter]
type variant = [
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
];

module Classes = {
  type classesType =
    | Root(string)
    | Body2(string)
    | Body1(string)
    | Caption(string)
    | Button(string)
    | H1(string)
    | H2(string)
    | H3(string)
    | H4(string)
    | H5(string)
    | H6(string)
    | Subtitle1(string)
    | Subtitle2(string)
    | Overline(string)
    | SrOnly(string)
    | AlignLeft(string)
    | AlignCenter(string)
    | AlignRight(string)
    | AlignJustify(string)
    | NoWrap(string)
    | GutterBottom(string)
    | Paragraph(string)
    | ColorInherit(string)
    | ColorPrimary(string)
    | ColorSecondary(string)
    | ColorTextPrimary(string)
    | ColorTextSecondary(string)
    | ColorError(string)
    | DisplayInline(string)
    | DisplayBlock(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Body2(_) => "body2"
    | Body1(_) => "body1"
    | Caption(_) => "caption"
    | Button(_) => "button"
    | H1(_) => "h1"
    | H2(_) => "h2"
    | H3(_) => "h3"
    | H4(_) => "h4"
    | H5(_) => "h5"
    | H6(_) => "h6"
    | Subtitle1(_) => "subtitle1"
    | Subtitle2(_) => "subtitle2"
    | Overline(_) => "overline"
    | SrOnly(_) => "srOnly"
    | AlignLeft(_) => "alignLeft"
    | AlignCenter(_) => "alignCenter"
    | AlignRight(_) => "alignRight"
    | AlignJustify(_) => "alignJustify"
    | NoWrap(_) => "noWrap"
    | GutterBottom(_) => "gutterBottom"
    | Paragraph(_) => "paragraph"
    | ColorInherit(_) => "colorInherit"
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | ColorTextPrimary(_) => "colorTextPrimary"
    | ColorTextSecondary(_) => "colorTextSecondary"
    | ColorError(_) => "colorError"
    | DisplayInline(_) => "displayInline"
    | DisplayBlock(_) => "displayBlock";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Body2(className)
                         | Body1(className)
                         | Caption(className)
                         | Button(className)
                         | H1(className)
                         | H2(className)
                         | H3(className)
                         | H4(className)
                         | H5(className)
                         | H6(className)
                         | Subtitle1(className)
                         | Subtitle2(className)
                         | Overline(className)
                         | SrOnly(className)
                         | AlignLeft(className)
                         | AlignCenter(className)
                         | AlignRight(className)
                         | AlignJustify(className)
                         | NoWrap(className)
                         | GutterBottom(className)
                         | Paragraph(className)
                         | ColorInherit(className)
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | ColorTextPrimary(className)
                         | ColorTextSecondary(className)
                         | ColorError(className)
                         | DisplayInline(className)
                         | DisplayBlock(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_rn5h=?,
    ~display: string=?,
    ~gutterBottom: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~variant: string=?,
    ~variantMapping: Js.t({..})=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~align: option(align)=?,
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
      ~display: option(display)=?,
      ~gutterBottom: option(bool)=?,
      ~noWrap: option(bool)=?,
      ~paragraph: option(bool)=?,
      ~variant: option(variant)=?,
      ~variantMapping: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~align=?align->(Belt.Option.map(v => alignToJs(v))),
    ~children?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~display=?display->(Belt.Option.map(v => displayToJs(v))),
    ~gutterBottom?,
    ~noWrap?,
    ~paragraph?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~variantMapping?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Typography";
