[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~onBlur: ReactEventRe.Focus.t => unit=?,
    ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~component: 'union_rtx2=?,
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
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
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
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~dense?,
        ~disablePadding?,
        ~subheader?,
        (),
      ),
    children,
  );
