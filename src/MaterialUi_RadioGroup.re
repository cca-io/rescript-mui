[@bs.obj]
external makeProps :
  (
    ~name: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onChange: 'any_rcn6=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~value: string=?,
    ~className: string=?,
    ~row: bool=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/RadioGroup/RadioGroup"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~name: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onChange: option((ReactEventRe.Form.t, string) => unit)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
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
