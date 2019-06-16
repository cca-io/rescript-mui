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

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "menu"] `Menu
  | [@bs.as "selectedMenu"] `SelectedMenu
];

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

module Classes = {
  type classesType =
    | Paper(string)
    | List(string);
  type t = list(classesType);
  let to_string =
    fun
    | Paper(_) => "paper"
    | List(_) => "list";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Paper(className)
                         | List(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~anchorEl: 'any_rgrl=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~disableAutoFocusItem: bool=?,
    ~_MenuListProps: Js.t({..})=?,
    ~onClose: 'any_rc9p=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_PopoverClasses: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_r9t9=?,
    ~variant: string=?,
    ~action: 'any_r3of=?,
    ~anchorOrigin: 'any_rv1s=?,
    ~anchorPosition: 'any_r3d9=?,
    ~anchorReference: string=?,
    ~container: 'union_r0j2=?,
    ~elevation: 'number_c=?,
    ~getContentAnchorEl: 'genericCallback=?,
    ~marginThreshold: 'number_7=?,
    ~_ModalClasses: Js.t({..})=?,
    ~transformOrigin: 'any_r7ip=?,
    ~_TransitionProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Menu";

[@react.component]
let make =
    (
      ~anchorEl: option('any_rgrl)=?,
      ~autoFocus: option(bool)=?,
      ~children: option('children)=?,
      ~disableAutoFocusItem: option(bool)=?,
      ~_MenuListProps: option(Js.t({..}))=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
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
      ~variant: option(variant)=?,
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
      ~_ModalClasses: option(Js.t({..}))=?,
      ~transformOrigin: option(TransformOrigin.t)=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~anchorEl?,
      ~autoFocus?,
      ~children?,
      ~disableAutoFocusItem?,
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
        transitionDuration->(
                              Belt.Option.map(v =>
                                switch (v) {
                                | `Enum(v) =>
                                  MaterialUi_Helpers.unwrapValue(
                                    `String(transitionDuration_enumToJs(v)),
                                  )

                                | v => MaterialUi_Helpers.unwrapValue(v)
                                }
                              )
                            ),
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      ~action?,
      ~anchorOrigin=?AnchorOrigin.unwrap(anchorOrigin),
      ~anchorPosition=?AnchorPosition.unwrap(anchorPosition),
      ~anchorReference=?
        anchorReference->(Belt.Option.map(v => anchorReferenceToJs(v))),
      ~container=?
        container->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~elevation=?
        elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~getContentAnchorEl?,
      ~marginThreshold=?
        marginThreshold->(
                           Belt.Option.map(v =>
                             MaterialUi_Helpers.unwrapValue(v)
                           )
                         ),
      ~_ModalClasses?,
      ~transformOrigin=?TransformOrigin.unwrap(transformOrigin),
      ~_TransitionProps?,
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
