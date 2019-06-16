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
    ~actions: 'any_r6wc=?,
    ~children: 'children=?,
    ~defaultValue: 'any_rx1g=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_roo6=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: string=?,
    ~className: string=?,
    ~row: bool=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "RadioGroup";

[@react.component]
let make =
    (
      ~actions: option(Actions.t)=?,
      ~children: option('children)=?,
      ~defaultValue: option('any_rx1g)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option((ReactEvent.Form.t, string) => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~value: option(string)=?,
      ~className: option(string)=?,
      ~row: option(bool)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~actions=?Actions.unwrap(actions),
      ~children?,
      ~defaultValue?,
      ~name?,
      ~onBlur?,
      ~onChange?,
      ~onKeyDown?,
      ~value?,
      ~className?,
      ~row?,
      (),
    ),
  );
