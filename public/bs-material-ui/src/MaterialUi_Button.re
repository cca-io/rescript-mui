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
    label: string,
    [@bs.optional]
    text: string,
    [@bs.optional]
    textPrimary: string,
    [@bs.optional]
    textSecondary: string,
    [@bs.optional]
    outlined: string,
    [@bs.optional]
    outlinedPrimary: string,
    [@bs.optional]
    outlinedSecondary: string,
    [@bs.optional]
    contained: string,
    [@bs.optional]
    containedPrimary: string,
    [@bs.optional]
    containedSecondary: string,
    [@bs.optional]
    disableElevation: string,
    [@bs.optional]
    focusVisible: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    colorInherit: string,
    [@bs.optional]
    textSizeSmall: string,
    [@bs.optional]
    textSizeLarge: string,
    [@bs.optional]
    outlinedSizeSmall: string,
    [@bs.optional]
    outlinedSizeLarge: string,
    [@bs.optional]
    containedSizeSmall: string,
    [@bs.optional]
    containedSizeLarge: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    sizeLarge: string,
    [@bs.optional]
    fullWidth: string,
    [@bs.optional]
    startIcon: string,
    [@bs.optional]
    endIcon: string,
    [@bs.optional]
    iconSizeSmall: string,
    [@bs.optional]
    iconSizeMedium: string,
    [@bs.optional]
    iconSizeLarge: string,
  };
  let make = t;
};

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
    ~role: option(string)=?,
    ~tabIndex: option(TabIndex.t)=?,
    ~_TouchRippleProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
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
    ~disableElevation: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~endIcon: option(React.element)=?,
    ~focusVisibleClassName: option(string)=?,
    ~fullWidth: option(bool)=?,
    ~href: option(string)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "small"] `Small
               | [@bs.as "medium"] `Medium
               | [@bs.as "large"] `Large
             ],
           )
             =?,
    ~startIcon: option(React.element)=?,
    ~_type: option(string)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "text"] `Text
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "contained"] `Contained
                ],
              )
                =?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Button";
