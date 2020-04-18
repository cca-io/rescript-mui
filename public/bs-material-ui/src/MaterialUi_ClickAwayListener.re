[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~mouseEvent: option(
                   [@bs.string] [
                     | [@bs.as "onClick"] `OnClick
                     | [@bs.as "onMouseDown"] `OnMouseDown
                     | [@bs.as "onMouseUp"] `OnMouseUp
                     | [@bs.as "false"] `False
                   ],
                 )
                   =?,
    ~onClickAway: ReactEvent.Mouse.t => unit,
    ~touchEvent: option(
                   [@bs.string] [
                     | [@bs.as "onTouchStart"] `OnTouchStart
                     | [@bs.as "onTouchEnd"] `OnTouchEnd
                     | [@bs.as "false"] `False
                   ],
                 )
                   =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ClickAwayListener";
