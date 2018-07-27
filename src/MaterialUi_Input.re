[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | FormControl(string)
    | Focused(string)
    | Disabled(string)
    | Underline(string)
    | Error(string)
    | Multiline(string)
    | FullWidth(string)
    | Input(string)
    | InputMarginDense(string)
    | InputMultiline(string)
    | InputType(string)
    | InputTypeSearch(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FormControl(_) => "formControl"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | Underline(_) => "underline"
    | Error(_) => "error"
    | Multiline(_) => "multiline"
    | FullWidth(_) => "fullWidth"
    | Input(_) => "input"
    | InputMarginDense(_) => "inputMarginDense"
    | InputMultiline(_) => "inputMultiline"
    | InputType(_) => "inputType"
    | InputTypeSearch(_) => "inputTypeSearch";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | FormControl(className)
           | Focused(className)
           | Disabled(className)
           | Underline(className)
           | Error(className)
           | Multiline(className)
           | FullWidth(className)
           | Input(className)
           | InputMarginDense(className)
           | InputMultiline(className)
           | InputType(className)
           | InputTypeSearch(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'union_r32q=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: ReasonReact.reactElement=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'any_rl58=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_r0ko=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onChange: 'any_r6u5=?,
    ~onEmpty: 'genericCallback=?,
    ~onFilled: 'genericCallback=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onKeyUp: ReactEventRe.Keyboard.t => unit=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~rows: 'union_rd72=?,
    ~rowsMax: 'union_rg6o=?,
    ~startAdornment: ReasonReact.reactElement=?,
    ~_type: string=?,
    ~value: 'union_r698=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Input/Input"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue:
         option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(ReasonReact.reactElement)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent: option('any_rl58)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onChange: option(ReactEventRe.Form.t => unit)=?,
      ~onEmpty: option('genericCallback)=?,
      ~onFilled: option('genericCallback)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEventRe.Keyboard.t => unit)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(ReasonReact.reactElement)=?,
      ~type_: option(string)=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Array(
                 array([ | `String(string) | `Int(int) | `Float(float)]),
               )
           ],
         )=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~autoComplete?,
        ~autoFocus?,
        ~className?,
        ~defaultValue=?
          defaultValue
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~disabled?,
        ~disableUnderline?,
        ~endAdornment?,
        ~error?,
        ~fullWidth?,
        ~id?,
        ~inputComponent?,
        ~inputProps?,
        ~inputRef=?
          inputRef |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~margin=?margin |. Belt.Option.map(v => marginToJs(v)),
        ~multiline?,
        ~name?,
        ~onBlur?,
        ~onChange?,
        ~onEmpty?,
        ~onFilled?,
        ~onFocus?,
        ~onKeyDown?,
        ~onKeyUp?,
        ~placeholder?,
        ~readOnly?,
        ~rows=?
          rows |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~rowsMax=?
          rowsMax |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~startAdornment?,
        ~_type=?type_,
        ~value=?
          value |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
