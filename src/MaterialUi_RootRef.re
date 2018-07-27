[@bs.obj] external makeProps : (~rootRef: 'union_rzyx, unit) => _ = "";

[@bs.module "@material-ui/core/RootRef/RootRef"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~rootRef: [
         | `Callback('genericCallback)
         | `ObjectGeneric(Js.t({..}))
       ],
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~rootRef=MaterialUi_Helpers.unwrapValue(rootRef), ()),
    children,
  );
