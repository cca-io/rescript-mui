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
    ~actions: 'any_ru28=?,
    ~autoFocus: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disableListWrap: bool=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: React.element=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "MenuList";

[@react.component]
let make =
    (
      ~actions: option(Actions.t)=?,
      ~autoFocus: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableListWrap: option(bool)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~dense: option(bool)=?,
      ~disablePadding: option(bool)=?,
      ~subheader: option(React.element)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~actions=?Actions.unwrap(actions),
      ~autoFocus?,
      ~children?,
      ~className?,
      ~disableListWrap?,
      ~onKeyDown?,
      ~dense?,
      ~disablePadding?,
      ~subheader?,
      (),
    ),
  );
