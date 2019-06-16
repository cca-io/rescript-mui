[@bs.obj]
external makePropsMui:
  (~children: 'children=?, ~rootRef: 'union_r70u, unit) => _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "RootRef";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~rootRef: [
         | `Callback('genericCallback)
         | `ObjectGeneric(Js.t({..}))
       ],
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~rootRef=MaterialUi_Helpers.unwrapValue(rootRef),
      (),
    ),
  );
