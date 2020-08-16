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
    "root": option(string),
    "expanded": option(string),
    "focused": option(string),
    "disabled": option(string),
    "content": option(string),
    "expandIcon": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~expanded: string=?,
      ~focused: string=?,
      ~disabled: string=?,
      ~content: string=?,
      ~expandIcon: string=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: bool=?,
    ~component: Component.t=?,
    ~disabled: bool=?,
    ~disableRipple: bool=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~href: string=?,
    ~onDragLeave: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onMouseUp: ReactEvent.Mouse.t => unit=?,
    ~onTouchEnd: ReactEvent.Touch.t => unit=?,
    ~onTouchMove: ReactEvent.Touch.t => unit=?,
    ~onTouchStart: ReactEvent.Touch.t => unit=?,
    ~tabIndex: TabIndex.t=?,
    ~_TouchRippleProps: Js.t({..})=?,
    ~_type: Type.t=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~expandIcon: React.element=?,
    ~_IconButtonProps: Js.t({..})=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocusVisible: MaterialUi_Types.any=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "AccordionSummary";
