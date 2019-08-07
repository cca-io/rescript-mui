module Timeout_shape = {
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

[@bs.deriving jsConverter]
type timeout_enum = [ | [@bs.as "auto"] `Auto];

module Classes = {
  type classesType =
    | Container(string)
    | Entered(string)
    | Hidden(string)
    | Wrapper(string)
    | WrapperInner(string);
  type t = list(classesType);
  let to_string =
    fun
    | Container(_) => "container"
    | Entered(_) => "entered"
    | Hidden(_) => "hidden"
    | Wrapper(_) => "wrapper"
    | WrapperInner(_) => "wrapperInner";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Container(className)
                         | Entered(className)
                         | Hidden(className)
                         | Wrapper(className)
                         | WrapperInner(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~collapsedHeight: string=?,
    ~_in: bool=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntered: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExiting: ReactEvent.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rqdq=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~collapsedHeight: option(string)=?,
      ~in_: option(bool)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntered: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExiting: option(ReactEvent.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(Timeout_shape.t)
             | `Enum(timeout_enum)
           ],
         )=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~collapsedHeight?,
    ~_in=?in_,
    ~onEnter?,
    ~onEntered?,
    ~onEntering?,
    ~onExit?,
    ~onExiting?,
    ~theme?,
    ~timeout=?
      timeout->(
                 Belt.Option.map(v =>
                   switch (v) {
                   | `Enum(v) =>
                     MaterialUi_Helpers.unwrapValue(
                       `String(timeout_enumToJs(v)),
                     )

                   | v => MaterialUi_Helpers.unwrapValue(v)
                   }
                 )
               ),
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Collapse";
