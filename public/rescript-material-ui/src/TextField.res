module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

type color = [#primary | #secondary]

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

module RowsMax = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

type size = [#medium | #small]

module Value = {
  type t
  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

type variant = [#filled | #outlined | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~focused: bool=?,
  ~style: ReactDOM.Style.t=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~defaultValue: DefaultValue.t=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~\"FormHelperTextProps": {..}=?,
  ~fullWidth: bool=?,
  ~helperText: React.element=?,
  ~hiddenLabel: bool=?,
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
  ~rowsMax: RowsMax.t=?,
  ~select: bool=?,
  ~\"SelectProps": {..}=?,
  ~size: size=?,
  ~\"type": string=?,
  ~value: Value.t=?,
  ~variant: variant=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TextField"
