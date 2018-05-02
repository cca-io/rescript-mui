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
    |> StdLabels.List.fold_left(
         ~f=
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~action: 'any_r4k7=?,
    ~centered: bool=?,
    ~className: string=?,
    ~fullWidth: bool=?,
    ~indicatorColor: string=?,
    ~onChange: 'any_r760=?,
    ~scrollable: bool=?,
    ~scrollButtons: string=?,
    ~_TabScrollButton: 'union_rtgg=?,
    ~textColor: string=?,
    ~theme: Js.t({..})=?,
    ~value: 'any_rj4r=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Tabs/Tabs"]
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
      ~scrollButtons: option(scrollButtons)=?,
      ~_TabScrollButton:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~textColor: option(textColor)=?,
      ~theme: option(Js.t({..}))=?,
      ~value: option('any_rj4r)=?,
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
          Js.Option.map((. v) => indicatorColorToJs(v), indicatorColor),
        ~onChange?,
        ~scrollable?,
        ~scrollButtons=?
          Js.Option.map((. v) => scrollButtonsToJs(v), scrollButtons),
        ~_TabScrollButton=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _TabScrollButton,
          ),
        ~textColor=?Js.Option.map((. v) => textColorToJs(v), textColor),
        ~theme?,
        ~value?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
