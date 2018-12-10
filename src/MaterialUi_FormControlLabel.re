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
external makeProps:
  (
    ~checked: 'union_rjah=?,
    ~className: string=?,
    ~control: ReasonReact.reactElement=?,
    ~disabled: bool=?,
    ~inputRef: 'union_ryff=?,
    ~label: ReasonReact.reactElement=?,
    ~labelPlacement: string=?,
    ~muiFormControl: Js.t({..})=?,
    ~name: string=?,
    ~onChange: 'any_ri59=?,
    ~value: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "FormControlLabel";
let make =
    (
      ~checked: option([ | `Bool(bool) | `String(string)])=?,
      ~className: option(string)=?,
      ~control: option(ReasonReact.reactElement)=?,
      ~disabled: option(bool)=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~label: option(ReasonReact.reactElement)=?,
      ~labelPlacement: option(labelPlacement)=?,
      ~muiFormControl: option(Js.t({..}))=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
      ~value: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~checked=?
          checked->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
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
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
