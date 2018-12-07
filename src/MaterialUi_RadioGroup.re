[@bs.obj]
external makeProps:
  (
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_rivc=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: 'union_rwlo=?,
    ~className: string=?,
    ~row: bool=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "RadioGroup";
let make =
    (
      ~name: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option((ReactEvent.Form.t, string) => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~value:
         option(
           [ | `String(string) | `Int(int) | `Float(float) | `Bool(bool)],
         )=?,
      ~className: option(string)=?,
      ~row: option(bool)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~name?,
        ~onBlur?,
        ~onChange?,
        ~onKeyDown?,
        ~value=?
          value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~className?,
        ~row?,
        (),
      ),
    children,
  );
