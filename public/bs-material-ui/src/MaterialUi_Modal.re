[@bs.obj]
external makePropsMui:
  (
    ~_BackdropComponent: 'union_rjs4=?,
    ~_BackdropProps: Js.t({..})=?,
    ~children: 'children=?,
    ~closeAfterTransition: bool=?,
    ~container: 'union_rf1j=?,
    ~disableAutoFocus: bool=?,
    ~disableBackdropClick: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~disablePortal: bool=?,
    ~disableRestoreFocus: bool=?,
    ~disableScrollLock: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
    ~onClose: 'any_rkpj=?,
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~_BackdropComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.reactElement)
           ],
         )=?,
      ~_BackdropProps: option(Js.t({..}))=?,
      ~children: option('children)=?,
      ~closeAfterTransition: option(bool)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~disableAutoFocus: option(bool)=?,
      ~disableBackdropClick: option(bool)=?,
      ~disableEnforceFocus: option(bool)=?,
      ~disableEscapeKeyDown: option(bool)=?,
      ~disablePortal: option(bool)=?,
      ~disableRestoreFocus: option(bool)=?,
      ~disableScrollLock: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~manager: option(Js.t({..}))=?,
      ~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: bool,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~_BackdropComponent=?
      _BackdropComponent->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
    ~_BackdropProps?,
    ~children?,
    ~closeAfterTransition?,
    ~container=?
      container->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableAutoFocus?,
    ~disableBackdropClick?,
    ~disableEnforceFocus?,
    ~disableEscapeKeyDown?,
    ~disablePortal?,
    ~disableRestoreFocus?,
    ~disableScrollLock?,
    ~hideBackdrop?,
    ~keepMounted?,
    ~manager?,
    ~onBackdropClick?,
    ~onClose?,
    ~onEscapeKeyDown?,
    ~onRendered?,
    ~_open=open_,
    ~key?,
    ~_ref=?ref_,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Modal";
