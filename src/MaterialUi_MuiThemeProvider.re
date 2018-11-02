[@bs.obj]
external makeProps:
  (
    ~disableStylesGeneration: bool=?,
    ~sheetsCache: Js.t({..})=?,
    ~sheetsManager: Js.t({..})=?,
    ~theme: 'union_r4j1,
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
      ~theme: [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~disableStylesGeneration?,
        ~sheetsCache?,
        ~sheetsManager?,
        ~theme=MaterialUi_Helpers.unwrapValue(theme),
        (),
      ),
    children,
  );
