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
type variant = [
  | [@bs.as "permanent"] `Permanent
  | [@bs.as "persistent"] `Persistent
  | [@bs.as "temporary"] `Temporary
];

[@bs.obj]
external makeProps :
  (
    ~anchor: string=?,
    ~disableBackdropTransition: bool=?,
    ~disableDiscovery: bool=?,
    ~disableSwipeToOpen: bool=?,
    ~_ModalProps: Js.t({..})=?,
    ~onClose: 'any_rjun,
    ~onOpen: 'any_rsu1,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~swipeAreaWidth: 'number_8=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_rcum=?,
    ~variant: string=?,
    ~className: string=?,
    ~elevation: 'number_8=?,
    ~_SlideProps: Js.t({..})=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/SwipeableDrawer/SwipeableDrawer"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~anchor: option(anchor)=?,
      ~disableBackdropTransition: option(bool)=?,
      ~disableDiscovery: option(bool)=?,
      ~disableSwipeToOpen: option(bool)=?,
      ~_ModalProps: option(Js.t({..}))=?,
      ~onClose: ReactEventRe.Synthetic.t => unit,
      ~onOpen: ReactEventRe.Synthetic.t => unit,
      ~open_: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~swipeAreaWidth: option([ | `Int(int) | `Float(float)])=?,
      ~theme: option(Js.t({..}))=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
           ],
         )=?,
      ~variant: option(variant)=?,
      ~className: option(string)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~_SlideProps: option(Js.t({..}))=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~anchor=?anchor |. Belt.Option.map(v => anchorToJs(v)),
        ~disableBackdropTransition?,
        ~disableDiscovery?,
        ~disableSwipeToOpen?,
        ~_ModalProps?,
        ~onClose,
        ~onOpen,
        ~_open=open_,
        ~_PaperProps?,
        ~swipeAreaWidth=?
          swipeAreaWidth
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~theme?,
        ~transitionDuration=?
          transitionDuration
          |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~variant=?variant |. Belt.Option.map(v => variantToJs(v)),
        ~className?,
        ~elevation=?
          elevation |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~_SlideProps?,
        (),
      ),
    children,
  );
