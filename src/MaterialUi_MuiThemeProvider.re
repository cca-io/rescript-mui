[@bs.obj]
external makeProps :
  (
    ~disableStylesGeneration: bool=?,
    ~sheetsManager: Js.t({..})=?,
    ~theme: 'union_rn9t,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/styles/MuiThemeProvider"]
external reactClass : ReasonReact.reactClass = "default";

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
