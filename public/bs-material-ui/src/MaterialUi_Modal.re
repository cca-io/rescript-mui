module BackdropComponent: {
  type t;
  let string: string => t;
  let backdropComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let backdropComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module Container: {
  type t;
  let container_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let container_func = (v: MaterialUi_Types.any) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~_BackdropComponent: option(BackdropComponent.t)=?,
    ~_BackdropProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~children: option('children)=?,
    ~closeAfterTransition: option(bool)=?,
    ~container: option(Container.t)=?,
    ~disableAutoFocus: option(bool)=?,
    ~disableBackdropClick: option(bool)=?,
    ~disableEnforceFocus: option(bool)=?,
    ~disableEscapeKeyDown: option(bool)=?,
    ~disablePortal: option(bool)=?,
    ~disableRestoreFocus: option(bool)=?,
    ~disableScrollLock: option(bool)=?,
    ~hideBackdrop: option(bool)=?,
    ~keepMounted: option(bool)=?,
    ~manager: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: bool,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Modal";
