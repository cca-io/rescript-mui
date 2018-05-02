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
  (~enter: 'number_6=?, ~exit: 'number_2=?, unit) =>
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

module Classes = {
  type classesType =
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
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
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
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~anchor: string=?,
    ~className: string=?,
    ~elevation: 'number_p=?,
    ~_ModalProps: Js.t({..})=?,
    ~onClose: 'any_rvln=?,
    ~_open: bool=?,
    ~_PaperProps: Js.t({..})=?,
    ~_SlideProps: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_r9mr=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Drawer/Drawer"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~anchor: option(anchor)=?,
      ~className: option(string)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~_ModalProps: option(Js.t({..}))=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~_open: option(bool)=?,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_SlideProps: option(Js.t({..}))=?,
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
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~anchor=?Js.Option.map((. v) => anchorToJs(v), anchor),
        ~className?,
        ~elevation=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            elevation,
          ),
        ~_ModalProps?,
        ~onClose?,
        ~_open?,
        ~_PaperProps?,
        ~_SlideProps?,
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
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
