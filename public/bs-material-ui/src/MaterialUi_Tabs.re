[@bs.deriving jsConverter]
type indicatorColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
];

[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
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
    | Vertical(string)
    | FlexContainer(string)
    | FlexContainerVertical(string)
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
    | Vertical(_) => "vertical"
    | FlexContainer(_) => "flexContainer"
    | FlexContainerVertical(_) => "flexContainerVertical"
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
                         | Vertical(className)
                         | FlexContainer(className)
                         | FlexContainerVertical(className)
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
    ~centered: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_rq4k=?,
    ~indicatorColor: string=?,
    ~onChange: 'any_rdyv=?,
    ~orientation: string=?,
    ~_ScrollButtonComponent: 'union_rfax=?,
    ~scrollButtons: string=?,
    ~_TabIndicatorProps: Js.t({..})=?,
    ~textColor: string=?,
    ~value: 'any_rpqx=?,
    ~variant: string=?,
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
      ~centered: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.reactElement)
           ],
         )=?,
      ~indicatorColor: option(indicatorColor)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_rlr8) => unit)=?,
      ~orientation: option(orientation)=?,
      ~_ScrollButtonComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.reactElement)
           ],
         )=?,
      ~scrollButtons: option(scrollButtons)=?,
      ~_TabIndicatorProps: option(Js.t({..}))=?,
      ~textColor: option(textColor)=?,
      ~value: option('any_rpqx)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~centered?,
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~indicatorColor=?
      indicatorColor->(Belt.Option.map(v => indicatorColorToJs(v))),
    ~onChange?,
    ~orientation=?orientation->(Belt.Option.map(v => orientationToJs(v))),
    ~_ScrollButtonComponent=?
      _ScrollButtonComponent->(
                                Belt.Option.map(v =>
                                  MaterialUi_Helpers.unwrapValue(v)
                                )
                              ),
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
    ~value?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Tabs";
