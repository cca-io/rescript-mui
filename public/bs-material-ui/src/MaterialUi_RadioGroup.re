[@bs.obj]
external makePropsMui:
  (
    ~className: string=?,
    ~row: bool=?,
    ~id: string=?,
    ~children: 'children=?,
    ~defaultValue: 'union_rj0x=?,
    ~name: string=?,
    ~onChange: 'any_r063=?,
    ~value: 'any_ruk9=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~className: option(string)=?,
      ~row: option(bool)=?,
      ~id: option(string)=?,
      ~children: option('children)=?,
      ~defaultValue:
         option(
           [
             | `Array(array(string))
             | `Int(int)
             | `Float(float)
             | `String(string)
           ],
         )=?,
      ~name: option(string)=?,
      ~onChange: option(ReactEvent.Form.t => unit)=?,
      ~value: option('any_ruk9)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~className?,
    ~row?,
    ~id?,
    ~children?,
    ~defaultValue=?
      defaultValue->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~name?,
    ~onChange?,
    ~value?,
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "RadioGroup";
