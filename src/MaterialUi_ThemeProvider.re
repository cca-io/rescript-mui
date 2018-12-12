[@bs.obj] external makeProps: (~theme: MaterialUi_Theme.t, unit) => _ = "";
[@bs.module "@material-ui/styles"]
external reactClass: ReasonReact.reactClass = "ThemeProvider";
let make = (~theme: MaterialUi_Theme.t, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~theme, ()),
    children,
  );
