[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

[@bs.deriving jsConverter]
type track = [
  | [@bs.as "normal"] `Normal
  | [@bs.as "false"] `False
  | [@bs.as "inverted"] `Inverted
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
    | ColorPrimary(string)
    | ColorSecondary(string)
    | Marked(string)
    | Vertical(string)
    | Disabled(string)
    | Rail(string)
    | Track(string)
    | TrackFalse(string)
    | TrackInverted(string)
    | Thumb(string)
    | ThumbColorPrimary(string)
    | ThumbColorSecondary(string)
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
    | ColorPrimary(_) => "colorPrimary"
    | ColorSecondary(_) => "colorSecondary"
    | Marked(_) => "marked"
    | Vertical(_) => "vertical"
    | Disabled(_) => "disabled"
    | Rail(_) => "rail"
    | Track(_) => "track"
    | TrackFalse(_) => "trackFalse"
    | TrackInverted(_) => "trackInverted"
    | Thumb(_) => "thumb"
    | ThumbColorPrimary(_) => "thumbColorPrimary"
    | ThumbColorSecondary(_) => "thumbColorSecondary"
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
                         | ColorPrimary(className)
                         | ColorSecondary(className)
                         | Marked(className)
                         | Vertical(className)
                         | Disabled(className)
                         | Rail(className)
                         | Track(className)
                         | TrackFalse(className)
                         | TrackInverted(className)
                         | Thumb(className)
                         | ThumbColorPrimary(className)
                         | ThumbColorSecondary(className)
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
    ~aria_labelledby: string=?,
    ~className: string=?,
    ~color: string=?,
    ~component: 'union_r3l8=?,
    ~defaultValue: 'union_r7i2=?,
    ~disabled: bool=?,
    ~getAriaLabel: 'any_ru22=?,
    ~getAriaValueText: 'any_rqax=?,
    ~marks: 'union_ruie=?,
    ~max: 'number_j=?,
    ~min: 'number_f=?,
    ~name: string=?,
    ~onChange: 'any_rz93=?,
    ~onChangeCommitted: 'any_rg2u=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~orientation: string=?,
    ~step: 'number_j=?,
    ~_ThumbComponent: 'union_rrj8=?,
    ~track: string=?,
    ~value: 'union_rvyl=?,
    ~_ValueLabelComponent: 'union_rjh1=?,
    ~valueLabelDisplay: string=?,
    ~valueLabelFormat: 'union_rjuy=?,
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
      ~aria_labelledby: option(string)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
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
      ~getAriaLabel: option(int => string)=?,
      ~getAriaValueText: option((int, int) => string)=?,
      ~marks: option([ | `Bool(bool) | `Array('any_rj39)])=?,
      ~max: option([ | `Int(int) | `Float(float)])=?,
      ~min: option([ | `Int(int) | `Float(float)])=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_rzcs) => unit)=?,
      ~onChangeCommitted: option((Js.t({..}), 'any_row5) => unit)=?,
      ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
      ~orientation: option(orientation)=?,
      ~step: option([ | `Int(int) | `Float(float)])=?,
      ~_ThumbComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~track: option(track)=?,
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
             | `Element(React.element)
           ],
         )=?,
      ~valueLabelDisplay: option(valueLabelDisplay)=?,
      ~valueLabelFormat:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~aria_labelledby?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~defaultValue=?
      defaultValue->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disabled?,
    ~getAriaLabel?,
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
    ~track=?track->(Belt.Option.map(v => trackToJs(v))),
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
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Slider";
