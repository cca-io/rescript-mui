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

type typeAnchorOrigin;

[@bs.obj]
external makeAnchorOrigin :
  (~horizontal: 'union_ruq2=?, ~vertical: 'union_rcte=?, unit) =>
  typeAnchorOrigin =
  "";

[@bs.get_index]
external getFromAnchorOrigin : (typeAnchorOrigin, string) => 'a = "";

let convertAnchorOrigin = (madeObj: option(typeAnchorOrigin)) => {
  let returnObj: Js.Dict.t(string) = Js.Dict.empty();
  switch (madeObj) {
  | Some(madeObj) =>
    Js.Dict.set(
      returnObj,
      "horizontal",
      MaterialUi_Helpers.toJsUnsafe(
        Js.Option.map(
          (. v) =>
            switch (v) {
            | `Enum(v) =>
              MaterialUi_Helpers.unwrapValue(
                `String(horizontal_enumToJs(v)),
              )
            | v => MaterialUi_Helpers.unwrapValue(v)
            },
          getFromAnchorOrigin(madeObj, "horizontal"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "vertical",
      MaterialUi_Helpers.toJsUnsafe(
        Js.Option.map(
          (. v) =>
            switch (v) {
            | `Enum(v) =>
              MaterialUi_Helpers.unwrapValue(`String(vertical_enumToJs(v)))
            | v => MaterialUi_Helpers.unwrapValue(v)
            },
          getFromAnchorOrigin(madeObj, "vertical"),
        ),
      ),
    );
    ();
  | None => ()
  };
  Some(returnObj);
};

type typeTransitionDuration_shape;

[@bs.obj]
external makeTransitionDuration_shape :
  (~enter: 'number_9=?, ~exit: 'number_l=?, unit) =>
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
    ~anchorOrigin: 'any_rupw=?,
    ~autoHideDuration: 'number_q=?,
    ~className: string=?,
    ~disableWindowBlurListener: bool=?,
    ~key: 'any_rm99=?,
    ~message: ReasonReact.reactElement=?,
    ~onClose: 'any_rjoy=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~onMouseEnter: ReactEventRe.Mouse.t => unit=?,
    ~onMouseLeave: ReactEventRe.Mouse.t => unit=?,
    ~_open: bool=?,
    ~resumeHideDuration: 'number_k=?,
    ~_SnackbarContentProps: Js.t({..})=?,
    ~transition: 'union_rbh6=?,
    ~transitionDuration: 'union_rk7i=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Snackbar/Snackbar"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~action: option(ReasonReact.reactElement)=?,
      ~anchorOrigin: option(typeAnchorOrigin)=?,
      ~autoHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~className: option(string)=?,
      ~disableWindowBlurListener: option(bool)=?,
      ~key: option('any_rm99)=?,
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
      ~_open: option(bool)=?,
      ~resumeHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~_SnackbarContentProps: option(Js.t({..}))=?,
      ~transition:
         option([ | `String(string) | `Callback('genericCallback)])=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(typeTransitionDuration_shape)
           ],
         )=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~action?,
        ~anchorOrigin=?convertAnchorOrigin(anchorOrigin),
        ~autoHideDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            autoHideDuration,
          ),
        ~className?,
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
        ~_open?,
        ~resumeHideDuration=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            resumeHideDuration,
          ),
        ~_SnackbarContentProps?,
        ~transition=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            transition,
          ),
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
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
