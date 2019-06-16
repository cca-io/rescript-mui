[@bs.obj]
external makePropsMui:
  (~children: 'children=?, ~rootRef: 'union_rri4, ~key: string=?, unit) => _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~rootRef: [
         | `Callback('genericCallback)
         | `ObjectGeneric(Js.t({..}))
       ],
      ~key: option(string)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~rootRef=MaterialUi_Helpers.unwrapValue(rootRef),
    ~key?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RootRef";
