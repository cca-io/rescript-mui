module MouseEvent: {
  type t;
  let onClick: t;
  let onMouseDown: t;
  let onMouseUp: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let onClick = Any("onClick");
  let onMouseDown = Any("onMouseDown");
  let onMouseUp = Any("onMouseUp");
  let _false = Any(false);
};

module TouchEvent: {
  type t;
  let onTouchEnd: t;
  let onTouchStart: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let onTouchEnd = Any("onTouchEnd");
  let onTouchStart = Any("onTouchStart");
  let _false = Any(false);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: 'children=?,
    ~disableReactTree: bool=?,
    ~mouseEvent: MouseEvent.t=?,
    ~onClickAway: ReactEvent.Mouse.t => unit,
    ~touchEvent: TouchEvent.t=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ClickAwayListener";
