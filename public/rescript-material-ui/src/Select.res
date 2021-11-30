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

type color = [#primary | #secondary]

module InputComponent = {
  type t
  external string: string => t = "%identity"
  external inputComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

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

module Classes = {
  type t = {
    "root": option<string>,
    "select": option<string>,
    "filled": option<string>,
    "outlined": option<string>,
    "selectMenu": option<string>,
    "disabled": option<string>,
    "icon": option<string>,
    "iconOpen": option<string>,
    "iconFilled": option<string>,
    "iconOutlined": option<string>,
    "nativeInput": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~select: string=?,
    ~filled: string=?,
    ~outlined: string=?,
    ~selectMenu: string=?,
    ~disabled: string=?,
    ~icon: string=?,
    ~iconOpen: string=?,
    ~iconFilled: string=?,
    ~iconOutlined: string=?,
    ~nativeInput: string=?,
    unit,
  ) => t = ""
}

module IconComponent = {
  type t
  external string: string => t = "%identity"
  external iconComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module Value = {
  type t
  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external arrayOf: array<string> => t = "%identity"
}

type variant = [#filled | #outlined | #standard]

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
  ~color: color=?,
  ~disabled: bool=?,
  ~disableUnderline: bool=?,
  ~endAdornment: React.element=?,
  ~error: bool=?,
  ~fullWidth: bool=?,
  ~inputComponent: InputComponent.t=?,
  ~margin: margin=?,
  ~maxRows: MaxRows.t=?,
  ~multiline: bool=?,
  ~name: string=?,
  ~placeholder: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~startAdornment: React.element=?,
  ~\"type": string=?,
  ~autoWidth: bool=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~defaultValue: Any.t=?,
  ~displayEmpty: bool=?,
  ~\"IconComponent": IconComponent.t=?,
  ~id: string=?,
  ~input: React.element=?,
  ~inputProps: {..}=?,
  ~label: React.element=?,
  ~labelId: string=?,
  ~labelWidth: Number.t=?,
  ~\"MenuProps": {..}=?,
  ~multiple: bool=?,
  ~native: bool=?,
  ~onChange: (ReactEvent.Form.t, {..}) => unit=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~onOpen: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~renderValue: Any.t => React.element=?,
  ~\"SelectDisplayProps": {..}=?,
  ~value: Value.t=?,
  ~variant: variant=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Select"
