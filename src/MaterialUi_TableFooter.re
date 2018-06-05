[@bs.obj]
external makeProps :
  (~className: string=?, ~component: 'union_r7ge=?, unit) => _ =
  "";
[@bs.module "@material-ui/core/TableFooter/TableFooter"]
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
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        (),
      ),
    children,
  );
