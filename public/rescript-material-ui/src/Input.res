module MinRows = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module RowsMax = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module RowsMin = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "formControl": option<string>,
    "focused": option<string>,
    "disabled": option<string>,
    "colorSecondary": option<string>,
    "underline": option<string>,
    "error": option<string>,
    "marginDense": option<string>,
    "multiline": option<string>,
    "fullWidth": option<string>,
    "input": option<string>,
    "inputMarginDense": option<string>,
    "inputMultiline": option<string>,
    "inputTypeSearch": option<string>,
  }
  @obj
  external make: (
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
    unit,
  ) => t = ""
}

type color = [#primary | #secondary]

type margin = [#dense | #none]

module MaxRows = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module Rows = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~\"aria-describedby": string=?,
  ~className: string=?,
  ~minRows: MinRows.t=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~renderSuffix: Any.t=?,
  ~rowsMax: RowsMax.t=?,
  ~rowsMin: RowsMin.t=?,
  ~style: ReactDOM.Style.t=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~classes: Classes.t=?,
  ~color: color=?,
  ~defaultValue: Any.t=?,
  ~disabled: bool=?,
  ~disableUnderline: bool=?,
  ~endAdornment: React.element=?,
  ~error: bool=?,
  ~fullWidth: bool=?,
  ~id: string=?,
  ~inputComponent: Any.t=?,
  ~inputProps: {..}=?,
  ~margin: margin=?,
  ~maxRows: MaxRows.t=?,
  ~multiline: bool=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~placeholder: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~startAdornment: React.element=?,
  ~\"type": string=?,
  ~value: Any.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Input"
