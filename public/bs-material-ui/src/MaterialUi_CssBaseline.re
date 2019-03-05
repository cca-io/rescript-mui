[@bs.obj] external makeProps: unit => _ = "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "CssBaseline";
let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
