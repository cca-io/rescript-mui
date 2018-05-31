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
    ~elevation: 'number_a=?,
    ~_ModalProps: Js.t({..})=?,
    ~onClose: 'any_r0b4=?,
    ~open_: bool=?,
    ~_PaperProps: Js.t({..})=?,
    ~_SlideProps: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_rzim=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Drawer/Drawer"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~anchor: option(anchor)=?,
      ~className: option(string)=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~_ModalProps: option(Js.t({..}))=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_SlideProps: option(Js.t({..}))=?,
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
        ~open_?,
        ~_PaperProps?,
        ~_SlideProps?,
        ~theme?,
        ~transitionDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            transitionDuration,
          ),
        ~variant=?Js.Option.map((. v) => variantToJs(v), variant),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
