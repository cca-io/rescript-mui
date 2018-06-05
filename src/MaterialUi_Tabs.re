[@bs.deriving jsConverter]
type indicatorColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
];

[@bs.deriving jsConverter]
type scrollButtons = [
  | [@bs.as "auto"] `Auto
  | [@bs.as "on"] `On
  | [@bs.as "off"] `Off
];

[@bs.deriving jsConverter]
type textColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
  | [@bs.as "inherit"] `Inherit
];

module Classes = {
  type classesType =
    | Root(string)
    | FlexContainer(string)
    | Scroller(string)
    | Fixed(string)
    | Scrollable(string)
    | Centered(string)
    | ScrollButtons(string)
    | ScrollButtonsAuto(string)
    | Indicator(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FlexContainer(_) => "flexContainer"
    | Scroller(_) => "scroller"
    | Fixed(_) => "fixed"
    | Scrollable(_) => "scrollable"
    | Centered(_) => "centered"
    | ScrollButtons(_) => "scrollButtons"
    | ScrollButtonsAuto(_) => "scrollButtonsAuto"
    | Indicator(_) => "indicator";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | FlexContainer(className)
           | Scroller(className)
           | Fixed(className)
           | Scrollable(className)
           | Centered(className)
           | ScrollButtons(className)
           | ScrollButtonsAuto(className)
           | Indicator(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~action: 'any_r0j1=?,
    ~centered: bool=?,
    ~className: string=?,
    ~fullWidth: bool=?,
    ~indicatorColor: string=?,
    ~onChange: 'any_rxha=?,
    ~scrollable: bool=?,
    ~_ScrollButtonComponent: 'union_r0sm=?,
    ~scrollButtons: string=?,
    ~_TabIndicatorProps: Js.t({..})=?,
    ~textColor: string=?,
    ~theme: Js.t({..})=?,
    ~value: 'any_rxy8=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/Tabs/Tabs"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~action: option(Js.t({..}) => unit)=?,
      ~centered: option(bool)=?,
      ~className: option(string)=?,
      ~fullWidth: option(bool)=?,
      ~indicatorColor: option(indicatorColor)=?,
      ~onChange: option((ReactEventRe.Form.t, int) => unit)=?,
      ~scrollable: option(bool)=?,
      ~_ScrollButtonComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~scrollButtons: option(scrollButtons)=?,
      ~_TabIndicatorProps: option(Js.t({..}))=?,
      ~textColor: option(textColor)=?,
      ~theme: option(Js.t({..}))=?,
      ~value: option('any_rxy8)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~centered?,
        ~className?,
        ~fullWidth?,
        ~indicatorColor=?
          indicatorColor |. Belt.Option.map(v => indicatorColorToJs(v)),
        ~onChange?,
        ~scrollable?,
        ~_ScrollButtonComponent=?
          _ScrollButtonComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~scrollButtons=?
          scrollButtons |. Belt.Option.map(v => scrollButtonsToJs(v)),
        ~_TabIndicatorProps?,
        ~textColor=?textColor |. Belt.Option.map(v => textColorToJs(v)),
        ~theme?,
        ~value?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
