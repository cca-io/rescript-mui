[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

[@bs.deriving jsConverter]
type valueLabelDisplay = [
  | [@bs.as "on"] `On
  | [@bs.as "auto"] `Auto
  | [@bs.as "off"] `Off
];

module Classes = {
  type classesType =
    | Root(string)
    | Marked(string)
    | Vertical(string)
    | Disabled(string)
    | Rail(string)
    | Track(string)
    | Thumb(string)
    | Active(string)
    | FocusVisible(string)
    | ValueLabel(string)
    | Mark(string)
    | MarkActive(string)
    | MarkLabel(string)
    | MarkLabelActive(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Marked(_) => "marked"
    | Vertical(_) => "vertical"
    | Disabled(_) => "disabled"
    | Rail(_) => "rail"
    | Track(_) => "track"
    | Thumb(_) => "thumb"
    | Active(_) => "active"
    | FocusVisible(_) => "focusVisible"
    | ValueLabel(_) => "valueLabel"
    | Mark(_) => "mark"
    | MarkActive(_) => "markActive"
    | MarkLabel(_) => "markLabel"
    | MarkLabelActive(_) => "markLabelActive";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Marked(className)
                         | Vertical(className)
                         | Disabled(className)
                         | Rail(className)
                         | Track(className)
                         | Thumb(className)
                         | Active(className)
                         | FocusVisible(className)
                         | ValueLabel(className)
                         | Mark(className)
                         | MarkActive(className)
                         | MarkLabel(className)
                         | MarkLabelActive(className) =>
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
    ~aria_label: string=?,
    ~aria_labelledby: string=?,
    ~className: string=?,
    ~component: 'union_rtvj=?,
    ~defaultValue: 'union_r06u=?,
    ~disabled: bool=?,
    ~getAriaValueText: 'any_rfl6=?,
    ~marks: 'union_ra0v=?,
    ~max: 'number_b=?,
    ~min: 'number_b=?,
    ~name: string=?,
    ~onChange: 'any_rkxe=?,
    ~onChangeCommitted: 'any_rjam=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~orientation: string=?,
    ~step: 'number_9=?,
    ~_ThumbComponent: 'union_ry86=?,
    ~value: 'union_rp80=?,
    ~_ValueLabelComponent: 'union_rqtk=?,
    ~valueLabelDisplay: string=?,
    ~valueLabelFormat: 'union_r9nu=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~aria_label: option(string)=?,
      ~aria_labelledby: option(string)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~defaultValue:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `IntArray(array(int))
             | `FloatArray(array(float))
           ],
         )=?,
      ~disabled: option(bool)=?,
      ~getAriaValueText: option((int, int) => unit)=?,
      ~marks: option([ | `Bool(bool) | `Array('any_r7rq)])=?,
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~min: option([ | `Int(int) | `Float(float)])=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_rp14) => unit)=?,
      ~onChangeCommitted: option((Js.t({..}), 'any_r2vp) => unit)=?,
      ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
      ~orientation: option(orientation)=?,
      ~step: option([ | `Int(int) | `Float(float)])=?,
      ~_ThumbComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~value:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `IntArray(array(int))
             | `FloatArray(array(float))
           ],
         )=?,
      ~_ValueLabelComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~valueLabelDisplay: option(valueLabelDisplay)=?,
      ~valueLabelFormat:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~aria_label?,
    ~aria_labelledby?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~defaultValue=?
      defaultValue->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~getAriaValueText?,
    ~marks=?marks->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~max=?max->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~min=?min->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~name?,
    ~onChange?,
    ~onChangeCommitted?,
    ~onMouseDown?,
    ~orientation=?orientation->(Belt.Option.map(v => orientationToJs(v))),
    ~step=?step->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_ThumbComponent=?
      _ThumbComponent->(
                         Belt.Option.map(v =>
                           MaterialUi_Helpers.unwrapValue(v)
                         )
                       ),
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_ValueLabelComponent=?
      _ValueLabelComponent->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
    ~valueLabelDisplay=?
      valueLabelDisplay->(Belt.Option.map(v => valueLabelDisplayToJs(v))),
    ~valueLabelFormat=?
      valueLabelFormat->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Slider";
