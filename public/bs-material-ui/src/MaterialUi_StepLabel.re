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
    ~children: 'children=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~icon: React.element=?,
    ~optional: React.element=?,
    ~_StepIconComponent: 'union_rgxk=?,
    ~_StepIconProps: Js.t({..})=?,
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
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~icon: option(React.element)=?,
      ~optional: option(React.element)=?,
      ~_StepIconComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_StepIconProps: option(Js.t({..}))=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~disabled?,
    ~error?,
    ~icon?,
    ~optional?,
    ~_StepIconComponent=?
      _StepIconComponent->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
    ~_StepIconProps?,
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "StepLabel";
