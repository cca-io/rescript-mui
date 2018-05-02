[@bs.deriving jsConverter]
type anchor = [
  | [@bs.as "left"] `Left
  | [@bs.as "top"] `Top
  | [@bs.as "right"] `Right
  | [@bs.as "bottom"] `Bottom
];

type typeTransitionDuration_shape;

[@bs.obj]
external makeTransitionDuration_shape :
  (~enter: 'number_e=?, ~exit: 'number_s=?, unit) =>
  typeTransitionDuration_shape =
  "";

[@bs.get_index]
external getFromTransitionDuration_shape :
  (typeTransitionDuration_shape, string) => 'a =
  "";

let convertTransitionDuration_shape = (madeObj: typeTransitionDuration_shape) => {
  let returnObj: Js.Dict.t(string) = Js.Dict.empty();
  Js.Dict.set(
    returnObj,
    "enter",
    MaterialUi_Helpers.toJsUnsafe(
      Js.Option.map(
        (. v) => MaterialUi_Helpers.unwrapValue(v),
        getFromTransitionDuration_shape(madeObj, "enter"),
      ),
    ),
  );
  Js.Dict.set(
    returnObj,
    "exit",
    MaterialUi_Helpers.toJsUnsafe(
      Js.Option.map(
        (. v) => MaterialUi_Helpers.unwrapValue(v),
        getFromTransitionDuration_shape(madeObj, "exit"),
      ),
    ),
  );
  returnObj;
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
    ~onClose: 'any_rko4,
    ~onOpen: 'any_ru63,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~swipeAreaWidth: 'number_c=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_rp21=?,
    ~variant: string=?,
    ~className: string=?,
    ~elevation: 'number_j=?,
    ~_SlideProps: Js.t({..})=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/SwipeableDrawer/SwipeableDrawer"]
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
      ~_open: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~swipeAreaWidth: option([ | `Int(int) | `Float(float)])=?,
      ~theme: option(Js.t({..}))=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(typeTransitionDuration_shape)
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
        ~_open,
        ~_PaperProps?,
        ~swipeAreaWidth=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            swipeAreaWidth,
          ),
        ~theme?,
        ~transitionDuration=?
          Js.Option.map(
            (. v) =>
              switch (v) {
              | `Object(v) =>
                MaterialUi_Helpers.unwrapValue(
                  `Element(convertTransitionDuration_shape(v)),
                )
              | v => MaterialUi_Helpers.unwrapValue(v)
              },
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
