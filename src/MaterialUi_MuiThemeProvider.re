[@bs.obj]
external makeProps:
  (
    ~disableStylesGeneration: bool=?,
    ~sheetsManager: Js.t({..})=?,
    ~theme: 'union_r6mo,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "MuiThemeProvider";
let make =
    (
      ~disableStylesGeneration: option(bool)=?,
      ~sheetsManager: option(Js.t({..}))=?,
      ~theme: [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~disableStylesGeneration?,
        ~sheetsManager?,
        ~theme=MaterialUi_Helpers.unwrapValue(theme),
        (),
      ),
    children,
  );
