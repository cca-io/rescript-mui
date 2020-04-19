module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module TabIndex: {
  type t;
  let int: int => t;
  let float: float => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let string = (v: string) => Any(v);
};

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    edgeStart: string,
    [@bs.optional]
    edgeEnd: string,
    [@bs.optional]
    switchBase: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    checked: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    input: string,
    [@bs.optional]
    thumb: string,
    [@bs.optional]
    track: string,
  };
  let make = t;
};

module Edge: {
  type t;
  let _end: t;
  let start: t;
  let _false: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _end = Any("end");
  let start = Any("start");
  let _false = Any(false);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: option(bool)=?,
    ~component: option(Component.t)=?,
    ~disableTouchRipple: option(bool)=?,
    ~focusRipple: option(bool)=?,
    ~focusVisibleClassName: option(string)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onDragLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~onFocusVisible: option(MaterialUi_Types.any)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
    ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
    ~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
    ~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
    ~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
    ~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
    ~role: option(string)=?,
    ~tabIndex: option(TabIndex.t)=?,
    ~_TouchRippleProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_type: option(
              [@bs.string] [
                | [@bs.as "submit"] `Submit
                | [@bs.as "reset"] `Reset
                | [@bs.as "button"] `Button
              ],
            )
              =?,
    ~children: option('children)=?,
    ~disableFocusRipple: option(bool)=?,
    ~checked: option(bool)=?,
    ~checkedIcon: option(React.element)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~defaultChecked: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~edge: option(Edge.t)=?,
    ~icon: option(React.element)=?,
    ~id: option(string)=?,
    ~inputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~required: option(bool)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Switch";
