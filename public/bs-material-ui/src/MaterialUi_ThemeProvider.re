[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~disableStylesGeneration: bool=?,
    ~sheetsCache: Js.t({..})=?,
    ~sheetsManager: Js.t({..})=?,
    ~theme: MaterialUi_Theme.t,
    unit
  ) =>
  _;

[@bs.module "@material-ui/core/styles"]
external reactComponent: React.component('a) = "MuiThemeProvider";

[@react.component]
let make = (~children: option('children)=?, ~theme: MaterialUi_Theme.t) =>
  React.createElement(reactComponent, makePropsMui(~children?, ~theme, ()));
