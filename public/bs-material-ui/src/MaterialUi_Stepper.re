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
    ~activeStep: 'number_w=?,
    ~alternativeLabel: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~connector: React.element=?,
    ~nonLinear: bool=?,
    ~orientation: string=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~elevation: 'number_3=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~activeStep: option([ | `Int(int) | `Float(float)])=?,
      ~alternativeLabel: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~connector: option(React.element)=?,
      ~nonLinear: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
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
    ~key?,
    ~_ref=?ref_,
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~square?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Stepper";
