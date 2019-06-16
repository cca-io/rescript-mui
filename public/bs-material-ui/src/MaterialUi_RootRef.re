[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~rootRef: 'union_re07,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~rootRef: [
         | `Callback('genericCallback)
         | `ObjectGeneric(Js.t({..}))
       ],
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~rootRef=MaterialUi_Helpers.unwrapValue(rootRef),
    ~key?,
    ~_ref=?ref_,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RootRef";
