[@bs.obj]
external makeProps:
  (~defer: bool=?, ~fallback: ReasonReact.reactElement=?, unit) => _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "NoSsr";
let make =
    (
      ~defer: option(bool)=?,
      ~fallback: option(ReasonReact.reactElement)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=makeProps(~defer?, ~fallback?, ()),
    children,
  );
