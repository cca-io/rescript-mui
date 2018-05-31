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
type transitionDuration_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
};

module Classes = {
  type classesType =
    | Root(string)
    | AnchorOriginTopCenter(string)
    | AnchorOriginBottomCenter(string)
    | AnchorOriginTopRight(string)
    | AnchorOriginBottomRight(string)
    | AnchorOriginTopLeft(string)
    | AnchorOriginBottomLeft(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | AnchorOriginTopCenter(_) => "anchorOriginTopCenter"
    | AnchorOriginBottomCenter(_) => "anchorOriginBottomCenter"
    | AnchorOriginTopRight(_) => "anchorOriginTopRight"
    | AnchorOriginBottomRight(_) => "anchorOriginBottomRight"
    | AnchorOriginTopLeft(_) => "anchorOriginTopLeft"
    | AnchorOriginBottomLeft(_) => "anchorOriginBottomLeft";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | AnchorOriginTopCenter(className)
             | AnchorOriginBottomCenter(className)
             | AnchorOriginTopRight(className)
             | AnchorOriginBottomRight(className)
             | AnchorOriginTopLeft(className)
             | AnchorOriginBottomLeft(className) =>
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
    ~action: ReasonReact.reactElement=?,
    ~anchorOrigin: anchorOrigin=?,
    ~autoHideDuration: 'number_v=?,
    ~className: string=?,
    ~_ContentProps: Js.t({..})=?,
    ~disableWindowBlurListener: bool=?,
    ~key: 'any_rbdc=?,
    ~message: ReasonReact.reactElement=?,
    ~onClose: 'any_rw4u=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~onMouseEnter: ReactEventRe.Mouse.t => unit=?,
    ~onMouseLeave: ReactEventRe.Mouse.t => unit=?,
    ~open_: bool=?,
    ~resumeHideDuration: 'number_w=?,
    ~_TransitionComponent: 'union_rbeq=?,
    ~transitionDuration: 'union_rrhw=?,
    ~_TransitionProps: Js.t({..})=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Snackbar/Snackbar"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~action: option(ReasonReact.reactElement)=?,
      ~anchorOrigin: option(anchorOrigin)=?,
      ~autoHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~className: option(string)=?,
      ~_ContentProps: option(Js.t({..}))=?,
      ~disableWindowBlurListener: option(bool)=?,
      ~key: option('any_rbdc)=?,
      ~message: option(ReasonReact.reactElement)=?,
      ~onClose: option((ReactEventRe.Synthetic.t, string) => unit)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onMouseEnter: option(ReactEventRe.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEventRe.Mouse.t => unit)=?,
      ~open_: option(bool)=?,
      ~resumeHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~_TransitionComponent:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(transitionDuration_shape)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~anchorOrigin?,
        ~autoHideDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            autoHideDuration,
          ),
        ~className?,
        ~_ContentProps?,
        ~disableWindowBlurListener?,
        ~key?,
        ~message?,
        ~onClose?,
        ~onEnter?,
        ~onEntered?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~onExiting?,
        ~onMouseEnter?,
        ~onMouseLeave?,
        ~open_?,
        ~resumeHideDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            resumeHideDuration,
          ),
        ~_TransitionComponent=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            _TransitionComponent,
          ),
        ~transitionDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            transitionDuration,
          ),
        ~_TransitionProps?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
