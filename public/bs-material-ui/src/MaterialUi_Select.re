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
    "root": option(string),
    "select": option(string),
    "filled": option(string),
    "outlined": option(string),
    "selectMenu": option(string),
    "disabled": option(string),
    "icon": option(string),
    "iconOpen": option(string),
    "iconFilled": option(string),
    "iconOutlined": option(string),
    "nativeInput": option(string),
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

module Value: {
  type t;
  let string: string => t;
  let int: int => t;
  let float: float => t;
  let arrayOf: array(string) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let arrayOf = (v: array(string)) => Any(v);
};

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~aria_describedby: string=?,
    ~className: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~renderSuffix: MaterialUi_Types.any=?,
    ~rowsMin: RowsMin.t=?,
    ~style: ReactDOM.Style.t=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~inputComponent: InputComponent.t=?,
    ~margin: [@bs.string] [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None]
               =?,
    ~multiline: bool=?,
    ~name: string=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: Rows.t=?,
    ~rowsMax: RowsMax.t=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~autoWidth: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~defaultValue: MaterialUi_Types.any=?,
    ~displayEmpty: bool=?,
    ~_IconComponent: IconComponent.t=?,
    ~id: string=?,
    ~input: React.element=?,
    ~inputProps: Js.t({..})=?,
    ~label: React.element=?,
    ~labelId: string=?,
    ~labelWidth: MaterialUi_Types.Number.t=?,
    ~_MenuProps: Js.t({..})=?,
    ~multiple: bool=?,
    ~native: bool=?,
    ~onChange: (ReactEvent.Form.t, Js.t({..})) => unit=?,
    ~onClose: ReactEvent.Synthetic.t => unit=?,
    ~onOpen: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool=?,
    ~renderValue: MaterialUi_Types.any => React.element=?,
    ~_SelectDisplayProps: Js.t({..})=?,
    ~value: Value.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "filled"] `Filled
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Select";
