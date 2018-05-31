[@bs.deriving abstract]
type timeout_shape = {
  enter: [ | `Int(int) | `Float(float)],
  exit: [ | `Int(int) | `Float(float)],
};

[@bs.obj]
external makeProps :
  (
    ~in_: bool=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_r4yq=?,
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
         option([ | `Int(int) | `Float(float) | `Object(timeout_shape)])=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~in_?,
        ~onEnter?,
        ~onExit?,
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
