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
[@bs.obj]
external makePropsMui:
  (
    ~anchor: string=?,
    ~disableBackdropTransition: bool=?,
    ~disableDiscovery: bool=?,
    ~disableSwipeToOpen: bool=?,
    ~hideBackdrop: bool=?,
    ~hysteresis: 'number_6=?,
    ~minFlingVelocity: 'number_3=?,
    ~_ModalProps: Js.t({..})=?,
    ~onClose: 'any_rnyh,
    ~onOpen: 'any_rwsr,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_SwipeAreaProps: Js.t({..})=?,
    ~swipeAreaWidth: 'number_q=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_r6ft=?,
    ~variant: string=?,
    ~_BackdropProps: Js.t({..})=?,
    ~children: 'children=?,
    ~className: string=?,
    ~elevation: 'number_7=?,
    ~_SlideProps: Js.t({..})=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "SwipeableDrawer";

[@react.component]
let make =
    (
      ~anchor: option(anchor)=?,
      ~disableBackdropTransition: option(bool)=?,
      ~disableDiscovery: option(bool)=?,
      ~disableSwipeToOpen: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~hysteresis: option([ | `Int(int) | `Float(float)])=?,
      ~minFlingVelocity: option([ | `Int(int) | `Float(float)])=?,
      ~_ModalProps: option(Js.t({..}))=?,
      ~onClose: ReactEvent.Synthetic.t => unit,
      ~onOpen: ReactEvent.Synthetic.t => unit,
      ~open_: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_SwipeAreaProps: option(Js.t({..}))=?,
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
      ~_BackdropProps: option(Js.t({..}))=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~_SlideProps: option(Js.t({..}))=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~anchor=?anchor->(Belt.Option.map(v => anchorToJs(v))),
      ~disableBackdropTransition?,
      ~disableDiscovery?,
      ~disableSwipeToOpen?,
      ~hideBackdrop?,
      ~hysteresis=?
        hysteresis->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~minFlingVelocity=?
        minFlingVelocity->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
      ~_ModalProps?,
      ~onClose,
      ~onOpen,
      ~_open=open_,
      ~_PaperProps?,
      ~_SwipeAreaProps?,
      ~swipeAreaWidth=?
        swipeAreaWidth->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
      ~theme?,
      ~transitionDuration=?
        transitionDuration->(
                              Belt.Option.map(v =>
                                MaterialUi_Helpers.unwrapValue(v)
                              )
                            ),
      ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
      ~_BackdropProps?,
      ~children?,
      ~className?,
      ~elevation=?
        elevation->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~_SlideProps?,
      (),
    ),
  );
