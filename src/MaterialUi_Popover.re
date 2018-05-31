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

[@bs.deriving abstract]
type transitionDuration_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
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
    ~action: 'any_r3rf=?,
    ~anchorEl: 'union_rp1q=?,
    ~anchorOrigin: anchorOrigin=?,
    ~anchorPosition: anchorPosition=?,
    ~anchorReference: string=?,
    ~container: 'union_r566=?,
    ~elevation: 'number_6=?,
    ~getContentAnchorEl: 'genericCallback=?,
    ~marginThreshold: 'number_c=?,
    ~onClose: 'any_re27=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~open_: bool,
    ~_PaperProps: Js.t({..})=?,
    ~role: string=?,
    ~transformOrigin: transformOrigin=?,
    ~_TransitionComponent: 'union_rxnm=?,
    ~transitionDuration: 'union_rt3j=?,
    ~_TransitionProps: Js.t({..})=?,
    ~_BackdropComponent: 'union_rbf5=?,
    ~_BackdropProps: Js.t({..})=?,
    ~className: string=?,
    ~disableAutoFocus: bool=?,
    ~disableBackdropClick: bool=?,
    ~disableEnforceFocus: bool=?,
    ~disableEscapeKeyDown: bool=?,
    ~disableRestoreFocus: bool=?,
    ~hideBackdrop: bool=?,
    ~keepMounted: bool=?,
    ~manager: Js.t({..})=?,
    ~onBackdropClick: ReactEventRe.Mouse.t => unit=?,
    ~onEscapeKeyDown: ReactEventRe.Keyboard.t => unit=?,
    ~onRendered: ReactEventRe.Synthetic.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Popover/Popover"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~action: option(Js.t({..}) => unit)=?,
      ~anchorEl:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
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
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~open_: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~role: option(string)=?,
      ~transformOrigin: option(transformOrigin)=?,
      ~_TransitionComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(transitionDuration_shape)
             | `Enum(transitionDuration_enum)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~_BackdropComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~_BackdropProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~disableAutoFocus: option(bool)=?,
      ~disableBackdropClick: option(bool)=?,
      ~disableEnforceFocus: option(bool)=?,
      ~disableEscapeKeyDown: option(bool)=?,
      ~disableRestoreFocus: option(bool)=?,
      ~hideBackdrop: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~manager: option(Js.t({..}))=?,
      ~onBackdropClick: option(ReactEventRe.Mouse.t => unit)=?,
      ~onEscapeKeyDown: option(ReactEventRe.Keyboard.t => unit)=?,
      ~onRendered: option(ReactEventRe.Synthetic.t => unit)=?,
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
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            anchorEl,
          ),
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
        ~onClose?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~onExiting?,
        ~open_,
        ~_PaperProps?,
        ~role?,
        ~transformOrigin?,
        ~_TransitionComponent=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _TransitionComponent,
          ),
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
        ~_TransitionProps?,
        ~_BackdropComponent=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _BackdropComponent,
          ),
        ~_BackdropProps?,
        ~className?,
        ~disableAutoFocus?,
        ~disableBackdropClick?,
        ~disableEnforceFocus?,
        ~disableEscapeKeyDown?,
        ~disableRestoreFocus?,
        ~hideBackdrop?,
        ~keepMounted?,
        ~manager?,
        ~onBackdropClick?,
        ~onEscapeKeyDown?,
        ~onRendered?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
