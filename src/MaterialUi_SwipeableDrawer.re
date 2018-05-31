[@bs.deriving jsConverter]
type anchor = [
  | [@bs.as "left"] `Left
  | [@bs.as "top"] `Top
  | [@bs.as "right"] `Right
  | [@bs.as "bottom"] `Bottom
];

[@bs.deriving abstract]
type transitionDuration_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
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
    ~onClose: 'any_rs6j,
    ~onOpen: 'any_ra0b,
    ~open_: bool,
    ~_PaperProps: Js.t({..})=?,
    ~swipeAreaWidth: 'number_4=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_r6uw=?,
    ~variant: string=?,
    ~className: string=?,
    ~elevation: 'number_b=?,
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
             | `Object(transitionDuration_shape)
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
        ~anchor=?Js.Option.map((. v) => anchorToJs(v), anchor),
        ~disableBackdropTransition?,
        ~disableDiscovery?,
        ~disableSwipeToOpen?,
        ~_ModalProps?,
        ~onClose,
        ~onOpen,
        ~open_,
        ~_PaperProps?,
        ~swipeAreaWidth=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            swipeAreaWidth,
          ),
        ~theme?,
        ~transitionDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            transitionDuration,
          ),
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~className?,
        ~elevation=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            elevation,
          ),
        ~_SlideProps?,
        (),
      ),
    children,
  );
