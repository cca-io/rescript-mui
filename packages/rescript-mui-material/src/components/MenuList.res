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

type variant = [#menu | #selectedMenu]

@react.component @module("@mui/material")
external make: (
  ~component: React.element=?,
  ~dense: bool=?,
  ~disablePadding: bool=?,
  ~subheader: React.element=?,
  ~sx: Sx.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~autoFocus: bool=?,
  ~autoFocusItem: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~disabledItemsFocusable: bool=?,
  ~disableListWrap: bool=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~variant: variant=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "MenuList"
