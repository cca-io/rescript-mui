[@bs.obj]
external makePropsMui:
  (~children: 'children=?, ~key: string=?, ~_ref: ReactDOMRe.domRef=?, unit) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(~children?, ~key?, ~_ref=?ref_, ());

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RootRef";
