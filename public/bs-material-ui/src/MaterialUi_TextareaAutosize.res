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

module Value: {
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
  ~className: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~placeholder: string=?,
  ~rows: Rows.t=?,
  ~rowsMax: RowsMax.t=?,
  ~rowsMin: RowsMin.t=?,
  ~style: ReactDOM.Style.t=?,
  ~value: Value.t=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TextareaAutosize"
