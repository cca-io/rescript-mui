[@bs.deriving jsConverter]
type color = [
  | [@bs.as "error"] `Error
  | [@bs.as "info"] `Info
  | [@bs.as "success"] `Success
  | [@bs.as "warning"] `Warning
];

module IconMapping = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    error: React.element,
    [@bs.optional]
    info: React.element,
    [@bs.optional]
    success: React.element,
    [@bs.optional]
    warning: React.element,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      switch (obj->errorGet) {
      | Some(v) =>
        unwrappedMap->(Js.Dict.set("error", v->MaterialUi_Helpers.toJsUnsafe))
      | None => ()
      };

      switch (obj->infoGet) {
      | Some(v) =>
        unwrappedMap->(Js.Dict.set("info", v->MaterialUi_Helpers.toJsUnsafe))
      | None => ()
      };

      switch (obj->successGet) {
      | Some(v) =>
        unwrappedMap->(
                        Js.Dict.set(
                          "success",
                          v->MaterialUi_Helpers.toJsUnsafe,
                        )
                      )
      | None => ()
      };

      switch (obj->warningGet) {
      | Some(v) =>
        unwrappedMap->(
                        Js.Dict.set(
                          "warning",
                          v->MaterialUi_Helpers.toJsUnsafe,
                        )
                      )
      | None => ()
      };

      Some(unwrappedMap);
    | None => None
    };
  };
};

[@bs.deriving jsConverter]
type severity = [
  | [@bs.as "error"] `Error
  | [@bs.as "info"] `Info
  | [@bs.as "success"] `Success
  | [@bs.as "warning"] `Warning
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "filled"] `Filled
  | [@bs.as "outlined"] `Outlined
  | [@bs.as "standard"] `Standard
];

module Classes = {
  type classesType =
    | Root(string)
    | StandardSuccess(string)
    | StandardInfo(string)
    | StandardWarning(string)
    | StandardError(string)
    | OutlinedSuccess(string)
    | OutlinedInfo(string)
    | OutlinedWarning(string)
    | OutlinedError(string)
    | FilledSuccess(string)
    | FilledInfo(string)
    | FilledWarning(string)
    | FilledError(string)
    | Icon(string)
    | Message(string)
    | Action(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | StandardSuccess(_) => "standardSuccess"
    | StandardInfo(_) => "standardInfo"
    | StandardWarning(_) => "standardWarning"
    | StandardError(_) => "standardError"
    | OutlinedSuccess(_) => "outlinedSuccess"
    | OutlinedInfo(_) => "outlinedInfo"
    | OutlinedWarning(_) => "outlinedWarning"
    | OutlinedError(_) => "outlinedError"
    | FilledSuccess(_) => "filledSuccess"
    | FilledInfo(_) => "filledInfo"
    | FilledWarning(_) => "filledWarning"
    | FilledError(_) => "filledError"
    | Icon(_) => "icon"
    | Message(_) => "message"
    | Action(_) => "action";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | StandardSuccess(className)
                         | StandardInfo(className)
                         | StandardWarning(className)
                         | StandardError(className)
                         | OutlinedSuccess(className)
                         | OutlinedInfo(className)
                         | OutlinedWarning(className)
                         | OutlinedError(className)
                         | FilledSuccess(className)
                         | FilledInfo(className)
                         | FilledWarning(className)
                         | FilledError(className)
                         | Icon(className)
                         | Message(className)
                         | Action(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~closeText: string=?,
    ~color: string=?,
    ~icon: React.element=?,
    ~iconMapping: 'any_r0b9=?,
    ~onClose: 'any_rh71=?,
    ~role: string=?,
    ~severity: string=?,
    ~variant: string=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~action: option(React.element)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~closeText: option(string)=?,
      ~color: option(color)=?,
      ~icon: option(React.element)=?,
      ~iconMapping: option(IconMapping.t)=?,
      ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
      ~role: option(string)=?,
      ~severity: option(severity)=?,
      ~variant: option(variant)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~action?,
    ~children?,
    ~className?,
    ~closeText?,
    ~color=?color->Belt.Option.map(v => colorToJs(v)),
    ~icon?,
    ~iconMapping=?IconMapping.unwrap(iconMapping),
    ~onClose?,
    ~role?,
    ~severity=?severity->Belt.Option.map(v => severityToJs(v)),
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"] external make: React.component('a) = "Alert";
