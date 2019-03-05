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
    | ScrollButtonsAuto(string)
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
    | ScrollButtonsAuto(_) => "scrollButtonsAuto"
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
                         | ScrollButtonsAuto(className)
                         | Indicator(className) =>
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
    ~action: 'any_r668=?,
    ~centered: bool=?,
    ~className: string=?,
    ~indicatorColor: string=?,
    ~onChange: 'any_rv7e=?,
    ~scrollButtons: string=?,
    ~_TabIndicatorProps: Js.t({..})=?,
    ~textColor: string=?,
    ~theme: Js.t({..})=?,
    ~value: 'any_rb73=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Tabs";
let make =
    (
      ~action: option(Js.t({..}) => unit)=?,
      ~centered: option(bool)=?,
      ~className: option(string)=?,
      ~indicatorColor: option(indicatorColor)=?,
      ~onChange: option((ReactEvent.Form.t, int) => unit)=?,
      ~scrollButtons: option(scrollButtons)=?,
      ~_TabIndicatorProps: option(Js.t({..}))=?,
      ~textColor: option(textColor)=?,
      ~theme: option(Js.t({..}))=?,
      ~value: option('any_rb73)=?,
      ~variant: option(variant)=?,
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
        ~indicatorColor=?
          indicatorColor->(Belt.Option.map(v => indicatorColorToJs(v))),
        ~onChange?,
        ~scrollButtons=?
          scrollButtons->(Belt.Option.map(v => scrollButtonsToJs(v))),
        ~_TabIndicatorProps?,
        ~textColor=?textColor->(Belt.Option.map(v => textColorToJs(v))),
        ~theme?,
        ~value?,
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
