[@bs.deriving abstract]
type transitionDuration_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
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

[@bs.deriving abstract]
type anchorOrigin = {
  horizontal: [ | `Int(int) | `Float(float) | `Enum(horizontal_enum)],
  vertical: [ | `Int(int) | `Float(float) | `Enum(vertical_enum)],
};

[@bs.deriving abstract]
type anchorPosition = {
  top: [ | `Int(int) | `Float(float)],
  left: [ | `Int(int) | `Float(float)],
};

[@bs.deriving jsConverter]
type anchorReference = [
  | [@bs.as "anchorEl"] `AnchorEl
  | [@bs.as "anchorPosition"] `AnchorPosition
  | [@bs.as "none"] `None
];

[@bs.deriving abstract]
type transformOrigin = {
  horizontal: [ | `Int(int) | `Float(float) | `Enum(horizontal_enum)],
  vertical: [ | `Int(int) | `Float(float) | `Enum(vertical_enum)],
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
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Paper(className) =>
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
    ~anchorEl: 'any_rjjr=?,
    ~_MenuListProps: Js.t({..})=?,
    ~onClose: 'any_rpg8=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~open_: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_PopoverClasses: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_r26e=?,
    ~action: 'any_rxep=?,
    ~anchorOrigin: anchorOrigin=?,
    ~anchorPosition: anchorPosition=?,
    ~anchorReference: string=?,
    ~container: 'union_rdks=?,
    ~elevation: 'number_c=?,
    ~getContentAnchorEl: 'genericCallback=?,
    ~marginThreshold: 'number_s=?,
    ~role: string=?,
    ~transformOrigin: transformOrigin=?,
    ~_TransitionComponent: 'union_rchg=?,
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
      ~anchorEl: option('any_rjjr)=?,
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
             | `Object(transitionDuration_shape)
             | `Enum(transitionDuration_enum)
           ],
         )=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~anchorOrigin: option(anchorOrigin)=?,
      ~anchorPosition: option(anchorPosition)=?,
      ~anchorReference: option(anchorReference)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~getContentAnchorEl: option('genericCallback)=?,
      ~marginThreshold: option([ | `Int(int) | `Float(float)])=?,
      ~role: option(string)=?,
      ~transformOrigin: option(transformOrigin)=?,
      ~_TransitionComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
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
        ~open_,
        ~_PaperProps?,
        ~_PopoverClasses?,
        ~theme?,
        ~transitionDuration=?
          Js.Option.map(
            (. v) =>
              switch (v) {
              | `Enum(v) =>
                MaterialUi_Helpers.unwrapValue(
                  `String(transitionDuration_enumToJs(v)),
                )
              | v => MaterialUi_Helpers.unwrapValue(v)
              },
            transitionDuration,
          ),
        ~action?,
        ~anchorOrigin?,
        ~anchorPosition?,
        ~anchorReference=?
          Js.Option.map((. v) => anchorReferenceToJs(v), anchorReference),
        ~container=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            container,
          ),
        ~elevation=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            elevation,
          ),
        ~getContentAnchorEl?,
        ~marginThreshold=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            marginThreshold,
          ),
        ~role?,
        ~transformOrigin?,
        ~_TransitionComponent=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _TransitionComponent,
          ),
        ~_TransitionProps?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
