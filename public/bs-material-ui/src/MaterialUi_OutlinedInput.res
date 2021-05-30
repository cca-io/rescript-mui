module RowsMin: {
  type t
  let int: int => t
  let float: float => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let string = (v: string) => Any(v)
}

module Classes = {
  type t = {
    "root": option<string>,
    "colorSecondary": option<string>,
    "focused": option<string>,
    "disabled": option<string>,
    "adornedStart": option<string>,
    "adornedEnd": option<string>,
    "error": option<string>,
    "marginDense": option<string>,
    "multiline": option<string>,
    "notchedOutline": option<string>,
    "input": option<string>,
    "inputMarginDense": option<string>,
    "inputMultiline": option<string>,
    "inputAdornedStart": option<string>,
    "inputAdornedEnd": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~colorSecondary: string=?,
    ~focused: string=?,
    ~disabled: string=?,
    ~adornedStart: string=?,
    ~adornedEnd: string=?,
    ~error: string=?,
    ~marginDense: string=?,
    ~multiline: string=?,
    ~notchedOutline: string=?,
    ~input: string=?,
    ~inputMarginDense: string=?,
    ~inputMultiline: string=?,
    ~inputAdornedStart: string=?,
    ~inputAdornedEnd: string=?,
    unit,
  ) => t = ""
}

type color = [#primary | #secondary]

module InputComponent: {
  type t
  let string: string => t
  let inputComponent_func: MaterialUi_Types.any => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let inputComponent_func = (v: MaterialUi_Types.any) => Any(v)
  let element = (v: React.element) => Any(v)
}

type margin = [#dense | #none]

module Rows: {
  type t
  let int: int => t
  let float: float => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let string = (v: string) => Any(v)
}

module RowsMax: {
  type t
  let int: int => t
  let float: float => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let string = (v: string) => Any(v)
}

@react.component @module("@material-ui/core")
external make: (
  ~\"aria-describedby": string=?,
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
  ~classes: Classes.t=?,
  ~color: color=?,
  ~defaultValue: MaterialUi_Types.any=?,
  ~disabled: bool=?,
  ~endAdornment: React.element=?,
  ~error: bool=?,
  ~fullWidth: bool=?,
  ~id: string=?,
  ~inputComponent: InputComponent.t=?,
  ~inputProps: {..}=?,
  ~label: React.element=?,
  ~labelWidth: MaterialUi_Types.Number.t=?,
  ~margin: margin=?,
  ~multiline: bool=?,
  ~name: string=?,
  ~notched: bool=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~placeholder: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~rowsMax: RowsMax.t=?,
  ~startAdornment: React.element=?,
  ~\"type": string=?,
  ~value: MaterialUi_Types.any=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "OutlinedInput"
