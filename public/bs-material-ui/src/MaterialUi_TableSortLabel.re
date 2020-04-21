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

type _type = [ | `Submit | `Reset | `Button];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "active": option(option(string)),
    "icon": option(option(string)),
    "iconDirectionDesc": option(option(string)),
    "iconDirectionAsc": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~active: string=?,
      ~icon: string=?,
      ~iconDirectionDesc: string=?,
      ~iconDirectionAsc: string=?,
      unit
    ) =>
    t;
};

type direction = [ | `Asc | `Desc];

module IconComponent: {
  type t;
  let string: string => t;
  let iconComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let iconComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~centerRipple: option(bool)=?,
    ~component: option(Component.t)=?,
    ~disabled: option(bool)=?,
    ~disableRipple: option(bool)=?,
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
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~active: option(bool)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~direction: option(
                  [@bs.string] [
                    | [@bs.as "asc"] `Asc
                    | [@bs.as "desc"] `Desc
                  ],
                )
                  =?,
    ~hideSortIcon: option(bool)=?,
    ~_IconComponent: option(IconComponent.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "TableSortLabel";
