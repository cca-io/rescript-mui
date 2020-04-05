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
    | FormControl(string)
    | Focused(string)
    | Disabled(string)
    | ColorSecondary(string)
    | Underline(string)
    | Error(string)
    | MarginDense(string)
    | Multiline(string)
    | FullWidth(string)
    | Input(string)
    | InputMarginDense(string)
    | InputMultiline(string)
    | InputTypeSearch(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FormControl(_) => "formControl"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | ColorSecondary(_) => "colorSecondary"
    | Underline(_) => "underline"
    | Error(_) => "error"
    | MarginDense(_) => "marginDense"
    | Multiline(_) => "multiline"
    | FullWidth(_) => "fullWidth"
    | Input(_) => "input"
    | InputMarginDense(_) => "inputMarginDense"
    | InputMultiline(_) => "inputMultiline"
    | InputTypeSearch(_) => "inputTypeSearch";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | FormControl(className)
                         | Focused(className)
                         | Disabled(className)
                         | ColorSecondary(className)
                         | Underline(className)
                         | Error(className)
                         | MarginDense(className)
                         | Multiline(className)
                         | FullWidth(className)
                         | Input(className)
                         | InputMarginDense(className)
                         | InputMultiline(className)
                         | InputTypeSearch(className) =>
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
    ~aria_describedby: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~renderSuffix: 'genericCallback=?,
    ~rowsMin: 'union_r168=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~color: string=?,
    ~defaultValue: 'any_rqqe=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'any_r0yf=?,
    ~inputProps: Js.t({..})=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onChange: 'any_rq2f=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_rjo0=?,
    ~rowsMax: 'union_rari=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~value: 'any_r6xf=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~aria_describedby: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~renderSuffix: option('genericCallback)=?,
      ~rowsMin: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~defaultValue: option('any_rqqe)=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(React.element)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent: option('any_r0yf)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(React.element)=?,
      ~type_: option(string)=?,
      ~value: option('any_r6xf)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~aria_describedby?,
    ~onBlur?,
    ~onClick?,
    ~onFocus?,
    ~onKeyDown?,
    ~onKeyUp?,
    ~renderSuffix?,
    ~rowsMin=?
      rowsMin->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~autoComplete?,
    ~autoFocus?,
    ~className?,
    ~color=?color->(Belt.Option.map(v => colorToJs(v))),
    ~defaultValue?,
    ~disabled?,
    ~disableUnderline?,
    ~endAdornment?,
    ~error?,
    ~fullWidth?,
    ~id?,
    ~inputComponent?,
    ~inputProps?,
    ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
    ~multiline?,
    ~name?,
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
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Input";
