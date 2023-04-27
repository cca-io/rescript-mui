module Value = {
  type t
  external int: int => t = "%identity"
}

type size_enum = [#small | #medium | #large]

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

@react.component @module("@mui/material")
external make: (
  ~className: string=?,
  ~defaultValue: Number.t=?,
  ~disabled: bool=?,
  ~emptyIcon: React.element=?,
  ~emptyLabelText: React.element=?,
  ~getLabelText: int => string=?,
  ~highlightSelectedOnly: bool=?,
  ~icon: React.element=?,
  ~\"IconContainerComponent": React.element=?,
  ~max: Number.t=?,
  ~name: string=?,
  ~onChange: (ReactEvent.Form.t, Value.t) => unit=?,
  ~onChangeActive: ({..}, int) => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~precision: Number.t=?,
  ~readOnly: bool=?,
  ~size: Size.t=?,
  ~sx: Sx.t=?,
  ~value: Number.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Rating"
