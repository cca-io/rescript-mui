module MouseEvent = {
  type t = [ | `OnClick | `OnMouseDown | `OnMouseUp | `False];
  let tToJs =
    fun
    | `OnClick => "onClick"->Obj.magic
    | `OnMouseDown => "onMouseDown"->Obj.magic
    | `OnMouseUp => "onMouseUp"->Obj.magic
    | `False => false->Obj.magic;
};

module TouchEvent = {
  type t = [ | `OnTouchEnd | `OnTouchStart | `False];
  let tToJs =
    fun
    | `OnTouchEnd => "onTouchEnd"->Obj.magic
    | `OnTouchStart => "onTouchStart"->Obj.magic
    | `False => false->Obj.magic;
};

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~disableReactTree: bool=?,
    ~mouseEvent: 'any_rq5x=?,
    ~onClickAway: ReactEvent.Mouse.t => unit,
    ~touchEvent: 'any_rq7s=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
      ~disableReactTree: option(bool)=?,
      ~mouseEvent: option(MouseEvent.t)=?,
      ~onClickAway: ReactEvent.Mouse.t => unit,
      ~touchEvent: option(TouchEvent.t)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~disableReactTree?,
    ~mouseEvent=?mouseEvent->Belt.Option.map(v => MouseEvent.tToJs(v)),
    ~onClickAway,
    ~touchEvent=?touchEvent->Belt.Option.map(v => TouchEvent.tToJs(v)),
    ~id?,
    ~key?,
    ~ref?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ClickAwayListener";
