type typeTransitionDuration_shape;

[@bs.obj]
external makeTransitionDuration_shape :
  (~enter: 'number_4=?, ~exit: 'number_i=?, unit) =>
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

type typeAnchorOrigin;

[@bs.obj]
external makeAnchorOrigin :
  (~horizontal: 'union_rqtv=?, ~vertical: 'union_rzgp=?, unit) =>
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

type typeAnchorPosition;

[@bs.obj]
external makeAnchorPosition :
  (~top: 'number_q=?, ~left: 'number_l=?, unit) => typeAnchorPosition =
  "";

[@bs.get_index]
external getFromAnchorPosition : (typeAnchorPosition, string) => 'a = "";

let convertAnchorPosition = (madeObj: option(typeAnchorPosition)) => {
  let returnObj: Js.Dict.t(string) = Js.Dict.empty();
  switch (madeObj) {
  | Some(madeObj) =>
    Js.Dict.set(
      returnObj,
      "top",
      MaterialUi_Helpers.toJsUnsafe(
        Js.Option.map(
          (. v) => MaterialUi_Helpers.unwrapValue(v),
          getFromAnchorPosition(madeObj, "top"),
        ),
      ),
    );
    Js.Dict.set(
      returnObj,
      "left",
      MaterialUi_Helpers.toJsUnsafe(
        Js.Option.map(
          (. v) => MaterialUi_Helpers.unwrapValue(v),
          getFromAnchorPosition(madeObj, "left"),
        ),
      ),
    );
    ();
  | None => ()
  };
  Some(returnObj);
};

[@bs.deriving jsConverter]
type anchorReference = [
  | [@bs.as "anchorEl"] `AnchorEl
  | [@bs.as "anchorPosition"] `AnchorPosition
  | [@bs.as "none"] `None
];

type typeTransformOrigin;

[@bs.obj]
external makeTransformOrigin :
  (~horizontal: 'union_rcvv=?, ~vertical: 'union_rdky=?, unit) =>
  typeTransformOrigin =
  "";

[@bs.get_index]
external getFromTransformOrigin : (typeTransformOrigin, string) => 'a = "";

let convertTransformOrigin = (madeObj: option(typeTransformOrigin)) => {
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
          getFromTransformOrigin(madeObj, "horizontal"),
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
          getFromTransformOrigin(madeObj, "vertical"),
        ),
      ),
    );
    ();
  | None => ()
  };
  Some(returnObj);
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
    ~anchorEl: 'any_rhhr=?,
    ~_MenuListProps: Js.t({..})=?,
    ~onClose: 'any_r2p3=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntered: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~onExiting: ReactEventRe.Synthetic.t => unit=?,
    ~_open: bool,
    ~_PaperProps: Js.t({..})=?,
    ~_PopoverClasses: Js.t({..})=?,
    ~theme: Js.t({..})=?,
    ~transitionDuration: 'union_rf1w=?,
    ~action: 'any_rj6o=?,
    ~anchorOrigin: 'any_r66u=?,
    ~anchorPosition: 'any_r5l0=?,
    ~anchorReference: string=?,
    ~container: 'union_rixc=?,
    ~elevation: 'number_q=?,
    ~getContentAnchorEl: 'genericCallback=?,
    ~marginThreshold: 'number_h=?,
    ~role: string=?,
    ~transformOrigin: 'any_rxl2=?,
    ~transition: 'union_rfx2=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Menu/Menu"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~anchorEl: option('any_rhhr)=?,
      ~_MenuListProps: option(Js.t({..}))=?,
      ~onClose: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEventRe.Synthetic.t => unit)=?,
      ~_open: bool,
      ~_PaperProps: option(Js.t({..}))=?,
      ~_PopoverClasses: option(Js.t({..}))=?,
      ~theme: option(Js.t({..}))=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(typeTransitionDuration_shape)
             | `Enum(transitionDuration_enum)
           ],
         )=?,
      ~action: option(Js.t({..}) => unit)=?,
      ~anchorOrigin: option(typeAnchorOrigin)=?,
      ~anchorPosition: option(typeAnchorPosition)=?,
      ~anchorReference: option(anchorReference)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~getContentAnchorEl: option('genericCallback)=?,
      ~marginThreshold: option([ | `Int(int) | `Float(float)])=?,
      ~role: option(string)=?,
      ~transformOrigin: option(typeTransformOrigin)=?,
      ~transition:
         option([ | `String(string) | `Callback('genericCallback)])=?,
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
        ~_open,
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
              | `Object(v) =>
                MaterialUi_Helpers.unwrapValue(
                  `Element(convertTransitionDuration_shape(v)),
                )
              | v => MaterialUi_Helpers.unwrapValue(v)
              },
            transitionDuration,
          ),
        ~action?,
        ~anchorOrigin=?convertAnchorOrigin(anchorOrigin),
        ~anchorPosition=?convertAnchorPosition(anchorPosition),
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
        ~transformOrigin=?convertTransformOrigin(transformOrigin),
        ~transition=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            transition,
          ),
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
