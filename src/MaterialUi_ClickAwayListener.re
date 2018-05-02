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
external makeProps :
  (
    ~mouseEvent: string=?,
    ~onClickAway: ReactEventRe.Mouse.t => unit,
    ~touchEvent: string=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/utils/ClickAwayListener"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~mouseEvent: option(mouseEvent)=?,
      ~onClickAway: ReactEventRe.Mouse.t => unit,
      ~touchEvent: option(touchEvent)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~mouseEvent=?Js.Option.map((. v) => mouseEventToJs(v), mouseEvent),
        ~onClickAway,
        ~touchEvent=?Js.Option.map((. v) => touchEventToJs(v), touchEvent),
        (),
      ),
    children,
  );
