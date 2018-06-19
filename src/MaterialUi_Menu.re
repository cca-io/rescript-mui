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

[@bs.deriving jsConverter]
type transitionDuration_enum = [ | [@bs.as "auto"] `Auto];

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
        |. horizontal
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
        |. vertical
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

module AnchorPosition = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    top: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    left: [ | `Int(int) | `Float(float)],
  };
  let make = t;
  let unwrap = (obj: option(t)) =>
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();
      switch (
        obj |. top |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
      ) {
      | Some(v) =>
        unwrappedMap |. Js.Dict.set("top", v |. MaterialUi_Helpers.toJsUnsafe)
      | None => ()
      };
      switch (
        obj |. left |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
      ) {
      | Some(v) =>
        unwrappedMap
        |. Js.Dict.set("left", v |. MaterialUi_Helpers.toJsUnsafe)
      | None => ()
      };
      Some(unwrappedMap);
    | None => None
    };
};

[@bs.deriving jsConverter]
type anchorReference = [
  | [@bs.as "anchorEl"] `AnchorEl
  | [@bs.as "anchorPosition"] `AnchorPosition
  | [@bs.as "none"] `None
];

module TransformOrigin = {
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
        |. horizontal
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
        |. vertical
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

module Classes = {
  type classesType =
    | Paper(string);
  type t = list(classesType);
  let to_string =
    fun
    | Paper(_) => "paper";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Paper(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~anchorEl: 'any_rfj7=?,
    ~_MenuListProps: Js.t({..})=?,
    ~onClose: 'any_ror2=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_PopoverClasses: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_ruzh=?,
    ~action: 'any_rj61=?,
    ~anchorOrigin: 'any_rq94=?,
    ~anchorPosition: 'any_rt7k=?,
    ~anchorReference: string=?,
    ~container: 'union_rgco=?,
    ~elevation: 'number_1=?,
    ~getContentAnchorEl: 'genericCallback=?,
    ~marginThreshold: 'number_i=?,
    ~role: string=?,
    ~transformOrigin: 'any_rhn8=?,
    ~_TransitionComponent: 'union_rr6s=?,
    ~_TransitionProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Menu/Menu"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~anchorEl: option('any_rfj7)=?,
      ~_MenuListProps: option(Js.t({..}))=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~open_: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_PopoverClasses: option(Js.t({..}))=?,
      ~theme: option(Js.t({..}))=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
             | `Enum(transitionDuration_enum)
           ],
         )=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~anchorOrigin: option(AnchorOrigin.t)=?,
      ~anchorPosition: option(AnchorPosition.t)=?,
      ~anchorReference: option(anchorReference)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~getContentAnchorEl: option('genericCallback)=?,
      ~marginThreshold: option([ | `Int(int) | `Float(float)])=?,
      ~role: option(string)=?,
      ~transformOrigin: option(TransformOrigin.t)=?,
      ~_TransitionComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
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
        ~anchorEl?,
        ~_MenuListProps?,
        ~onClose?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~onExiting?,
        ~_open=open_,
        ~_PaperProps?,
        ~_PopoverClasses?,
        ~theme?,
        ~transitionDuration=?
          transitionDuration
          |. Belt.Option.map(v =>
               switch (v) {
               | `Enum(v) =>
                 MaterialUi_Helpers.unwrapValue(
                   `String(transitionDuration_enumToJs(v)),
                 )
               | v => MaterialUi_Helpers.unwrapValue(v)
               }
             ),
        ~action?,
        ~anchorOrigin=?AnchorOrigin.unwrap(anchorOrigin),
        ~anchorPosition=?AnchorPosition.unwrap(anchorPosition),
        ~anchorReference=?
          anchorReference |. Belt.Option.map(v => anchorReferenceToJs(v)),
        ~container=?
          container |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~elevation=?
          elevation |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~getContentAnchorEl?,
        ~marginThreshold=?
          marginThreshold
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~role?,
        ~transformOrigin=?TransformOrigin.unwrap(transformOrigin),
        ~_TransitionComponent=?
          _TransitionComponent
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_TransitionProps?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
