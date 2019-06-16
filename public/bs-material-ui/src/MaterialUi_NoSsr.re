[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~defer: bool=?,
    ~fallback: React.element=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~defer: option(bool)=?,
      ~fallback: option(React.element)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      (),
    ) =>
  makePropsMui(~children?, ~defer?, ~fallback?, ~key?, ~_ref=?ref_, ());

[@bs.module "@material-ui/core"] external make: React.component('a) = "NoSsr";
