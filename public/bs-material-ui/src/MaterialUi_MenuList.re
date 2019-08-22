module Actions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    current: Js.Json.t,
  };
  let make = t;

  let unwrap = (obj: option(t)) => {
    switch (obj) {
    | Some(obj) =>
      let unwrappedMap = Js.Dict.empty();

      switch (obj->currentGet) {
      | Some(v) =>
        unwrappedMap->(
                        Js.Dict.set(
                          "current",
                          v->MaterialUi_Helpers.toJsUnsafe,
                        )
                      )
      | None => ()
      };

      Some(unwrappedMap);
    | None => None
    };
  };
};

[@bs.obj]
external makePropsMui:
  (
    ~actions: 'any_rjd3=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disableListWrap: bool=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    ~component: 'union_rst9=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: React.element=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~actions: option(Actions.t)=?,
      ~autoFocus: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableListWrap: option(bool)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(ReasonReact.reactElement)
           ],
         )=?,
      ~dense: option(bool)=?,
      ~disablePadding: option(bool)=?,
      ~subheader: option(React.element)=?,
      (),
    ) =>
  makePropsMui(
    ~actions=?Actions.unwrap(actions),
    ~autoFocus?,
    ~children?,
    ~className?,
    ~disableListWrap?,
    ~onKeyDown?,
    ~key?,
    ~_ref=?ref_,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~dense?,
    ~disablePadding?,
    ~subheader?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "MenuList";
