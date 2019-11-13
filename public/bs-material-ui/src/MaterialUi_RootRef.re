[@bs.obj]
external makePropsMui:
  (~children: 'children=?, ~key: string=?, ~ref: ReactDOMRe.domRef=?, unit) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(~children?, ~key?, ~ref?, ());

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RootRef";
