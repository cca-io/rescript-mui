[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~component: 'union_rmku=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/MenuList/MenuList"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~onBlur: option(ReactEventRe.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~dense: option(bool)=?,
      ~disablePadding: option(bool)=?,
      ~subheader: option(ReasonReact.reactElement)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~onBlur?,
        ~onKeyDown?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~dense?,
        ~disablePadding?,
        ~subheader?,
        (),
      ),
    children,
  );
