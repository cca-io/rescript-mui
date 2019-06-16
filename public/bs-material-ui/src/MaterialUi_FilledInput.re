[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | Underline(string)
    | Focused(string)
    | Disabled(string)
    | AdornedStart(string)
    | AdornedEnd(string)
    | Error(string)
    | MarginDense(string)
    | Multiline(string)
    | Input(string)
    | InputMarginDense(string)
    | InputMultiline(string)
    | InputAdornedStart(string)
    | InputAdornedEnd(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Underline(_) => "underline"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | AdornedStart(_) => "adornedStart"
    | AdornedEnd(_) => "adornedEnd"
    | Error(_) => "error"
    | MarginDense(_) => "marginDense"
    | Multiline(_) => "multiline"
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
                         | Underline(className)
                         | Focused(className)
                         | Disabled(className)
                         | AdornedStart(className)
                         | AdornedEnd(className)
                         | Error(className)
                         | MarginDense(className)
                         | Multiline(className)
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
    ~defaultValue: 'any_rj4b=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rki5=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onChange: 'any_rlja=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_rxuh=?,
    ~rowsMax: 'union_rnex=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~value: 'any_rg32=?,
    ~aria_describedby: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onEmpty: 'genericCallback=?,
    ~onFilled: 'genericCallback=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~renderPrefix: 'genericCallback=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "FilledInput";

[@react.component]
let make =
    (
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue: option('any_rj4b)=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(React.element)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
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
      ~value: option('any_rg32)=?,
      ~aria_describedby: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onEmpty: option('genericCallback)=?,
      ~onFilled: option('genericCallback)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~renderPrefix: option('genericCallback)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~autoComplete?,
      ~autoFocus?,
      ~className?,
      ~defaultValue?,
      ~disabled?,
      ~disableUnderline?,
      ~endAdornment?,
      ~error?,
      ~fullWidth?,
      ~id?,
      ~inputProps?,
      ~inputRef=?
        inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
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
      ~aria_describedby?,
      ~onBlur?,
      ~onClick?,
      ~onEmpty?,
      ~onFilled?,
      ~onFocus?,
      ~onKeyDown?,
      ~onKeyUp?,
      ~renderPrefix?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
