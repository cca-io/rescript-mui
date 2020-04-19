[@bs.deriving jsConverter]
type direction = [
  | [@bs.as "down"] `Down
  | [@bs.as "left"] `Left
  | [@bs.as "right"] `Right
  | [@bs.as "up"] `Up
];

module Timeout_shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    appear: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    enter: [ | `Int(int) | `Float(float)],
    [@bs.optional]
    exit: [ | `Int(int) | `Float(float)],
  };
  let make = t;

  let unwrap = (obj: t) => {
    let unwrappedMap = Js.Dict.empty();

    switch (
      obj
      ->appearGet
      ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)))
    ) {
    | Some(v) =>
      unwrappedMap->(Js.Dict.set("appear", v->MaterialUi_Helpers.toJsUnsafe))
    | None => ()
    };

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

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~direction: string=?,
    ~_in: bool=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~timeout: 'union_ra9k=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~direction: option(direction)=?,
      ~in_: option(bool)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
      ~timeout:
         option([ | `Int(int) | `Float(float) | `Object(Timeout_shape.t)])=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~direction=?direction->Belt.Option.map(v => directionToJs(v)),
    ~_in=?in_,
    ~onEnter?,
    ~onEntering?,
    ~onExit?,
    ~onExited?,
    ~timeout=?
      timeout->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~id?,
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"] external make: React.component('a) = "Slide";
