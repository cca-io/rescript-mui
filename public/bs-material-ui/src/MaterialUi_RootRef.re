[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(~children?, ~id?, ~key?, ~ref?, ());

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RootRef";
