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
external makePropsMui:
  (
    ~children: 'children=?,
    ~input: React.element=?,
    ~inputProps: Js.t({..})=?,
    ~muiFormControl: Js.t({..})=?,
    ~onChange: 'any_r0pl=?,
    ~value: 'any_rnja=?,
    ~variant: string=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'any_rjjy=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: 'any_rp2e=?,
    ~inputRef: 'union_r02b=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: 'union_re78=?,
    ~rowsMax: 'union_rq1a=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
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
external reactComponent: React.component('a) = "NativeSelect";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~input: option(React.element)=?,
      ~inputProps: option(Js.t({..}))=?,
      ~muiFormControl: option(Js.t({..}))=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~value: option('any_rnja)=?,
      ~variant: option(variant)=?,
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue: option('any_rjjy)=?,
      ~disabled: option(bool)=?,
      ~disableUnderline: option(bool)=?,
      ~endAdornment: option(React.element)=?,
      ~error: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~id: option(string)=?,
      ~inputComponent: option('any_rp2e)=?,
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
      ~startAdornment: option(React.element)=?,
      ~type_: option(string)=?,
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
      ~children?,
      ~input?,
      ~inputProps?,
      ~muiFormControl?,
      ~onChange?,
      ~value?,
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
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
      ~inputComponent?,
      ~inputRef=?
        inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
      ~multiline?,
      ~name?,
      ~placeholder?,
      ~readOnly?,
      ~required?,
      ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~rowsMax=?
        rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~startAdornment?,
      ~_type=?type_,
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
