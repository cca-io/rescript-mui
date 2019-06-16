[@bs.deriving jsConverter]
type indicatorColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
];

[@bs.deriving jsConverter]
type scrollButtons = [
  | [@bs.as "auto"] `Auto
  | [@bs.as "desktop"] `Desktop
  | [@bs.as "on"] `On
  | [@bs.as "off"] `Off
];

[@bs.deriving jsConverter]
type textColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
  | [@bs.as "inherit"] `Inherit
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "scrollable"] `Scrollable
  | [@bs.as "fullWidth"] `FullWidth
];

module Classes = {
  type classesType =
    | Root(string)
    | FlexContainer(string)
    | Centered(string)
    | Scroller(string)
    | Fixed(string)
    | Scrollable(string)
    | ScrollButtons(string)
    | ScrollButtonsDesktop(string)
    | Indicator(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FlexContainer(_) => "flexContainer"
    | Centered(_) => "centered"
    | Scroller(_) => "scroller"
    | Fixed(_) => "fixed"
    | Scrollable(_) => "scrollable"
    | ScrollButtons(_) => "scrollButtons"
    | ScrollButtonsDesktop(_) => "scrollButtonsDesktop"
    | Indicator(_) => "indicator";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | FlexContainer(className)
                         | Centered(className)
                         | Scroller(className)
                         | Fixed(className)
                         | Scrollable(className)
                         | ScrollButtons(className)
                         | ScrollButtonsDesktop(className)
                         | Indicator(className) =>
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
    ~action: 'any_r28y=?,
    ~centered: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~indicatorColor: string=?,
    ~innerRef: 'union_ru92=?,
    ~onChange: 'any_r661=?,
    ~scrollButtons: string=?,
    ~_TabIndicatorProps: Js.t({..})=?,
    ~textColor: string=?,
    ~theme: Js.t({..})=?,
    ~value: 'any_r0ad=?,
    ~variant: string=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~action: option(Js.t({..}) => unit)=?,
      ~centered: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~indicatorColor: option(indicatorColor)=?,
      ~innerRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~onChange: option((ReactEvent.Form.t, 'any_r5xv) => unit)=?,
      ~scrollButtons: option(scrollButtons)=?,
      ~_TabIndicatorProps: option(Js.t({..}))=?,
      ~textColor: option(textColor)=?,
      ~theme: option(Js.t({..}))=?,
      ~value: option('any_r0ad)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~action?,
    ~centered?,
    ~children?,
    ~className?,
    ~indicatorColor=?
      indicatorColor->(Belt.Option.map(v => indicatorColorToJs(v))),
    ~innerRef=?
      innerRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~onChange?,
    ~scrollButtons=?
      scrollButtons->(Belt.Option.map(v => scrollButtonsToJs(v))),
    ~_TabIndicatorProps?,
    ~textColor=?
      textColor->(
                   Belt.Option.map(v =>
                     switch (v->Obj.magic->Js.Json.classify) {
                     | JSONString(str) => str
                     | _ => textColorToJs(v)
                     }
                   )
                 ),
    ~theme?,
    ~value?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Tabs";
