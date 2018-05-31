[@bs.deriving jsConverter]
type direction = [
  | [@bs.as "left"] `Left
  | [@bs.as "right"] `Right
  | [@bs.as "up"] `Up
  | [@bs.as "down"] `Down
];

[@bs.deriving abstract]
type timeout_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
};

[@bs.obj]
external makeProps :
  (
    ~direction: string=?,
    ~in_: bool=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rmi2=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Slide/Slide"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~direction: option(direction)=?,
      ~in_: option(bool)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option([ | `Int(int) | `Float(float) | `Object(timeout_shape)])=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~direction=?Js.Option.map((. v) => directionToJs(v), direction),
        ~in_?,
        ~onEnter?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~theme?,
        ~timeout=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            timeout,
          ),
        (),
      ),
    children,
  );
