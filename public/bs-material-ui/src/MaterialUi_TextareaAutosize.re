[@bs.obj]
external makePropsMui:
  (
    ~className: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~placeholder: string=?,
    ~rows: 'union_rxro=?,
    ~rowsMax: 'union_r08z=?,
    ~value: 'any_rxxf=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~className: option(string)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~placeholder: option(string)=?,
      ~rows: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~value: option('any_rxxf)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~onChange?,
    ~placeholder?,
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMax=?
      rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~value?,
    ~key?,
    ~_ref=?ref_,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TextareaAutosize";
