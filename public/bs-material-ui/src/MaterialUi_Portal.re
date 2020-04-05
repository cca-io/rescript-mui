[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~container: 'union_rt8j=?,
    ~disablePortal: bool=?,
    ~onRendered: ReactEvent.Synthetic.t => unit=?,
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
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Portal";
