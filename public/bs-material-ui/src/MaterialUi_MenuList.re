[@bs.obj]
external makeProps:
  (
    ~className: string=?,
    ~disableListWrap: bool=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~component: 'union_raof=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "MenuList";
let make =
    (
      ~className: option(string)=?,
      ~disableListWrap: option(bool)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
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
        ~disableListWrap?,
        ~onBlur?,
        ~onKeyDown?,
        ~component=?
          component->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~dense?,
        ~disablePadding?,
        ~subheader?,
        (),
      ),
    children,
  );
