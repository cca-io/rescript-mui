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
    | AlternativeLabel(string)
    | Active(string)
    | Completed(string)
    | Disabled(string)
    | Line(string)
    | LineHorizontal(string)
    | LineVertical(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | AlternativeLabel(_) => "alternativeLabel"
    | Active(_) => "active"
    | Completed(_) => "completed"
    | Disabled(_) => "disabled"
    | Line(_) => "line"
    | LineHorizontal(_) => "lineHorizontal"
    | LineVertical(_) => "lineVertical";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Horizontal(className)
                         | Vertical(className)
                         | AlternativeLabel(className)
                         | Active(className)
                         | Completed(className)
                         | Disabled(className)
                         | Line(className)
                         | LineHorizontal(className)
                         | LineVertical(className) =>
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
    ~active: bool=?,
    ~alternativeLabel: bool=?,
    ~className: string=?,
    ~completed: bool=?,
    ~disabled: bool=?,
    ~index: 'number_n=?,
    ~orientation: string=?,
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
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~disabled: option(bool)=?,
      ~index: option([ | `Int(int) | `Float(float)])=?,
      ~orientation: option(orientation)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~active?,
    ~alternativeLabel?,
    ~className?,
    ~completed?,
    ~disabled?,
    ~index=?index->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~orientation=?
      orientation->(
                     Belt.Option.map(v =>
                       switch (v->Obj.magic->Js.Json.classify) {
                       | JSONString(str) => str
                       | _ => orientationToJs(v)
                       }
                     )
                   ),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "StepConnector";
