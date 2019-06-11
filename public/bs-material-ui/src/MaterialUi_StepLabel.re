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
    | Label(string)
    | Active(string)
    | Completed(string)
    | Error(string)
    | Disabled(string)
    | IconContainer(string)
    | AlternativeLabel(string)
    | LabelContainer(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | Label(_) => "label"
    | Active(_) => "active"
    | Completed(_) => "completed"
    | Error(_) => "error"
    | Disabled(_) => "disabled"
    | IconContainer(_) => "iconContainer"
    | AlternativeLabel(_) => "alternativeLabel"
    | LabelContainer(_) => "labelContainer";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Horizontal(className)
                         | Vertical(className)
                         | Label(className)
                         | Active(className)
                         | Completed(className)
                         | Error(className)
                         | Disabled(className)
                         | IconContainer(className)
                         | AlternativeLabel(className)
                         | LabelContainer(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~completed: bool=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~icon: React.element=?,
    ~last: bool=?,
    ~optional: React.element=?,
    ~orientation: string=?,
    ~_StepIconProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "StepLabel";

[@react.component]
let make =
    (
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~icon: option(React.element)=?,
      ~last: option(bool)=?,
      ~optional: option(React.element)=?,
      ~orientation: option(orientation)=?,
      ~_StepIconProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~active?,
      ~alternativeLabel?,
      ~children?,
      ~className?,
      ~completed?,
      ~disabled?,
      ~error?,
      ~icon?,
      ~last?,
      ~optional?,
      ~orientation=?orientation->(Belt.Option.map(v => orientationToJs(v))),
      ~_StepIconProps?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
