module Component: {
  type t
  let string: string => t
  let callback: (unit => React.element) => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let callback = (v: unit => React.element) => Any(v)
  let element = (v: React.element) => Any(v)
}

module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

type color = [#primary | #secondary]

module DefaultValue: {
  type t
  let string: string => t
  let int: int => t
  let float: float => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
}

type margin = [#dense | #none | #normal]

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

type size = [#medium | #small]

module Value: {
  type t
  let string: string => t
  let int: int => t
  let float: float => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
}

type variant = [#filled | #outlined | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~focused: bool=?,
  ~style: ReactDOM.Style.t=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~children: 'children=?,
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
  ~label: React.element=?,
  ~margin: margin=?,
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
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TextField"
