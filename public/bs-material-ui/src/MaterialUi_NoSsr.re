[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~defer: bool=?,
    ~fallback: React.element=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
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
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(~children?, ~defer?, ~fallback?, ~key?, ~ref?, ());

[@bs.module "@material-ui/core"] external make: React.component('a) = "NoSsr";
