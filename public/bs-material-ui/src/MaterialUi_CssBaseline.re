[@bs.obj] external makePropsMui: (~children: 'children=?, unit) => _ = "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "CssBaseline";

[@react.component]
let make = (~children: option('children)=?) =>
  React.createElement(reactComponent, makePropsMui(~children?, ()));
