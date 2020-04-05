[@bs.deriving jsConverter]
type color = [
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
];

[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | ColorSecondary(string)
    | Focused(string)
    | Disabled(string)
    | AdornedStart(string)
    | AdornedEnd(string)
    | Error(string)
    | MarginDense(string)
    | Multiline(string)
    | NotchedOutline(string)
    | Input(string)
    | InputMarginDense(string)
    | InputMultiline(string)
    | InputAdornedStart(string)
    | InputAdornedEnd(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorSecondary(_) => "colorSecondary"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | AdornedStart(_) => "adornedStart"
    | AdornedEnd(_) => "adornedEnd"
    | Error(_) => "error"
    | MarginDense(_) => "marginDense"
    | Multiline(_) => "multiline"
    | NotchedOutline(_) => "notchedOutline"
    | Input(_) => "input"
    | InputMarginDense(_) => "inputMarginDense"
    | InputMultiline(_) => "inputMultiline"
    | InputAdornedStart(_) => "inputAdornedStart"
    | InputAdornedEnd(_) => "inputAdornedEnd";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | ColorSecondary(className)
                         | Focused(className)
                         | Disabled(className)
                         | AdornedStart(className)
                         | AdornedEnd(className)
                         | Error(className)
                         | MarginDense(className)
                         | Multiline(className)
                         | NotchedOutline(className)
                         | Input(className)
                         | InputMarginDense(className)
                         | InputMultiline(className)
                         | InputAdornedStart(className)
                         | InputAdornedEnd(className) =>
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
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~color: string=?,
    ~defaultValue: 'any_rnx0=?,
    ~disabled: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'union_r3bf=?,
    ~inputProps: Js.t({..})=?,
    ~label: React.element=?,
    ~labelWidth: 'number_z=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~notched: bool=?,
    ~onChange: 'any_r6vw=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_r96w=?,
    ~rowsMax: 'union_rk9k=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~value: 'any_rkdw=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~aria_describedby: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~renderSuffix: 'genericCallback=?,
    ~rowsMin: 'union_r8i0=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~defaultValue: option('any_rnx0)=?,
      ~disabled: option(bool)=?,
      ~endAdornment: option(React.element)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~inputProps: option(Js.t({..}))=?,
      ~label: option(React.element)=?,
      ~labelWidth: option([ | `Int(int) | `Float(float)])=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~notched: option(bool)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(React.element)=?,
      ~type_: option(string)=?,
      ~value: option('any_rkdw)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~aria_describedby: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~renderSuffix: option('genericCallback)=?,
      ~rowsMin: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~autoComplete?,
    ~autoFocus?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~defaultValue?,
    ~disabled?,
    ~endAdornment?,
    ~error?,
    ~fullWidth?,
    ~id?,
    ~inputComponent=?
      inputComponent->(
                        Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                      ),
    ~inputProps?,
    ~label?,
    ~labelWidth=?
      labelWidth->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
    ~multiline?,
    ~name?,
    ~notched?,
    ~onChange?,
    ~placeholder?,
    ~readOnly?,
    ~required?,
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMax=?
      rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~startAdornment?,
    ~_type=?type_,
    ~value?,
    ~key?,
    ~ref?,
    ~aria_describedby?,
    ~onBlur?,
    ~onClick?,
    ~onFocus?,
    ~onKeyDown?,
    ~onKeyUp?,
    ~renderSuffix?,
    ~rowsMin=?
      rowsMin->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "OutlinedInput";
