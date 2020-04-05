[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~container: 'union_r3qi=?,
    ~disablePortal: bool=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~container: option([ | `Callback('genericCallback)])=?,
      ~disablePortal: option(bool)=?,
      ~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~container=?
      container->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disablePortal?,
    ~onRendered?,
    ~id?,
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Portal";
