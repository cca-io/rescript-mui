[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~defer: bool=?,
    ~fallback: React.element=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~defer: option(bool)=?,
      ~fallback: option(React.element)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(~children?, ~defer?, ~fallback?, ~id?, ~key?, ~ref?, ());

[@bs.module "@material-ui/core"] external make: React.component('a) = "NoSsr";
