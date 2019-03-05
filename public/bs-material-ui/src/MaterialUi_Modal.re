module Classes = {
  type classesType =
    | Root(string)
    | Hidden(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Hidden(_) => "hidden";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Hidden(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makeProps:
  (
    ~_BackdropProps: Js.t({..})=?,
    ~className: string=?,
    ~closeAfterTransition: bool=?,
    ~container: 'union_rg4u=?,
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
    ~onClose: 'any_r98y=?,
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Modal";
let make =
    (
      ~_BackdropProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_BackdropProps?,
        ~className?,
        ~closeAfterTransition?,
        ~container=?
          container->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
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
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
