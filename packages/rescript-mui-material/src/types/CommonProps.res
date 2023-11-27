type t_NoId = {
  className?: string,
  style?: ReactDOM.Style.t,
  ref?: ReactDOM.domRef,
}

type classNameOnly = {className: string}

type t_NoRef = {
  className?: string,
  style?: ReactDOM.Style.t,
  id?: string,
}

type t = {
  ...t_NoId,
  id?: string,
}

type clickableProps = {
  ...t,
  onBlur?: ReactEvent.Focus.t => unit,
  onContextMenu?: ReactEvent.Mouse.t => unit,
  onDragLeave?: ReactEvent.Mouse.t => unit,
  onFocus?: ReactEvent.Focus.t => unit,
  onKeyDown?: ReactEvent.Keyboard.t => unit,
  onKeyPress?: ReactEvent.Keyboard.t => unit,
  onKeyUp?: ReactEvent.Keyboard.t => unit,
  onMouseDown?: ReactEvent.Mouse.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  onMouseUp?: ReactEvent.Mouse.t => unit,
  onTouchEnd?: ReactEvent.Touch.t => unit,
  onTouchMove?: ReactEvent.Touch.t => unit,
  onTouchStart?: ReactEvent.Touch.t => unit,
}

type clickablePropsWithOnClick = {
  ...clickableProps,
  onClick?: ReactEvent.Mouse.t => unit,
  onDoubleClick?: ReactEvent.Mouse.t => unit,
}
