[@bs.obj]
external makePropsMui:
  (~children: 'children=?, ~defer: bool=?, ~fallback: React.element=?, unit) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "NoSsr";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~defer: option(bool)=?,
      ~fallback: option(React.element)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(~children?, ~defer?, ~fallback?, ()),
  );
