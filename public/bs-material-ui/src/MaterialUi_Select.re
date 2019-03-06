[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "filled"] `Filled
];

[@bs.deriving jsConverter]
type margin = [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None];

module Classes = {
  type classesType =
    | Root(string)
    | Select(string)
    | Filled(string)
    | Outlined(string)
    | SelectMenu(string)
    | Disabled(string)
    | Icon(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Select(_) => "select"
    | Filled(_) => "filled"
    | Outlined(_) => "outlined"
    | SelectMenu(_) => "selectMenu"
    | Disabled(_) => "disabled"
    | Icon(_) => "icon";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Select(className)
                         | Filled(className)
                         | Outlined(className)
                         | SelectMenu(className)
                         | Disabled(className)
                         | Icon(className) =>
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
    ~autoWidth: bool=?,
    ~displayEmpty: bool=?,
    ~_IconComponent: 'union_r9zd=?,
    ~input: ReasonReact.reactElement=?,
    ~inputProps: Js.t({..})=?,
    ~_MenuProps: Js.t({..})=?,
    ~multiple: bool=?,
    ~native: bool=?,
    ~onChange: 'any_r9pn=?,
    ~onClose: 'any_rbxl=?,
    ~onOpen: 'any_rl8l=?,
    ~_open: bool=?,
    ~renderValue: 'any_rr3g=?,
    ~_SelectDisplayProps: Js.t({..})=?,
    ~value: 'union_rxmx=?,
    ~variant: string=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'union_rjd4=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: ReasonReact.reactElement=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'any_r59w=?,
    ~inputRef: 'union_rrvl=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_rq27=?,
    ~rowsMax: 'union_r3j3=?,
    ~startAdornment: ReasonReact.reactElement=?,
    ~_type: string=?,
    ~muiFormControl: Js.t({..})=?,
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
external reactClass: ReasonReact.reactClass = "Select";
let make =
    (
      ~autoWidth: option(bool)=?,
      ~displayEmpty: option(bool)=?,
      ~_IconComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~input: option(ReasonReact.reactElement)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~_MenuProps: option(Js.t({..}))=?,
      ~multiple: option(bool)=?,
      ~native: option(bool)=?,
      ~onChange: option((ReactEvent.Form.t, Js.t({..})) => unit)=?,
      ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
      ~onOpen: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~renderValue: option('any_r6ru => ReasonReact.reactElement)=?,
      ~_SelectDisplayProps: option(Js.t({..}))=?,
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
      ~variant: option(variant)=?,
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
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(ReasonReact.reactElement)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent: option('any_r59w)=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~placeholder: option(string)=?,
      ~readOnly: option(bool)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~startAdornment: option(ReasonReact.reactElement)=?,
      ~type_: option(string)=?,
      ~muiFormControl: option(Js.t({..}))=?,
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
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~autoWidth?,
        ~displayEmpty?,
        ~_IconComponent=?
          _IconComponent->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
        ~input?,
        ~inputProps?,
        ~_MenuProps?,
        ~multiple?,
        ~native?,
        ~onChange?,
        ~onClose?,
        ~onOpen?,
        ~_open=?open_,
        ~renderValue?,
        ~_SelectDisplayProps?,
        ~value=?
          value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
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
        ~disableUnderline?,
        ~endAdornment?,
        ~error?,
        ~fullWidth?,
        ~id?,
        ~inputComponent?,
        ~inputRef=?
          inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
        ~multiline?,
        ~name?,
        ~placeholder?,
        ~readOnly?,
        ~required?,
        ~rows=?
          rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~rowsMax=?
          rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~startAdornment?,
        ~_type=?type_,
        ~muiFormControl?,
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
    children,
  );
