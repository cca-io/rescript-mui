[@bs.obj]
external makePropsMui:
  (
    ~className: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~placeholder: string=?,
    ~rows: 'union_rcvn=?,
    ~rowsMax: 'union_rw8f=?,
    ~rowsMin: 'union_rd33=?,
    ~value: 'any_r63f=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
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
      ~rowsMin: option([ | `String(string) | `Int(int) | `Float(float)])=?,
      ~value: option('any_r63f)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~onChange?,
    ~placeholder?,
    ~rows=?rows->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMax=?
      rowsMax->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~rowsMin=?
      rowsMin->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~value?,
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TextareaAutosize";
