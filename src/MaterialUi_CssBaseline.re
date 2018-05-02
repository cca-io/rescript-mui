[@bs.obj] external makeProps : unit => _ = "";

[@bs.module "material-ui/CssBaseline/CssBaseline"]
external reactClass : ReasonReact.reactClass = "default";

let make = children =>
  ReasonReact.wrapJsForReason(~reactClass, ~props=makeProps(), children);
