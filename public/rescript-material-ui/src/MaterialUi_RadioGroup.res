module Classes = {
  type t = {"root": option<string>, "row": option<string>}
  @obj external make: (~root: string=?, ~row: string=?, unit) => t = ""
}

module DefaultValue: {
  type t
  let arrayOf: array<string> => t
  let int: int => t
  let float: float => t
  let string: string => t
} = {
  @unboxed
  type rec t = Any('a): t
  let arrayOf = (v: array<string>) => Any(v)
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let string = (v: string) => Any(v)
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
  ~value: MaterialUi_Types.any=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "RadioGroup"
