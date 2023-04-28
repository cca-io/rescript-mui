type loadingPosition = [#start | #end | #center]

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

type variant_enum = [#contained | #outlined | #text]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/lab")
external make: (
  ~children: React.element=?,
  ~disabled: bool=?,
  ~id: string=?,
  ~loading: bool=?,
  ~loadingIndicator: React.element=?,
  ~loadingPosition: loadingPosition=?,
  ~sx: Sx.t=?,
  ~variant: Variant.t=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "LoadingButton"
