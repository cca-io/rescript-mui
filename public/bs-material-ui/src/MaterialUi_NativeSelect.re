module RowsMin: {
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

type color = [ | `Primary | `Secondary];

module InputComponent: {
  type t;
  let string: string => t;
  let inputComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let inputComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

type margin = [ | `Dense | `None];

module Rows: {
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

module RowsMax: {
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
  type t = {
    .
    "root": option(option(string)),
    "select": option(option(string)),
    "filled": option(option(string)),
    "outlined": option(option(string)),
    "selectMenu": option(option(string)),
    "disabled": option(option(string)),
    "icon": option(option(string)),
    "iconOpen": option(option(string)),
    "iconFilled": option(option(string)),
    "iconOutlined": option(option(string)),
    "nativeInput": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~select: string=?,
      ~filled: string=?,
      ~outlined: string=?,
      ~selectMenu: string=?,
      ~disabled: string=?,
      ~icon: string=?,
      ~iconOpen: string=?,
      ~iconFilled: string=?,
      ~iconOutlined: string=?,
      ~nativeInput: string=?,
      unit
    ) =>
    t;
};

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

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~aria_describedby: option(string)=?,
    ~className: option(string)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
    ~renderSuffix: option(MaterialUi_Types.any)=?,
    ~rowsMin: option(RowsMin.t)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~autoComplete: option(string)=?,
    ~autoFocus: option(bool)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~defaultValue: option(MaterialUi_Types.any)=?,
    ~disabled: option(bool)=?,
    ~disableUnderline: option(bool)=?,
    ~endAdornment: option(React.element)=?,
    ~error: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~id: option(string)=?,
    ~inputComponent: option(InputComponent.t)=?,
    ~margin: option(
               [@bs.string] [
                 | [@bs.as "dense"] `Dense
                 | [@bs.as "none"] `None
               ],
             )
               =?,
    ~multiline: option(bool)=?,
    ~name: option(string)=?,
    ~placeholder: option(string)=?,
    ~readOnly: option(bool)=?,
    ~required: option(bool)=?,
    ~rows: option(Rows.t)=?,
    ~rowsMax: option(RowsMax.t)=?,
    ~startAdornment: option(React.element)=?,
    ~_type: option(string)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~_IconComponent: option(IconComponent.t)=?,
    ~input: option(React.element)=?,
    ~inputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~value: option(MaterialUi_Types.any)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "filled"] `Filled
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "standard"] `Standard
                ],
              )
                =?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "NativeSelect";
