[@bs.deriving jsConverter]
type margin = [
  | [@bs.as "none"] `None
  | [@bs.as "dense"] `Dense
  | [@bs.as "normal"] `Normal
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "standard"] `Standard
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "filled"] `Filled
];
[@bs.obj]
external makePropsMui:
  (
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~defaultValue: 'any_rgp5=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~_FormHelperTextProps: Js.t({..})=?,
    ~fullWidth: bool=?,
    ~helperText: React.element=?,
    ~id: string=?,
    ~_InputLabelProps: Js.t({..})=?,
    ~_InputProps: Js.t({..})=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'union_r4uy=?,
    ~label: React.element=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_r4zc=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~placeholder: string=?,
    ~required: bool=?,
    ~rows: 'union_rgyh=?,
    ~rowsMax: 'union_r302=?,
    ~select: bool=?,
    ~_SelectProps: Js.t({..})=?,
    ~_type: string=?,
    ~value: 'any_re5z=?,
    ~variant: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "TextField";

[@react.component]
let make =
    (
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~defaultValue: option('any_rgp5)=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~_FormHelperTextProps: option(Js.t({..}))=?,
      ~fullWidth: option(bool)=?,
      ~helperText: option(React.element)=?,
      ~id: option(string)=?,
      ~_InputLabelProps: option(Js.t({..}))=?,
      ~_InputProps: option(Js.t({..}))=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~label: option(React.element)=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onFocus: option(ReactEvent.Focus.t => unit)=?,
      ~placeholder: option(string)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~select: option(bool)=?,
      ~_SelectProps: option(Js.t({..}))=?,
      ~type_: option(string)=?,
      ~value: option('any_re5z)=?,
      ~variant: option(variant)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~autoComplete?,
      ~autoFocus?,
      ~children?,
      ~className?,
      ~defaultValue?,
      ~disabled?,
      ~error?,
      ~_FormHelperTextProps?,
      ~fullWidth?,
      ~helperText?,
      ~id?,
      ~_InputLabelProps?,
      ~_InputProps?,
      ~inputProps?,
      ~inputRef=?
        inputRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~label?,
      ~margin=?margin->(Belt.Option.map(v => marginToJs(v))),
      ~multiline?,
      ~name?,
      ~onBlur?,
      ~onChange?,
      ~onFocus?,
      ~placeholder?,
      ~required?,
      ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~rowsMax=?
        rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~select?,
      ~_SelectProps?,
      ~_type=?type_,
      ~value?,
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      (),
    ),
  );
