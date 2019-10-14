[@bs.obj]
external makePropsMui:
  (
    ~className: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~placeholder: string=?,
    ~rows: 'union_ri19=?,
    ~rowsMax: 'union_rqni=?,
    ~value: 'any_r64h=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
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
      ~value: option('any_r64h)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
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
