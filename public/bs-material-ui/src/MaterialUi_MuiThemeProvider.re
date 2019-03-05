[@bs.obj]
external makeProps:
  (
    ~disableStylesGeneration: bool=?,
    ~sheetsCache: Js.t({..})=?,
    ~sheetsManager: Js.t({..})=?,
    ~theme: MaterialUi_Theme.t,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "MuiThemeProvider";
let make =
    (
      ~disableStylesGeneration: option(bool)=?,
      ~sheetsCache: option(Js.t({..}))=?,
      ~sheetsManager: option(Js.t({..}))=?,
      ~theme: MaterialUi_Theme.t,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~disableStylesGeneration?,
        ~sheetsCache?,
        ~sheetsManager?,
        ~theme,
        (),
      ),
    children,
  );
