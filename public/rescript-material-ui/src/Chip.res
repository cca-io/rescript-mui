type color_enum = [#default | #primary | #secondary | #error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

type size_enum = [#medium | #small]

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

type variant_enum = [#filled | #outlined]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~avatar: React.element=?,
  ~children: React.element=?,
  ~className: string=?,
  ~clickable: bool=?,
  ~color: Color.t=?,
  ~component: React.element=?,
  ~deleteIcon: React.element=?,
  ~disabled: bool=?,
  ~icon: React.element=?,
  ~label: React.element=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onDelete: ReactEvent.Synthetic.t => unit=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~size: Size.t=?,
  ~skipFocusWhenDisabled: bool=?,
  ~sx: Sx.t=?,
  ~tabIndex: Number.t=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Chip"
