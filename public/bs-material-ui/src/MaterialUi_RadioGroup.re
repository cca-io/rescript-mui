[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~defaultValue: 'union_r9la=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: 'any_r4w5=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: 'union_re1h=?,
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
      ~children: option('children)=?,
      ~defaultValue:
         option(
           [ | `String(string) | `Int(int) | `Float(float) | `Bool(bool)],
         )=?,
      ~name: option(string)=?,
      ~onBlur: option(ReactEvent.Focus.t => unit)=?,
      ~onChange: option((ReactEvent.Form.t, string) => unit)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~value:
         option(
           [ | `String(string) | `Int(int) | `Float(float) | `Bool(bool)],
         )=?,
      ~className: option(string)=?,
      ~row: option(bool)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~children?,
      ~defaultValue=?
        defaultValue->(
                        Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                      ),
      ~name?,
      ~onBlur?,
      ~onChange?,
      ~onKeyDown?,
      ~value=?
        value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~className?,
      ~row?,
      (),
    ),
  );
