[@bs.deriving jsConverter]
type direction = [
  | [@bs.as "left"] `Left
  | [@bs.as "right"] `Right
  | [@bs.as "up"] `Up
  | [@bs.as "down"] `Down
];

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

[@bs.obj]
external makeProps:
  (
    ~direction: string=?,
    ~_in: bool=?,
    ~onEnter: ReactEvent.Synthetic.t => unit=?,
    ~onEntering: ReactEvent.Synthetic.t => unit=?,
    ~onExit: ReactEvent.Synthetic.t => unit=?,
    ~onExited: ReactEvent.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rwfh=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Slide";
let make =
    (
      ~direction: option(direction)=?,
      ~in_: option(bool)=?,
      ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
      ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option([ | `Int(int) | `Float(float) | `Object(Timeout_shape.t)])=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~direction=?direction->(Belt.Option.map(v => directionToJs(v))),
        ~_in=?in_,
        ~onEnter?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~theme?,
        ~timeout=?
          timeout->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        (),
      ),
    children,
  );
