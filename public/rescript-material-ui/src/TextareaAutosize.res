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

module Value = {
  type t
  external arrayOf: array<string> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~className: string=?,
  ~maxRows: MaxRows.t=?,
  ~minRows: MinRows.t=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~placeholder: string=?,
  ~rows: Number.t=?,
  ~rowsMax: Number.t=?,
  ~rowsMin: Number.t=?,
  ~style: ReactDOM.Style.t=?,
  ~value: Value.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TextareaAutosize"
