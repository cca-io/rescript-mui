[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | FormControl(string)
    | Focused(string)
    | Disabled(string)
    | AdornedStart(string)
    | AdornedEnd(string)
    | Error(string)
    | MarginDense(string)
    | Multiline(string)
    | FullWidth(string)
    | Input(string)
    | InputMarginDense(string)
    | InputMultiline(string)
    | InputTypeSearch(string)
    | InputAdornedStart(string)
    | InputAdornedEnd(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FormControl(_) => "formControl"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | AdornedStart(_) => "adornedStart"
    | AdornedEnd(_) => "adornedEnd"
    | Error(_) => "error"
    | MarginDense(_) => "marginDense"
    | Multiline(_) => "multiline"
    | FullWidth(_) => "fullWidth"
    | Input(_) => "input"
    | InputMarginDense(_) => "inputMarginDense"
    | InputMultiline(_) => "inputMultiline"
    | InputTypeSearch(_) => "inputTypeSearch"
    | InputAdornedStart(_) => "inputAdornedStart"
    | InputAdornedEnd(_) => "inputAdornedEnd";
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
                         | AdornedStart(className)
                         | AdornedEnd(className)
                         | Error(className)
                         | MarginDense(className)
                         | Multiline(className)
                         | FullWidth(className)
                         | Input(className)
                         | InputMarginDense(className)
                         | InputMultiline(className)
                         | InputTypeSearch(className)
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
    ~aria_describedby: string=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'any_rxff=?,
    ~disabled: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_rg5a=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_rd2j=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onEmpty: 'genericCallback=?,
    ~onFilled: 'genericCallback=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~renderPrefix: 'genericCallback=?,
    ~required: bool=?,
    ~rows: 'union_rygv=?,
    ~rowsMax: 'union_ruhd=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~value: 'any_r7ab=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "InputBase";

[@react.component]
let make =
    (
      ~aria_describedby: option(string)=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue: option('any_rxff)=?,
      ~disabled: option(bool)=?,
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
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onEmpty: option('genericCallback)=?,
      ~onFilled: option('genericCallback)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~renderPrefix: option('genericCallback)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(React.element)=?,
      ~type_: option(string)=?,
      ~value: option('any_r7ab)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~aria_describedby?,
      ~autoComplete?,
      ~autoFocus?,
      ~className?,
      ~defaultValue?,
      ~disabled?,
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
      ~onBlur?,
      ~onChange?,
      ~onClick?,
      ~onEmpty?,
      ~onFilled?,
      ~onFocus?,
      ~onKeyDown?,
      ~onKeyUp?,
      ~placeholder?,
      ~readOnly?,
      ~renderPrefix?,
      ~required?,
      ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~rowsMax=?
        rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~startAdornment?,
      ~_type=?type_,
      ~value?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
