type color_enum = [#primary | #secondary | #error | #info | #success | #warning]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Components = {
  type t = {"Input": option<React.element>, "Root": option<React.element>}
  @obj external make: (~\"Input": React.element=?, ~\"Root": React.element=?, unit) => t = ""
}

module ComponentsProps = {
  type t = {"input": option<Any.t>, "root": option<Any.t>}
  @obj external make: (~input: Any.t=?, ~root: Any.t=?, unit) => t = ""
}

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

module MinRows = {
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

type size_enum = [#medium | #small]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

module SlotProps = {
  type t = {"input": option<Any.t>, "root": option<Any.t>}
  @obj external make: (~input: Any.t=?, ~root: Any.t=?, unit) => t = ""
}

module Slots = {
  type t = {"input": option<React.element>, "root": option<React.element>}
  @obj external make: (~input: React.element=?, ~root: React.element=?, unit) => t = ""
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
  ~\"aria-describedby": string=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~defaultValue: Any.t=?,
  ~disabled: bool=?,
  ~disableInjectingGlobalStyles: bool=?,
  ~endAdornment: React.element=?,
  ~error: bool=?,
  ~fullWidth: bool=?,
  ~id: string=?,
  ~inputComponent: InputComponent.t=?,
  ~inputProps: {..}=?,
  ~margin: margin=?,
  ~maxRows: MaxRows.t=?,
  ~minRows: MinRows.t=?,
  ~multiline: bool=?,
  ~name: string=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onInvalid: Any.t=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~placeholder: string=?,
  ~readOnly: bool=?,
  ~renderSuffix: Any.t=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~size: Size.t=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~startAdornment: React.element=?,
  ~sx: Sx.t=?,
  ~\"type": string=?,
  ~value: Any.t=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "InputBase"
