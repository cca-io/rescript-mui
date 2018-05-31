[@bs.obj]
external makeProps :
  (~className: string=?, ~component: 'union_rum5=?, unit) => _ =
  "";

[@bs.module "@material-ui/core/TableBody/TableBody"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        (),
      ),
    children,
  );
