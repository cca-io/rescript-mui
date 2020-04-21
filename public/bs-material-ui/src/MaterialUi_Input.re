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
    "root": option(option(string)),
    "formControl": option(option(string)),
    "focused": option(option(string)),
    "disabled": option(option(string)),
    "colorSecondary": option(option(string)),
    "underline": option(option(string)),
    "error": option(option(string)),
    "marginDense": option(option(string)),
    "multiline": option(option(string)),
    "fullWidth": option(option(string)),
    "input": option(option(string)),
    "inputMarginDense": option(option(string)),
    "inputMultiline": option(option(string)),
    "inputTypeSearch": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~formControl: string=?,
      ~focused: string=?,
      ~disabled: string=?,
      ~colorSecondary: string=?,
      ~underline: string=?,
      ~error: string=?,
      ~marginDense: string=?,
      ~multiline: string=?,
      ~fullWidth: string=?,
      ~input: string=?,
      ~inputMarginDense: string=?,
      ~inputMultiline: string=?,
      ~inputTypeSearch: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Primary | `Secondary];

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
    ~aria_describedby: option(string)=?,
    ~className: option(string)=?,
    ~onBlur: option(ReactEvent.Focus.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~onFocus: option(ReactEvent.Focus.t => unit)=?,
    ~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
    ~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
    ~renderSuffix: option(MaterialUi_Types.any)=?,
    ~rowsMin: option(RowsMin.t)=?,
    ~autoComplete: option(string)=?,
    ~autoFocus: option(bool)=?,
    ~classes: option(Classes.t)=?,
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
    ~inputComponent: option(MaterialUi_Types.any)=?,
    ~inputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~margin: option(
               [@bs.string] [
                 | [@bs.as "dense"] `Dense
                 | [@bs.as "none"] `None
               ],
             )
               =?,
    ~multiline: option(bool)=?,
    ~name: option(string)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~placeholder: option(string)=?,
    ~readOnly: option(bool)=?,
    ~required: option(bool)=?,
    ~rows: option(Rows.t)=?,
    ~rowsMax: option(RowsMax.t)=?,
    ~startAdornment: option(React.element)=?,
    ~_type: option(string)=?,
    ~value: option(MaterialUi_Types.any)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Input";
