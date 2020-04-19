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
    ~component: 'union_r4f6=?,
    ~indicatorColor: string=?,
    ~onChange: 'any_rhdk=?,
    ~orientation: string=?,
    ~_ScrollButtonComponent: 'union_r6en=?,
    ~scrollButtons: string=?,
    ~_TabIndicatorProps: Js.t({..})=?,
    ~textColor: string=?,
    ~value: 'any_rfpg=?,
    ~variant: string=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

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
             | `Element(React.element)
           ],
         )=?,
      ~indicatorColor: option(indicatorColor)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_r670) => unit)=?,
      ~orientation: option(orientation)=?,
      ~_ScrollButtonComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~scrollButtons: option(scrollButtons)=?,
      ~_TabIndicatorProps: option(Js.t({..}))=?,
      ~textColor: option(textColor)=?,
      ~value: option('any_rfpg)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
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
      indicatorColor->Belt.Option.map(v => indicatorColorToJs(v)),
    ~onChange?,
    ~orientation=?orientation->Belt.Option.map(v => orientationToJs(v)),
    ~_ScrollButtonComponent=?
      _ScrollButtonComponent->(
                                Belt.Option.map(v =>
                                  MaterialUi_Helpers.unwrapValue(v)
                                )
                              ),
    ~scrollButtons=?scrollButtons->Belt.Option.map(v => scrollButtonsToJs(v)),
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
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Tabs";
