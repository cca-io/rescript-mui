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
    "labelIcon": option(string),
    "textColorInherit": option(string),
    "textColorPrimary": option(string),
    "textColorSecondary": option(string),
    "selected": option(string),
    "disabled": option(string),
    "fullWidth": option(string),
    "wrapped": option(string),
    "wrapper": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~labelIcon: string=?,
      ~textColorInherit: string=?,
      ~textColorPrimary: string=?,
      ~textColorSecondary: string=?,
      ~selected: string=?,
      ~disabled: string=?,
      ~fullWidth: string=?,
      ~wrapped: string=?,
      ~wrapper: string=?,
      unit
    ) =>
    t;
};

type textColor = [ | `Secondary | `Primary | `Inherit];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: bool=?,
    ~component: Component.t=?,
    ~disableTouchRipple: bool=?,
    ~focusRipple: bool=?,
    ~focusVisibleClassName: string=?,
    ~href: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onDragLeave: ReactEvent.Mouse.t => unit=?,
    ~onFocusVisible: MaterialUi_Types.any=?,
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
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~fullWidth: bool=?,
    ~icon: React.element=?,
    ~indicator: React.element=?,
    ~label: React.element=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~selected: bool=?,
    ~selectionFollowsFocus: bool=?,
    ~textColor: [@bs.string] [
                  | [@bs.as "secondary"] `Secondary
                  | [@bs.as "primary"] `Primary
                  | [@bs.as "inherit"] `Inherit
                ]
                  =?,
    ~value: MaterialUi_Types.any=?,
    ~wrapped: bool=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Tab";
