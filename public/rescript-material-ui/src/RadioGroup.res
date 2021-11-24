module Classes = {
  type t = {"root": option<string>, "row": option<string>}
  @obj external make: (~root: string=?, ~row: string=?, unit) => t = ""
}

module DefaultValue = {
  type t
  external arrayOf: array<string> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~classes: Classes.t=?,
  ~className: string=?,
  ~row: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~children: 'children=?,
  ~defaultValue: DefaultValue.t=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~value: Any.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "RadioGroup"
