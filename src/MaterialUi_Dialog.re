[@bs.deriving jsConverter]
type maxWidth = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "false"] `False
];

module TransitionDuration_shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    enter: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    exit: [ | `Int(int) | `Float(float)],
  };
  let make = t;

  let unwrap = (obj: t) => {
    let unwrappedMap = Js.Dict.empty();

    switch (
      obj |. enter |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
    ) {
    | Some(v) =>
      unwrappedMap |. Js.Dict.set("enter", v |. MaterialUi_Helpers.toJsUnsafe)
    | None => ()
    };

    switch (
      obj |. exit |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
    ) {
    | Some(v) =>
      unwrappedMap |. Js.Dict.set("exit", v |. MaterialUi_Helpers.toJsUnsafe)
    | None => ()
    };

    unwrappedMap;
  };
};

module Classes = {
  type classesType =
    | Root(string)
    | Paper(string)
    | PaperWidthXs(string)
    | PaperWidthSm(string)
    | PaperWidthMd(string)
    | PaperFullWidth(string)
    | PaperFullScreen(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Paper(_) => "paper"
    | PaperWidthXs(_) => "paperWidthXs"
    | PaperWidthSm(_) => "paperWidthSm"
    | PaperWidthMd(_) => "paperWidthMd"
    | PaperFullWidth(_) => "paperFullWidth"
    | PaperFullScreen(_) => "paperFullScreen";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Paper(className)
           | PaperWidthXs(className)
           | PaperWidthSm(className)
           | PaperWidthMd(className)
           | PaperFullWidth(className)
           | PaperFullScreen(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~_BackdropProps: Js.t({..})=?,
    ~className: string=?,
    ~disableBackdropClick: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~fullScreen: bool=?,
    ~fullWidth: bool=?,
    ~maxWidth: string=?,
    ~onBackdropClick: ReactEventRe.Mouse.t => unit=?,
    ~onClose: 'any_r2xs=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onEscapeKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_TransitionComponent: 'union_rci5=?,
    ~transitionDuration: 'union_r6xa=?,
    ~_TransitionProps: Js.t({..})=?,
    ~_BackdropComponent: 'union_rxyf=?,
    ~container: 'union_rsbw=?,
    ~disableAutoFocus: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disableRestoreFocus: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onRendered: ReactEventRe.Synthetic.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core/Dialog/Dialog"]
external reactClass : ReasonReact.reactClass = "default";
let make =
    (
      ~_BackdropProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~disableBackdropClick: option(bool)=?,
      ~disableEscapeKeyDown: option(bool)=?,
      ~fullScreen: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~maxWidth: option(maxWidth)=?,
      ~onBackdropClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEscapeKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~open_: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_TransitionComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~_BackdropComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~disableAutoFocus: option(bool)=?,
      ~disableEnforceFocus: option(bool)=?,
      ~disableRestoreFocus: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~manager: option(Js.t({..}))=?,
      ~onRendered: option(ReactEventRe.Synthetic.t => unit)=?,
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
        ~disableBackdropClick?,
        ~disableEscapeKeyDown?,
        ~fullScreen?,
        ~fullWidth?,
        ~maxWidth=?maxWidth |. Belt.Option.map(v => maxWidthToJs(v)),
        ~onBackdropClick?,
        ~onClose?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onEscapeKeyDown?,
        ~onExit?,
        ~onExited?,
        ~onExiting?,
        ~_open=open_,
        ~_PaperProps?,
        ~_TransitionComponent=?
          _TransitionComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~transitionDuration=?
          transitionDuration
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_TransitionProps?,
        ~_BackdropComponent=?
          _BackdropComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~container=?
          container |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~disableAutoFocus?,
        ~disableEnforceFocus?,
        ~disableRestoreFocus?,
        ~hideBackdrop?,
        ~keepMounted?,
        ~manager?,
        ~onRendered?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
