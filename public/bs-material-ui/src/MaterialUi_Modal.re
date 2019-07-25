[@bs.obj]
external makePropsMui:
  (
    ~_BackdropProps: Js.t({..})=?,
    ~children: 'children=?,
    ~closeAfterTransition: bool=?,
    ~container: 'union_rhzp=?,
    ~disableAutoFocus: bool=?,
    ~disableBackdropClick: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~disablePortal: bool=?,
    ~disableRestoreFocus: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
    ~onClose: 'any_rdl6=?,
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
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
      ~hideBackdrop: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~manager: option(Js.t({..}))=?,
      ~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: bool,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      (),
    ) =>
  makePropsMui(
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
