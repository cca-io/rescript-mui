[@bs.obj] external makeProps : (~component: 'union_rbr9=?, unit) => _ = "";

[@bs.module "material-ui/Table/TableFooter"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        (),
      ),
    children,
  );
