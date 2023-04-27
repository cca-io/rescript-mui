type color_enum = [#primary | #secondary | #error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module DefaultValue = {
  type t
  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

type margin = [#dense | #none | #normal]

module MaxRows = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

module MinRows = {
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

type size_enum = [#medium | #small]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

module Value = {
  type t
  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

type variant = [#filled | #outlined | #standard]

@react.component @module("@mui/material")
external make: (
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~defaultValue: DefaultValue.t=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~\"FormHelperTextProps": {..}=?,
  ~fullWidth: bool=?,
  ~helperText: React.element=?,
  ~id: string=?,
  ~\"InputLabelProps": {..}=?,
  ~inputProps: {..}=?,
  ~\"InputProps": {..}=?,
  ~inputRef: ReactDOM.domRef=?,
  ~label: React.element=?,
  ~margin: margin=?,
  ~maxRows: MaxRows.t=?,
  ~minRows: MinRows.t=?,
  ~multiline: bool=?,
  ~name: string=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~placeholder: string=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~select: bool=?,
  ~\"SelectProps": {..}=?,
  ~size: Size.t=?,
  ~sx: Sx.t=?,
  ~\"type": string=?,
  ~value: Value.t=?,
  ~variant: variant=?,
  ~style: ReactDOM.Style.t=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TextField"
