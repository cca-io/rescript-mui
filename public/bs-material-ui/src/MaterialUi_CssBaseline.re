[@bs.obj]
external makePropsMui: (~children: 'children=?, ~key: string=?, unit) => _ =
  "";

let makeProps = (~children: option('children)=?, ~key: option(string)=?, ()) =>
  makePropsMui(~children?, ~key?, ());

[@bs.module "@material-ui/core"]
external make: React.component('a) = "CssBaseline";
