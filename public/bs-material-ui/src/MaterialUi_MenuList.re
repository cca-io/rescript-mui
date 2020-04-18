[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "menu"] `Menu
  | [@bs.as "selectedMenu"] `SelectedMenu
];
[@bs.obj]
external makePropsMui:
  (
    ~component: 'union_rtfo=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: React.element=?,
    ~id: string=?,
    ~autoFocus: bool=?,
    ~autoFocusItem: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~disabledItemsFocusable: bool=?,
    ~disableListWrap: bool=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~variant: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
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
      ~id: option(string)=?,
      ~autoFocus: option(bool)=?,
      ~autoFocusItem: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disabledItemsFocusable: option(bool)=?,
      ~disableListWrap: option(bool)=?,
      ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
      ~variant: option(variant)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~dense?,
    ~disablePadding?,
    ~subheader?,
    ~id?,
    ~autoFocus?,
    ~autoFocusItem?,
    ~children?,
    ~className?,
    ~disabledItemsFocusable?,
    ~disableListWrap?,
    ~onKeyDown?,
    ~variant=?variant->Belt.Option.map(v => variantToJs(v)),
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "MenuList";
