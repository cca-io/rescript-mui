[@bs.deriving jsConverter]
type textColor = [
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "primary"] `Primary
  | [@bs.as "inherit"] `Inherit
];

module Classes = {
  type classesType =
    | Root(string)
    | LabelIcon(string)
    | TextColorInherit(string)
    | TextColorPrimary(string)
    | TextColorSecondary(string)
    | Selected(string)
    | Disabled(string)
    | FullWidth(string)
    | Wrapped(string)
    | Wrapper(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | LabelIcon(_) => "labelIcon"
    | TextColorInherit(_) => "textColorInherit"
    | TextColorPrimary(_) => "textColorPrimary"
    | TextColorSecondary(_) => "textColorSecondary"
    | Selected(_) => "selected"
    | Disabled(_) => "disabled"
    | FullWidth(_) => "fullWidth"
    | Wrapped(_) => "wrapped"
    | Wrapper(_) => "wrapper";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | LabelIcon(className)
                         | TextColorInherit(className)
                         | TextColorPrimary(className)
                         | TextColorSecondary(className)
                         | Selected(className)
                         | Disabled(className)
                         | FullWidth(className)
                         | Wrapped(className)
                         | Wrapper(className) =>
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
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~icon: React.element=?,
    ~indicator: React.element=?,
    ~label: React.element=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~selected: bool=?,
    ~textColor: string=?,
    ~value: 'any_rbcc=?,
    ~wrapped: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Tab";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~disableFocusRipple: option(bool)=?,
      ~disableRipple: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~icon: option(React.element)=?,
      ~indicator: option(React.element)=?,
      ~label: option(React.element)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~selected: option(bool)=?,
      ~textColor: option(textColor)=?,
      ~value: option('any_rbcc)=?,
      ~wrapped: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~className?,
      ~disabled?,
      ~disableFocusRipple?,
      ~disableRipple?,
      ~fullWidth?,
      ~icon?,
      ~indicator?,
      ~label?,
      ~onChange?,
      ~onClick?,
      ~selected?,
      ~textColor=?textColor->(Belt.Option.map(v => textColorToJs(v))),
      ~value?,
      ~wrapped?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
