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
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    focused: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    adornedStart: string,
    [@bs.optional]
    adornedEnd: string,
    [@bs.optional]
    error: string,
    [@bs.optional]
    marginDense: string,
    [@bs.optional]
    multiline: string,
    [@bs.optional]
    notchedOutline: string,
    [@bs.optional]
    input: string,
    [@bs.optional]
    inputMarginDense: string,
    [@bs.optional]
    inputMultiline: string,
    [@bs.optional]
    inputAdornedStart: string,
    [@bs.optional]
    inputAdornedEnd: string,
  };
  let make = t;
};

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
    ~endAdornment: option(React.element)=?,
    ~error: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~id: option(string)=?,
    ~inputComponent: option(InputComponent.t)=?,
    ~inputProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~label: option(React.element)=?,
    ~labelWidth: option(MaterialUi_Types.Number.t)=?,
    ~margin: option(
               [@bs.string] [
                 | [@bs.as "dense"] `Dense
                 | [@bs.as "none"] `None
               ],
             )
               =?,
    ~multiline: option(bool)=?,
    ~name: option(string)=?,
    ~notched: option(bool)=?,
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
  "OutlinedInput";
