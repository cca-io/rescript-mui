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

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "menu"] `Menu
  | [@bs.as "selectedMenu"] `SelectedMenu
];
[@bs.obj]
external makePropsMui:
  (
    ~actions: 'any_rzmz=?,
    ~autoFocus: bool=?,
    ~autoFocusItem: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disableListWrap: bool=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~variant: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~component: 'union_rvvo=?,
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
      ~autoFocusItem: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableListWrap: option(bool)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
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
    ~autoFocusItem?,
    ~children?,
    ~className?,
    ~disableListWrap?,
    ~onKeyDown?,
    ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
    ~key?,
    ~ref?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~dense?,
    ~disablePadding?,
    ~subheader?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "MenuList";
