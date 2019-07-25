[@bs.deriving jsConverter]
type horizontal = [
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
];

[@bs.deriving jsConverter]
type vertical = [ | [@bs.as "top"] `Top | [@bs.as "bottom"] `Bottom];

module AnchorOrigin = {
  [@bs.deriving abstract]
  type t = {
    horizontal,
    vertical,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      unwrappedMap->(
                      Js.Dict.set(
                        "horizontal",
                        horizontalToJs(obj->horizontalGet)
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      unwrappedMap->(
                      Js.Dict.set(
                        "vertical",
                        verticalToJs(obj->verticalGet)
                        ->MaterialUi_Helpers.toJsUnsafe,
                      )
                    );

      Some(unwrappedMap);
    | None => None
    };
  };
};

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
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
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
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~action: React.element=?,
    ~anchorOrigin: 'any_rvza=?,
    ~autoHideDuration: 'number_u=?,
    ~children: 'children=?,
    ~className: string=?,
    ~_ClickAwayListenerProps: Js.t({..})=?,
    ~_ContentProps: Js.t({..})=?,
    ~disableWindowBlurListener: bool=?,
    ~key: string=?,
    ~message: React.element=?,
    ~onClose: 'any_rqj6=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~_open: bool=?,
    ~resumeHideDuration: 'number_z=?,
    ~transitionDuration: 'union_r40o=?,
    ~_TransitionProps: Js.t({..})=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~action: option(React.element)=?,
      ~anchorOrigin: option(AnchorOrigin.t)=?,
      ~autoHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~_ClickAwayListenerProps: option(Js.t({..}))=?,
      ~_ContentProps: option(Js.t({..}))=?,
      ~disableWindowBlurListener: option(bool)=?,
      ~key: option(string)=?,
      ~message: option(React.element)=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
      ~onMouseEnter: option(ReactEvent.Mouse.t => unit)=?,
      ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
      ~open_: option(bool)=?,
      ~resumeHideDuration: option([ | `Int(int) | `Float(float)])=?,
      ~transitionDuration:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(TransitionDuration_shape.t)
           ],
         )=?,
      ~_TransitionProps: option(Js.t({..}))=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~action?,
    ~anchorOrigin=?AnchorOrigin.unwrap(anchorOrigin),
    ~autoHideDuration=?
      autoHideDuration->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
    ~children?,
    ~className?,
    ~_ClickAwayListenerProps?,
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
    ~_open=?open_,
    ~resumeHideDuration=?
      resumeHideDuration->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
    ~transitionDuration=?
      transitionDuration->(
                            Belt.Option.map(v =>
                              MaterialUi_Helpers.unwrapValue(v)
                            )
                          ),
    ~_TransitionProps?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Snackbar";
