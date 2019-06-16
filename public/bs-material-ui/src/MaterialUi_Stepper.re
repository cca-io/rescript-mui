[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

module Classes = {
  type classesType =
    | Root(string)
    | Horizontal(string)
    | Vertical(string)
    | AlternativeLabel(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | AlternativeLabel(_) => "alternativeLabel";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Horizontal(className)
                         | Vertical(className)
                         | AlternativeLabel(className) =>
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
    ~activeStep: 'number_2=?,
    ~alternativeLabel: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~connector: React.element=?,
    ~nonLinear: bool=?,
    ~orientation: string=?,
    ~elevation: 'number_8=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Stepper";

[@react.component]
let make =
    (
      ~activeStep: option([ | `Int(int) | `Float(float)])=?,
      ~alternativeLabel: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~connector: option(React.element)=?,
      ~nonLinear: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~activeStep=?
        activeStep->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~alternativeLabel?,
      ~children?,
      ~className?,
      ~connector?,
      ~nonLinear?,
      ~orientation=?
        orientation->(
                       Belt.Option.map(v =>
                         switch (v->Obj.magic->Js.Json.classify) {
                         | JSONString(str) => str
                         | _ => orientationToJs(v)
                         }
                       )
                     ),
      ~elevation=?
        elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~square?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
