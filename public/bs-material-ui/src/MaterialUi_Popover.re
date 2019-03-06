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
    horizontal: [ | `Int(int) | `Float(float) | `Enum(horizontal_enum)],
    vertical: [ | `Int(int) | `Float(float) | `Enum(vertical_enum)],
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      unwrappedMap->(
                      Js.Dict.set(
                        "horizontal",
                        (
                          fun
                          | `Enum(v) =>
                            MaterialUi_Helpers.unwrapValue(
                              `String(horizontal_enumToJs(v)),
                            )

                          | v => MaterialUi_Helpers.unwrapValue(v)
                        )(
                          obj->horizontalGet,
                        )
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      unwrappedMap->(
                      Js.Dict.set(
                        "vertical",
                        (
                          fun
                          | `Enum(v) =>
                            MaterialUi_Helpers.unwrapValue(
                              `String(vertical_enumToJs(v)),
                            )

                          | v => MaterialUi_Helpers.unwrapValue(v)
                        )(
                          obj->verticalGet,
                        )
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      Some(unwrappedMap);
    | None => None
    };
  };
};

module AnchorPosition = {
  [@bs.deriving abstract]
  type t = {
    left: [ | `Int(int) | `Float(float)],
    top: [ | `Int(int) | `Float(float)],
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      unwrappedMap->(
                      Js.Dict.set(
                        "left",
                        MaterialUi_Helpers.unwrapValue(obj->leftGet)
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      unwrappedMap->(
                      Js.Dict.set(
                        "top",
                        MaterialUi_Helpers.unwrapValue(obj->topGet)
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      Some(unwrappedMap);
    | None => None
    };
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
    horizontal: [ | `Int(int) | `Float(float) | `Enum(horizontal_enum)],
    vertical: [ | `Int(int) | `Float(float) | `Enum(vertical_enum)],
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      unwrappedMap->(
                      Js.Dict.set(
                        "horizontal",
                        (
                          fun
                          | `Enum(v) =>
                            MaterialUi_Helpers.unwrapValue(
                              `String(horizontal_enumToJs(v)),
                            )

                          | v => MaterialUi_Helpers.unwrapValue(v)
                        )(
                          obj->horizontalGet,
                        )
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      unwrappedMap->(
                      Js.Dict.set(
                        "vertical",
                        (
                          fun
                          | `Enum(v) =>
                            MaterialUi_Helpers.unwrapValue(
                              `String(vertical_enumToJs(v)),
                            )

                          | v => MaterialUi_Helpers.unwrapValue(v)
                        )(
                          obj->verticalGet,
                        )
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      Some(unwrappedMap);
    | None => None
    };
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

[@bs.deriving jsConverter]
type transitionDuration_enum = [ | [@bs.as "auto"] `Auto];

module Classes = {
  type classesType =
    | Paper(string);
  type t = list(classesType);
  let to_string =
    fun
    | Paper(_) => "paper";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Paper(className) =>
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
    ~action: 'any_rwen=?,
    ~anchorEl: 'union_rwdq=?,
    ~anchorOrigin: 'any_r8l0=?,
    ~anchorPosition: 'any_rbsx=?,
    ~anchorReference: string=?,
    ~container: 'union_r5rp=?,
    ~elevation: 'number_w=?,
    ~getContentAnchorEl: 'genericCallback=?,
    ~marginThreshold: 'number_5=?,
    ~_ModalClasses: Js.t({..})=?,
    ~onClose: 'any_rqdi=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~role: string=?,
    ~transformOrigin: 'any_rv55=?,
    ~_TransitionComponent: 'union_r9hm=?,
    ~transitionDuration: 'union_rvuu=?,
    ~_TransitionProps: Js.t({..})=?,
    ~_BackdropComponent: 'union_r62r=?,
    ~_BackdropProps: Js.t({..})=?,
    ~className: string=?,
    ~closeAfterTransition: bool=?,
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
    ~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Popover";
let make =
    (
      ~action: option(Js.t({..}) => unit)=?,
      ~anchorEl:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
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
      ~_ModalClasses: option(Js.t({..}))=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~role: option(string)=?,
      ~transformOrigin: option(TransformOrigin.t)=?,
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
             | `Enum(transitionDuration_enum)
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
      ~_BackdropProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~closeAfterTransition: option(bool)=?,
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
      ~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~anchorEl=?
          anchorEl->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~anchorOrigin=?AnchorOrigin.unwrap(anchorOrigin),
        ~anchorPosition=?AnchorPosition.unwrap(anchorPosition),
        ~anchorReference=?
          anchorReference->(Belt.Option.map(v => anchorReferenceToJs(v))),
        ~container=?
          container->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~elevation=?
          elevation->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~getContentAnchorEl?,
        ~marginThreshold=?
          marginThreshold->(
                             Belt.Option.map(v =>
                               MaterialUi_Helpers.unwrapValue(v)
                             )
                           ),
        ~_ModalClasses?,
        ~onClose?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~onExiting?,
        ~_open=open_,
        ~_PaperProps?,
        ~role?,
        ~transformOrigin=?TransformOrigin.unwrap(transformOrigin),
        ~_TransitionComponent=?
          _TransitionComponent->(
                                  Belt.Option.map(v =>
                                    MaterialUi_Helpers.unwrapValue(v)
                                  )
                                ),
        ~transitionDuration=?
          transitionDuration->(
                                Belt.Option.map(v =>
                                  switch (v) {
                                  | `Enum(v) =>
                                    MaterialUi_Helpers.unwrapValue(
                                      `String(
                                        transitionDuration_enumToJs(v),
                                      ),
                                    )

                                  | v => MaterialUi_Helpers.unwrapValue(v)
                                  }
                                )
                              ),
        ~_TransitionProps?,
        ~_BackdropComponent=?
          _BackdropComponent->(
                                Belt.Option.map(v =>
                                  MaterialUi_Helpers.unwrapValue(v)
                                )
                              ),
        ~_BackdropProps?,
        ~className?,
        ~closeAfterTransition?,
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
        ~onEscapeKeyDown?,
        ~onRendered?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
