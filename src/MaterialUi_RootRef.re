[@bs.obj] external makeProps : (~rootRef: 'genericCallback, unit) => _ = "";

[@bs.module "@material-ui/core/RootRef/RootRef"]
external reactClass : ReasonReact.reactClass = "default";

let make = (~rootRef: 'genericCallback, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~rootRef, ()),
    children,
  );
