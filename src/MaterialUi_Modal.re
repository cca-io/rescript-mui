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
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Hidden(className) =>
               Js.Dict.set(obj, to_string(classType), className)
             };
             obj;
           },
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~_BackdropComponent: 'union_rw36=?,
    ~_BackdropProps: Js.t({..})=?,
    ~className: string=?,
    ~container: 'union_rjqp=?,
    ~disableAutoFocus: bool=?,
    ~disableBackdropClick: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~disableRestoreFocus: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onBackdropClick: ReactEventRe.Mouse.t => unit=?,
    ~onClose: 'any_rtq0=?,
    ~onEscapeKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onRendered: ReactEventRe.Synthetic.t => unit=?,
    ~open_: bool,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Modal/Modal"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~_BackdropComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~_BackdropProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~disableAutoFocus: option(bool)=?,
      ~disableBackdropClick: option(bool)=?,
      ~disableEnforceFocus: option(bool)=?,
      ~disableEscapeKeyDown: option(bool)=?,
      ~disableRestoreFocus: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~manager: option(Js.t({..}))=?,
      ~onBackdropClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~onClose: option((ReactEventRe.Synthetic.t, string) => unit)=?,
      ~onEscapeKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onRendered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~open_: bool,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_BackdropComponent=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _BackdropComponent,
          ),
        ~_BackdropProps?,
        ~className?,
        ~container=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            container,
          ),
        ~disableAutoFocus?,
        ~disableBackdropClick?,
        ~disableEnforceFocus?,
        ~disableEscapeKeyDown?,
        ~disableRestoreFocus?,
        ~hideBackdrop?,
        ~keepMounted?,
        ~manager?,
        ~onBackdropClick?,
        ~onClose?,
        ~onEscapeKeyDown?,
        ~onRendered?,
        ~open_,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
