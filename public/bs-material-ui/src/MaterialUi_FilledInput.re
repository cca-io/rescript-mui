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

module Classes = {
  type t = {
    .
    "root": option(string),
    "colorSecondary": option(string),
    "underline": option(string),
    "focused": option(string),
    "disabled": option(string),
    "adornedStart": option(string),
    "adornedEnd": option(string),
    "error": option(string),
    "marginDense": option(string),
    "multiline": option(string),
    "input": option(string),
    "inputMarginDense": option(string),
    "inputHiddenLabel": option(string),
    "inputMultiline": option(string),
    "inputAdornedStart": option(string),
    "inputAdornedEnd": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorSecondary: string=?,
      ~underline: string=?,
      ~focused: string=?,
      ~disabled: string=?,
      ~adornedStart: string=?,
      ~adornedEnd: string=?,
      ~error: string=?,
      ~marginDense: string=?,
      ~multiline: string=?,
      ~input: string=?,
      ~inputMarginDense: string=?,
      ~inputHiddenLabel: string=?,
      ~inputMultiline: string=?,
      ~inputAdornedStart: string=?,
      ~inputAdornedEnd: string=?,
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
    ~autoComplete: string=?,
    ~autoFocus: bool=?,
    ~classes: Classes.t=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~defaultValue: MaterialUi_Types.any=?,
    ~disabled: bool=?,
    ~disableUnderline: bool=?,
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
    ~onChange: ReactEvent.Form.t => unit=?,
    ~placeholder: string=?,
    ~readOnly: bool=?,
    ~required: bool=?,
    ~rows: Rows.t=?,
    ~rowsMax: RowsMax.t=?,
    ~startAdornment: React.element=?,
    ~_type: string=?,
    ~value: MaterialUi_Types.any=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "FilledInput";
