module MouseEvent: {
  type t
  let onClick: t
  let onMouseDown: t
  let onMouseUp: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let onClick = Any("onClick")
  let onMouseDown = Any("onMouseDown")
  let onMouseUp = Any("onMouseUp")
  let \"false" = Any(false)
}

module TouchEvent: {
  type t
  let onTouchEnd: t
  let onTouchStart: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let onTouchEnd = Any("onTouchEnd")
  let onTouchStart = Any("onTouchStart")
  let \"false" = Any(false)
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~disableReactTree: bool=?,
  ~mouseEvent: MouseEvent.t=?,
  ~onClickAway: ReactEvent.Mouse.t => unit,
  ~touchEvent: TouchEvent.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ClickAwayListener"
