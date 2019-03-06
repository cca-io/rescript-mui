[@bs.deriving jsConverter]
type maxWidth = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "lg"] `Lg
  | [@bs.as "xl"] `Xl
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type scroll = [ | [@bs.as "body"] `Body | [@bs.as "paper"] `Paper];

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
      obj->enterGet->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("enter", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    switch (
      obj->exitGet->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("exit", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

    unwrappedMap;
  };
};

module Classes = {
  type classesType =
    | Root(string)
    | ScrollPaper(string)
    | ScrollBody(string)
    | Container(string)
    | Paper(string)
    | PaperScrollPaper(string)
    | PaperScrollBody(string)
    | PaperWidthXs(string)
    | PaperWidthSm(string)
    | PaperWidthMd(string)
    | PaperWidthLg(string)
    | PaperWidthXl(string)
    | PaperFullWidth(string)
    | PaperFullScreen(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ScrollPaper(_) => "scrollPaper"
    | ScrollBody(_) => "scrollBody"
    | Container(_) => "container"
    | Paper(_) => "paper"
    | PaperScrollPaper(_) => "paperScrollPaper"
    | PaperScrollBody(_) => "paperScrollBody"
    | PaperWidthXs(_) => "paperWidthXs"
    | PaperWidthSm(_) => "paperWidthSm"
    | PaperWidthMd(_) => "paperWidthMd"
    | PaperWidthLg(_) => "paperWidthLg"
    | PaperWidthXl(_) => "paperWidthXl"
    | PaperFullWidth(_) => "paperFullWidth"
    | PaperFullScreen(_) => "paperFullScreen";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | ScrollPaper(className)
                         | ScrollBody(className)
                         | Container(className)
                         | Paper(className)
                         | PaperScrollPaper(className)
                         | PaperScrollBody(className)
                         | PaperWidthXs(className)
                         | PaperWidthSm(className)
                         | PaperWidthMd(className)
                         | PaperWidthLg(className)
                         | PaperWidthXl(className)
                         | PaperFullWidth(className)
                         | PaperFullScreen(className) =>
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
    ~disableBackdropClick: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~fullScreen: bool=?,
    ~fullWidth: bool=?,
    ~maxWidth: string=?,
    ~onBackdropClick: ReactEvent.Mouse.t => unit=?,
    ~onClose: 'any_rlps=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperComponent: 'union_rdjp=?,
    ~_PaperProps: Js.t({..})=?,
    ~scroll: string=?,
    ~_TransitionComponent: 'union_ru51=?,
    ~transitionDuration: 'union_ryqp=?,
    ~_TransitionProps: Js.t({..})=?,
    ~_BackdropComponent: 'union_rhmu=?,
    ~closeAfterTransition: bool=?,
    ~container: 'union_r5za=?,
    ~disableAutoFocus: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disablePortal: bool=?,
    ~disableRestoreFocus: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Dialog";
let make =
    (
      ~_BackdropProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~disableBackdropClick: option(bool)=?,
      ~disableEscapeKeyDown: option(bool)=?,
      ~fullScreen: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~maxWidth: option(maxWidth)=?,
      ~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: bool,
      ~_PaperComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~_PaperProps: option(Js.t({..}))=?,
      ~scroll: option(scroll)=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
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
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~closeAfterTransition: option(bool)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~disableAutoFocus: option(bool)=?,
      ~disableEnforceFocus: option(bool)=?,
      ~disablePortal: option(bool)=?,
      ~disableRestoreFocus: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~manager: option(Js.t({..}))=?,
      ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
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
        ~maxWidth=?maxWidth->(Belt.Option.map(v => maxWidthToJs(v))),
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
        ~_PaperComponent=?
          _PaperComponent->(
                             Belt.Option.map(v =>
                               MaterialUi_Helpers.unwrapValue(v)
                             )
                           ),
        ~_PaperProps?,
        ~scroll=?scroll->(Belt.Option.map(v => scrollToJs(v))),
        ~_TransitionComponent=?
          _TransitionComponent->(
                                  Belt.Option.map(v =>
                                    MaterialUi_Helpers.unwrapValue(v)
                                  )
                                ),
        ~transitionDuration=?
          transitionDuration->(
                                Belt.Option.map(v =>
                                  MaterialUi_Helpers.unwrapValue(v)
                                )
                              ),
        ~_TransitionProps?,
        ~_BackdropComponent=?
          _BackdropComponent->(
                                Belt.Option.map(v =>
                                  MaterialUi_Helpers.unwrapValue(v)
                                )
                              ),
        ~closeAfterTransition?,
        ~container=?
          container->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~disableAutoFocus?,
        ~disableEnforceFocus?,
        ~disablePortal?,
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
