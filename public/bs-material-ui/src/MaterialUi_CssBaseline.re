[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      (),
    ) =>
  makePropsMui(~children?, ~key?, ~_ref=?ref_, ());

[@bs.module "@material-ui/core"]
external make: React.component('a) = "CssBaseline";
