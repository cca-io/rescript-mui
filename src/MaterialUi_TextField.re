[@bs.deriving jsConverter]
type margin = [
  | [@bs.as "none"] `None
  | [@bs.as "dense"] `Dense
  | [@bs.as "normal"] `Normal
];
[@bs.obj]
external makeProps :
  (
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~className: string=?,
    ~defaultValue: 'union_r2kb=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~_FormHelperTextProps: Js.t({..})=?,
    ~fullWidth: bool=?,
    ~helperText: ReasonReact.reactElement=?,
    ~id: string=?,
    ~_InputLabelProps: Js.t({..})=?,
    ~_InputProps: Js.t({..})=?,
    ~inputProps: Js.t({..})=?,
    ~inputRef: 'genericCallback=?,
    ~label: ReasonReact.reactElement=?,
    ~margin: string=?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onChange: 'any_r1cn=?,
    ~onFocus: ReactEventRe.Focus.t => unit=?,
    ~placeholder: string=?,
    ~required: bool=?,
    ~rows: 'union_rixm=?,
    ~rowsMax: 'union_rd04=?,
    ~select: bool=?,
    ~_SelectProps: Js.t({..})=?,
    ~_type: string=?,
    ~value: 'union_r7bk=?,
    ~component: 'union_rns2=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/TextField/TextField"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~autoComplete: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~className: option(string)=?,
      ~defaultValue:
         option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~_FormHelperTextProps: option(Js.t({..}))=?,
      ~fullWidth: option(bool)=?,
      ~helperText: option(ReasonReact.reactElement)=?,
      ~id: option(string)=?,
      ~_InputLabelProps: option(Js.t({..}))=?,
      ~_InputProps: option(Js.t({..}))=?,
      ~inputProps: option(Js.t({..}))=?,
      ~inputRef: option('genericCallback)=?,
      ~label: option(ReasonReact.reactElement)=?,
      ~margin: option(margin)=?,
      ~multiline: option(bool)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onChange: option(ReactEventRe.Form.t => unit)=?,
      ~onFocus: option(ReactEventRe.Focus.t => unit)=?,
      ~placeholder: option(string)=?,
      ~required: option(bool)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~select: option(bool)=?,
      ~_SelectProps: option(Js.t({..}))=?,
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
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
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
        ~error?,
        ~_FormHelperTextProps?,
        ~fullWidth?,
        ~helperText?,
        ~id?,
        ~_InputLabelProps?,
        ~_InputProps?,
        ~inputProps?,
        ~inputRef?,
        ~label?,
        ~margin=?margin |. Belt.Option.map(v => marginToJs(v)),
        ~multiline?,
        ~name?,
        ~onBlur?,
        ~onChange?,
        ~onFocus?,
        ~placeholder?,
        ~required?,
        ~rows=?
          rows |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~rowsMax=?
          rowsMax |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~select?,
        ~_SelectProps?,
        ~_type=?type_,
        ~value=?
          value |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        (),
      ),
    children,
  );
