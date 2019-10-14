[@bs.deriving jsConverter]
type anchor = [
  | [@bs.as "left"] `Left
  | [@bs.as "top"] `Top
  | [@bs.as "right"] `Right
  | [@bs.as "bottom"] `Bottom
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
type variant = [
  | [@bs.as "permanent"] `Permanent
  | [@bs.as "persistent"] `Persistent
  | [@bs.as "temporary"] `Temporary
];

module Classes = {
  type classesType =
    | Root(string)
    | Docked(string)
    | Paper(string)
    | PaperAnchorLeft(string)
    | PaperAnchorRight(string)
    | PaperAnchorTop(string)
    | PaperAnchorBottom(string)
    | PaperAnchorDockedLeft(string)
    | PaperAnchorDockedTop(string)
    | PaperAnchorDockedRight(string)
    | PaperAnchorDockedBottom(string)
    | Modal(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Docked(_) => "docked"
    | Paper(_) => "paper"
    | PaperAnchorLeft(_) => "paperAnchorLeft"
    | PaperAnchorRight(_) => "paperAnchorRight"
    | PaperAnchorTop(_) => "paperAnchorTop"
    | PaperAnchorBottom(_) => "paperAnchorBottom"
    | PaperAnchorDockedLeft(_) => "paperAnchorDockedLeft"
    | PaperAnchorDockedTop(_) => "paperAnchorDockedTop"
    | PaperAnchorDockedRight(_) => "paperAnchorDockedRight"
    | PaperAnchorDockedBottom(_) => "paperAnchorDockedBottom"
    | Modal(_) => "modal";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Docked(className)
                         | Paper(className)
                         | PaperAnchorLeft(className)
                         | PaperAnchorRight(className)
                         | PaperAnchorTop(className)
                         | PaperAnchorBottom(className)
                         | PaperAnchorDockedLeft(className)
                         | PaperAnchorDockedTop(className)
                         | PaperAnchorDockedRight(className)
                         | PaperAnchorDockedBottom(className)
                         | Modal(className) =>
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
    ~anchor: string=?,
    ~_BackdropProps: Js.t({..})=?,
    ~children: 'children=?,
    ~className: string=?,
    ~elevation: 'number_e=?,
    ~_ModalProps: Js.t({..})=?,
    ~onClose: 'any_r4hi=?,
    ~_open: bool=?,
    ~_PaperProps: Js.t({..})=?,
    ~_SlideProps: Js.t({..})=?,
    ~transitionDuration: 'union_r6hi=?,
    ~variant: string=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~anchor: option(anchor)=?,
      ~_BackdropProps: option(Js.t({..}))=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~_ModalProps: option(Js.t({..}))=?,
      ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_SlideProps: option(Js.t({..}))=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
           ],
         )=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~anchor=?anchor->(Belt.Option.map(v => anchorToJs(v))),
    ~_BackdropProps?,
    ~children?,
    ~className?,
    ~elevation=?
      elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_ModalProps?,
    ~onClose?,
    ~_open=?open_,
    ~_PaperProps?,
    ~_SlideProps?,
    ~transitionDuration=?
      transitionDuration->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Drawer";
