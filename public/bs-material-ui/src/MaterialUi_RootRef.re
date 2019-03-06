[@bs.obj] external makeProps: (~rootRef: 'union_rvdc, unit) => _ = "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "RootRef";
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
