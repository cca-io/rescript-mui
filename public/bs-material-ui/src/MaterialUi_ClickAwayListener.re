[@bs.deriving jsConverter]
type mouseEvent = [
  | [@bs.as "onClick"] `OnClick
  | [@bs.as "onMouseDown"] `OnMouseDown
  | [@bs.as "onMouseUp"] `OnMouseUp
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type touchEvent = [
  | [@bs.as "onTouchStart"] `OnTouchStart
  | [@bs.as "onTouchEnd"] `OnTouchEnd
  | [@bs.as "false"] `False
];
[@bs.obj]
external makePropsMui:
  (
    ~children: 'children=?,
    ~mouseEvent: string=?,
    ~onClickAway: ReactEvent.Mouse.t => unit,
    ~touchEvent: string=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~mouseEvent: option(mouseEvent)=?,
      ~onClickAway: ReactEvent.Mouse.t => unit,
      ~touchEvent: option(touchEvent)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~mouseEvent=?mouseEvent->(Belt.Option.map(v => mouseEventToJs(v))),
    ~onClickAway,
    ~touchEvent=?touchEvent->(Belt.Option.map(v => touchEventToJs(v))),
    ~key?,
    ~_ref=?ref_,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ClickAwayListener";
