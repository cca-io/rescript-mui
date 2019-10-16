[@bs.deriving jsConverter]
type labelPlacement = [
  | [@bs.as "end"] `End
  | [@bs.as "start"] `Start
  | [@bs.as "top"] `Top
  | [@bs.as "bottom"] `Bottom
];

module Classes = {
  type classesType =
    | Root(string)
    | LabelPlacementStart(string)
    | LabelPlacementTop(string)
    | LabelPlacementBottom(string)
    | Disabled(string)
    | Label(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | LabelPlacementStart(_) => "labelPlacementStart"
    | LabelPlacementTop(_) => "labelPlacementTop"
    | LabelPlacementBottom(_) => "labelPlacementBottom"
    | Disabled(_) => "disabled"
    | Label(_) => "label";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | LabelPlacementStart(className)
                         | LabelPlacementTop(className)
                         | LabelPlacementBottom(className)
                         | Disabled(className)
                         | Label(className) =>
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
    ~checked: bool=?,
    ~className: string=?,
    ~control: React.element=?,
    ~disabled: bool=?,
    ~label: React.element=?,
    ~labelPlacement: string=?,
    ~name: string=?,
    ~onChange: 'any_rf4w=?,
    ~value: 'any_rwaa=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~checked: option(bool)=?,
      ~className: option(string)=?,
      ~control: option(React.element)=?,
      ~disabled: option(bool)=?,
      ~label: option(React.element)=?,
      ~labelPlacement: option(labelPlacement)=?,
      ~name: option(string)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~value: option('any_rwaa)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~checked?,
    ~className?,
    ~control?,
    ~disabled?,
    ~label?,
    ~labelPlacement=?
      labelPlacement->(Belt.Option.map(v => labelPlacementToJs(v))),
    ~name?,
    ~onChange?,
    ~value?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "FormControlLabel";
