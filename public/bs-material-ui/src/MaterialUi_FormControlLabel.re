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
    ~inputRef: 'union_rj17=?,
    ~label: React.element=?,
    ~labelPlacement: string=?,
    ~muiFormControl: Js.t({..})=?,
    ~name: string=?,
    ~onChange: 'any_rgc6=?,
    ~value: 'any_r27w=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
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
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~label: option(React.element)=?,
      ~labelPlacement: option(labelPlacement)=?,
      ~muiFormControl: option(Js.t({..}))=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~value: option('any_r27w)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~checked?,
    ~className?,
    ~control?,
    ~disabled?,
    ~inputRef=?
      inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~label?,
    ~labelPlacement=?
      labelPlacement->(Belt.Option.map(v => labelPlacementToJs(v))),
    ~muiFormControl?,
    ~name?,
    ~onChange?,
    ~value?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "FormControlLabel";
