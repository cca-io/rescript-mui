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

module Type_enum: {
  type t;
  let button: t;
  let reset: t;
  let submit: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let button = Any("button");
  let reset = Any("reset");
  let submit = Any("submit");
};

module Type: {
  type t;
  let enum: Type_enum.t => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: Type_enum.t) => Any(v);
  let string = (v: string) => Any(v);
};

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "label": option(option(string)),
    "primary": option(option(string)),
    "secondary": option(option(string)),
    "extended": option(option(string)),
    "focusVisible": option(option(string)),
    "disabled": option(option(string)),
    "colorInherit": option(option(string)),
    "sizeSmall": option(option(string)),
    "sizeMedium": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~label: string=?,
      ~primary: string=?,
      ~secondary: string=?,
      ~extended: string=?,
      ~focusVisible: string=?,
      ~disabled: string=?,
      ~colorInherit: string=?,
      ~sizeSmall: string=?,
      ~sizeMedium: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Inherit | `Primary | `Secondary];

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

type size = [ | `Large | `Medium | `Small];

type variant = [ | `Extended | `Round];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: option(bool)=?,
    ~disableTouchRipple: option(bool)=?,
    ~focusRipple: option(bool)=?,
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
    ~tabIndex: option(TabIndex.t)=?,
    ~_TouchRippleProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~_type: option(Type.t)=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~disabled: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~focusVisibleClassName: option(string)=?,
    ~href: option(string)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "large"] `Large
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "extended"] `Extended
                  | [@bs.as "round"] `Round
                ],
              )
                =?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Fab";
