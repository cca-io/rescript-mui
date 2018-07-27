[@bs.deriving jsConverter]
type horizontal_enum = [
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
];

[@bs.deriving jsConverter]
type vertical_enum = [
  | [@bs.as "top"] `Top
  | [@bs.as "center"] `Center
  | [@bs.as "bottom"] `Bottom
];

module AnchorOrigin = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    horizontal: [ | `Int(int) | `Float(float) | `Enum(horizontal_enum)],
    [@bs.optional]
    vertical: [ | `Int(int) | `Float(float) | `Enum(vertical_enum)],
  };
  let make = t;
  let unwrap = (obj: option(t)) =>
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();
      switch (
        obj
        |. horizontalGet
        |. Belt.Option.map(v =>
             switch (v) {
             | `Enum(v) =>
               MaterialUi_Helpers.unwrapValue(
                 `String(horizontal_enumToJs(v)),
               )
             | v => MaterialUi_Helpers.unwrapValue(v)
             }
           )
      ) {
      | Some(v) =>
        unwrappedMap
        |. Js.Dict.set("horizontal", v |. MaterialUi_Helpers.toJsUnsafe)
      | None => ()
      };
      switch (
        obj
        |. verticalGet
        |. Belt.Option.map(v =>
             switch (v) {
             | `Enum(v) =>
               MaterialUi_Helpers.unwrapValue(`String(vertical_enumToJs(v)))
             | v => MaterialUi_Helpers.unwrapValue(v)
             }
           )
      ) {
      | Some(v) =>
        unwrappedMap
        |. Js.Dict.set("vertical", v |. MaterialUi_Helpers.toJsUnsafe)
      | None => ()
      };
      Some(unwrappedMap);
    | None => None
    };
};

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
      obj
      |. enterGet
      |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
    ) {
    | Some(v) =>
      unwrappedMap |. Js.Dict.set("enter", v |. MaterialUi_Helpers.toJsUnsafe)
    | None => ()
    };
    switch (
      obj
      |. exitGet
      |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
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
    | AnchorOriginTopCenter(string)
    | AnchorOriginBottomCenter(string)
    | AnchorOriginTopRight(string)
    | AnchorOriginBottomRight(string)
    | AnchorOriginTopLeft(string)
    | AnchorOriginBottomLeft(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | AnchorOriginTopCenter(_) => "anchorOriginTopCenter"
    | AnchorOriginBottomCenter(_) => "anchorOriginBottomCenter"
    | AnchorOriginTopRight(_) => "anchorOriginTopRight"
    | AnchorOriginBottomRight(_) => "anchorOriginBottomRight"
    | AnchorOriginTopLeft(_) => "anchorOriginTopLeft"
    | AnchorOriginBottomLeft(_) => "anchorOriginBottomLeft";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | AnchorOriginTopCenter(className)
           | AnchorOriginBottomCenter(className)
           | AnchorOriginTopRight(className)
           | AnchorOriginBottomRight(className)
           | AnchorOriginTopLeft(className)
           | AnchorOriginBottomLeft(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~action: ReasonReact.reactElement=?,
    ~anchorOrigin: 'any_rz7b=?,
    ~autoHideDuration: 'number_x=?,
    ~className: string=?,
    ~_ContentProps: Js.t({..})=?,
    ~disableWindowBlurListener: bool=?,
    ~key: 'any_ru74=?,
    ~message: ReasonReact.reactElement=?,
    ~onClose: 'any_re5q=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~onMouseEnter: ReactEventRe.Mouse.t => unit=?,
    ~onMouseLeave: ReactEventRe.Mouse.t => unit=?,
    ~_open: bool=?,
    ~resumeHideDuration: 'number_4=?,
    ~_TransitionComponent: 'union_rgm4=?,
    ~transitionDuration: 'union_r6w1=?,
    ~_TransitionProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Snackbar/Snackbar"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~action: option(ReasonReact.reactElement)=?,
      ~anchorOrigin: option(AnchorOrigin.t)=?,
      ~autoHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~className: option(string)=?,
      ~_ContentProps: option(Js.t({..}))=?,
      ~disableWindowBlurListener: option(bool)=?,
      ~key: option('any_ru74)=?,
      ~message: option(ReasonReact.reactElement)=?,
      ~onClose: option((ReactEventRe.Synthetic.t, string) => unit)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onMouseEnter: option(ReactEventRe.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEventRe.Mouse.t => unit)=?,
      ~open_: option(bool)=?,
      ~resumeHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~anchorOrigin=?AnchorOrigin.unwrap(anchorOrigin),
        ~autoHideDuration=?
          autoHideDuration
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~className?,
        ~_ContentProps?,
        ~disableWindowBlurListener?,
        ~key?,
        ~message?,
        ~onClose?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~onExiting?,
        ~onMouseEnter?,
        ~onMouseLeave?,
        ~_open=?open_,
        ~resumeHideDuration=?
          resumeHideDuration
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_TransitionComponent=?
          _TransitionComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~transitionDuration=?
          transitionDuration
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_TransitionProps?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
