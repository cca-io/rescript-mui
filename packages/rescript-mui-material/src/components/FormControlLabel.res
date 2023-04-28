module ComponentsProps = {
  type t = {"typography": option<Any.t>}
  @obj external make: (~typography: Any.t=?, unit) => t = ""
}

type labelPlacement = [#bottom | #end | #start | #top]

module SlotProps = {
  type t = {"typography": option<Any.t>}
  @obj external make: (~typography: Any.t=?, unit) => t = ""
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
  ~checked: bool=?,
  ~className: string=?,
  ~componentsProps: ComponentsProps.t=?,
  ~control: React.element,
  ~disabled: bool=?,
  ~disableTypography: bool=?,
  ~inputRef: ReactDOM.domRef=?,
  ~label: React.element=?,
  ~labelPlacement: labelPlacement=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~slotProps: SlotProps.t=?,
  ~sx: Sx.t=?,
  ~value: Any.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "FormControlLabel"
