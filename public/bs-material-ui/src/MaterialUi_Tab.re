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
    labelIcon: string,
    [@bs.optional]
    textColorInherit: string,
    [@bs.optional]
    textColorPrimary: string,
    [@bs.optional]
    textColorSecondary: string,
    [@bs.optional]
    selected: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    fullWidth: string,
    [@bs.optional]
    wrapped: string,
    [@bs.optional]
    wrapper: string,
  };
  let make = t;
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
    ~id: option(string)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disabled: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~icon: option(React.element)=?,
    ~indicator: option(React.element)=?,
    ~label: option(React.element)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~selected: option(bool)=?,
    ~textColor: option(
                  [@bs.string] [
                    | [@bs.as "secondary"] `Secondary
                    | [@bs.as "primary"] `Primary
                    | [@bs.as "inherit"] `Inherit
                  ],
                )
                  =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~wrapped: option(bool)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Tab";
