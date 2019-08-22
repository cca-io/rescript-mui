[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~rootRef: 'union_r0jw,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
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
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
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
