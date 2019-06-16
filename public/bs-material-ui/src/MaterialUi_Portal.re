[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~container: 'union_ru5r=?,
    ~disablePortal: bool=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Portal";

[@react.component]
let make =
    (
      ~children: option('children)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~disablePortal: option(bool)=?,
      ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~container=?
        container->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~disablePortal?,
      ~onRendered?,
      (),
    ),
  );
