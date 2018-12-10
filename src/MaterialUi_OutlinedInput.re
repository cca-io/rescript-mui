[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | Focused(string)
    | Disabled(string)
    | AdornedStart(string)
    | AdornedEnd(string)
    | Error(string)
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
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | AdornedStart(_) => "adornedStart"
    | AdornedEnd(_) => "adornedEnd"
    | Error(_) => "error"
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
                         | Focused(className)
                         | Disabled(className)
                         | AdornedStart(className)
                         | AdornedEnd(className)
                         | Error(className)
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
external makeProps:
  (
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'union_r3zw=?,
    ~disabled: bool=?,
    ~endAdornment: ReasonReact.reactElement=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'union_r75h=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_r43z=?,
    ~labelWidth: 'number_0,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~notched: bool=?,
    ~onChange: 'any_ri2h=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_r5cq=?,
    ~rowsMax: 'union_r7xu=?,
    ~startAdornment: ReasonReact.reactElement=?,
    ~_type: string=?,
    ~value: 'union_rw2y=?,
    ~muiFormControl: Js.t({..})=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
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
external reactClass: ReasonReact.reactClass = "OutlinedInput";
let make =
    (
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Bool(bool)
             | `ObjectGeneric(Js.t({..}))
             | `Array(
                 array(
                   [
                     | `String(string)
                     | `Int(int)
                     | `Float(float)
                     | `Bool(bool)
                     | `ObjectGeneric(Js.t({..}))
                   ],
                 ),
               )
           ],
         )=?,
      ~disabled: option(bool)=?,
      ~endAdornment: option(ReasonReact.reactElement)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~labelWidth: [ | `Int(int) | `Float(float)],
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
      ~startAdornment: option(ReasonReact.reactElement)=?,
      ~type_: option(string)=?,
      ~value:
         option(
           [
             | `String(string)
             | `Int(int)
             | `Float(float)
             | `Bool(bool)
             | `ObjectGeneric(Js.t({..}))
             | `Array(
                 array(
                   [
                     | `String(string)
                     | `Int(int)
                     | `Float(float)
                     | `Bool(bool)
                     | `ObjectGeneric(Js.t({..}))
                   ],
                 ),
               )
           ],
         )=?,
      ~muiFormControl: option(Js.t({..}))=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onEmpty: option('genericCallback)=?,
      ~onFilled: option('genericCallback)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
      ~renderPrefix: option('genericCallback)=?,
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
          defaultValue->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
        ~disabled?,
        ~endAdornment?,
        ~error?,
        ~fullWidth?,
        ~id?,
        ~inputComponent=?
          inputComponent->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
        ~inputProps?,
        ~inputRef=?
          inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~labelWidth=MaterialUi_Helpers.unwrapValue(labelWidth),
        ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
        ~multiline?,
        ~name?,
        ~notched?,
        ~onChange?,
        ~placeholder?,
        ~readOnly?,
        ~required?,
        ~rows=?
          rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~rowsMax=?
          rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~startAdornment?,
        ~_type=?type_,
        ~value=?
          value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~muiFormControl?,
        ~onBlur?,
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
    children,
  );
