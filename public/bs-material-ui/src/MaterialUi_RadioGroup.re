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
    ~actions: 'any_rqtj=?,
    ~children: 'children=?,
    ~defaultValue: 'any_rzov=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_rgqi=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: 'any_r4lb=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    ~className: string=?,
    ~row: bool=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~actions: option(Actions.t)=?,
      ~children: option('children)=?,
      ~defaultValue: option('any_rzov)=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~value: option('any_r4lb)=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~className: option(string)=?,
      ~row: option(bool)=?,
      (),
    ) =>
  makePropsMui(
    ~actions=?Actions.unwrap(actions),
    ~children?,
    ~defaultValue?,
    ~name?,
    ~onBlur?,
    ~onChange?,
    ~onKeyDown?,
    ~value?,
    ~key?,
    ~_ref=?ref_,
    ~className?,
    ~row?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RadioGroup";
