module Classes = {
  type t = {
    "@global": option<string>,
    "root": option<string>,
    "formControl": option<string>,
    "focused": option<string>,
    "disabled": option<string>,
    "adornedStart": option<string>,
    "adornedEnd": option<string>,
    "error": option<string>,
    "marginDense": option<string>,
    "multiline": option<string>,
    "colorSecondary": option<string>,
    "fullWidth": option<string>,
    "input": option<string>,
    "inputMarginDense": option<string>,
    "inputMultiline": option<string>,
    "inputTypeSearch": option<string>,
    "inputAdornedStart": option<string>,
    "inputAdornedEnd": option<string>,
    "inputHiddenLabel": option<string>,
  }
  @obj
  external make: (
    ~\"@global": string=?,
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
    unit,
  ) => t = ""
}

type color = [#primary | #secondary]

module InputComponent = {
  type t
  external string: string => t = "%identity"
  external inputComponent_func: Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

type margin = [#dense | #none]

module Rows = {
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

@react.component @module("@material-ui/core")
external make: (
  ~\"aria-describedby": string=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~defaultValue: Types.any=?,
  ~disabled: bool=?,
  ~endAdornment: React.element=?,
  ~error: bool=?,
  ~fullWidth: bool=?,
  ~id: string=?,
  ~inputComponent: InputComponent.t=?,
  ~inputProps: {..}=?,
  ~margin: margin=?,
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
  ~renderSuffix: Types.any=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~rowsMax: RowsMax.t=?,
  ~rowsMin: RowsMin.t=?,
  ~startAdornment: React.element=?,
  ~\"type": string=?,
  ~value: Types.any=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "InputBase"
