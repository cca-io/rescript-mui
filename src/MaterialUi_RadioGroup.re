[@bs.obj]
external makeProps:
  (
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_rr23=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: string=?,
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
      ~value: option(string)=?,
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
        ~value?,
        ~className?,
        ~row?,
        (),
      ),
    children,
  );
