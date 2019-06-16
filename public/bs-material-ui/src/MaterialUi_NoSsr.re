[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~defer: bool=?,
    ~fallback: React.element=?,
    ~key: string=?,
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
      (),
    ) =>
  makePropsMui(~children?, ~defer?, ~fallback?, ~key?, ());

[@bs.module "@material-ui/core"] external make: React.component('a) = "NoSsr";
