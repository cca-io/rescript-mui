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
      obj |. enter |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
    ) {
    | Some(v) =>
      unwrappedMap |. Js.Dict.set("enter", v |. MaterialUi_Helpers.toJsUnsafe)
    | None => ()
    };
    switch (
      obj |. exit |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
    ) {
    | Some(v) =>
      unwrappedMap |. Js.Dict.set("exit", v |. MaterialUi_Helpers.toJsUnsafe)
    | None => ()
    };
    unwrappedMap;
  };
};

[@bs.obj]
external makeProps :
  (
    ~_in: bool=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rp5n=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Fade/Fade"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~in_: option(bool)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option([ | `Int(int) | `Float(float) | `Object(Timeout_shape.t)])=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_in=?in_,
        ~onEnter?,
        ~onExit?,
        ~theme?,
        ~timeout=?
          timeout |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        (),
      ),
    children,
  );
