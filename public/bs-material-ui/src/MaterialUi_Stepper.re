[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "elevation"] `Elevation
  | [@bs.as "outlined"] `Outlined
];

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
    ~component: 'union_rw9i=?,
    ~elevation: 'number_t=?,
    ~square: bool=?,
    ~variant: string=?,
    ~id: string=?,
    ~activeStep: 'number_n=?,
    ~alternativeLabel: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~connector: React.element=?,
    ~nonLinear: bool=?,
    ~orientation: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~activeStep: option([ | `Int(int) | `Float(float)])=?,
      ~alternativeLabel: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~connector: option(React.element)=?,
      ~nonLinear: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~square?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~id?,
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
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Stepper";
