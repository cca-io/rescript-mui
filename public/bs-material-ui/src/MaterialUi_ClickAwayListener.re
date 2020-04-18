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
  type t = [ | `OnTouchStart | `OnTouchEnd | `False];
  let tToJs =
    fun
    | `OnTouchStart => "onTouchStart"->Obj.magic
    | `OnTouchEnd => "onTouchEnd"->Obj.magic
    | `False => false->Obj.magic;
};

[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~mouseEvent: 'any_ru5l=?,
    ~onClickAway: ReactEvent.Mouse.t => unit,
    ~touchEvent: 'any_r24b=?,
    ~id: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~children: option('children)=?,
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
