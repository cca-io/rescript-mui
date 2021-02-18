module Classes = {
  type t = {
    .
    "_global": option(string),
    "root": option(string),
    "formControl": option(string),
    "focused": option(string),
    "disabled": option(string),
    "adornedStart": option(string),
    "adornedEnd": option(string),
    "error": option(string),
    "marginDense": option(string),
    "multiline": option(string),
    "colorSecondary": option(string),
    "fullWidth": option(string),
    "input": option(string),
    "inputMarginDense": option(string),
    "inputMultiline": option(string),
    "inputTypeSearch": option(string),
    "inputAdornedStart": option(string),
    "inputAdornedEnd": option(string),
    "inputHiddenLabel": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~__global: string=?,
      ~root: string=?,
      ~formControl: string=?,
      ~focused: string=?,
      ~disabled: string=?,
      ~adornedStart: string=?,
      ~adornedEnd: string=?,
      ~error: string=?,
      ~marginDense: string=?,
      ~multiline: string=?,
      ~colorSecondary: string=?,
      ~fullWidth: string=?,
      ~input: string=?,
      ~inputMarginDense: string=?,
      ~inputMultiline: string=?,
      ~inputTypeSearch: string=?,
      ~inputAdornedStart: string=?,
      ~inputAdornedEnd: string=?,
      ~inputHiddenLabel: string=?,
      unit
    ) =>
    t;
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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~aria_describedby: string=?,
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~defaultValue: MaterialUi_Types.any=?,
    ~disabled: bool=?,
    ~endAdornment: React.element=?,
    ~error: bool=?,
    ~fullWidth: bool=?,
    ~id: string=?,
    ~inputComponent: InputComponent.t=?,
    ~inputProps: Js.t({..})=?,
    ~margin: [@bs.string] [ | [@bs.as "dense"] `Dense | [@bs.as "none"] `None]
               =?,
    ~multiline: bool=?,
    ~name: string=?,
    ~onBlur: ReactEvent.Focus.t => unit=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~onFocus: ReactEvent.Focus.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~renderSuffix: MaterialUi_Types.any=?,
    ~required: bool=?,
    ~rows: Rows.t=?,
    ~rowsMax: RowsMax.t=?,
    ~rowsMin: RowsMin.t=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~value: MaterialUi_Types.any=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "InputBase";
