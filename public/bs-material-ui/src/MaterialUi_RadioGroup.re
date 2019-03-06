[@bs.obj]
external makeProps:
  (
    ~defaultValue: 'union_rjnd=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_r5dm=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: 'union_r5is=?,
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
      ~defaultValue:
         option(
           [ | `String(string) | `Int(int) | `Float(float) | `Bool(bool)],
         )=?,
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
        ~defaultValue=?
          defaultValue->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
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
