type size_enum = [#medium | #small]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

type color_enum = [#primary | #secondary]

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
  ~className: string=?,
  ~disableInjectingGlobalStyles: bool=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onInvalid: Any.t=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~renderSuffix: Any.t=?,
  ~size: Size.t=?,
  ~style: ReactDOM.Style.t=?,
  ~autoComplete: string=?,
  ~autoFocus: bool=?,
  ~color: Color.t=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~defaultValue: Any.t=?,
  ~disabled: bool=?,
  ~disableUnderline: bool=?,
  ~endAdornment: React.element=?,
  ~error: bool=?,
  ~fullWidth: bool=?,
  ~id: string=?,
  ~inputComponent: Any.t=?,
  ~inputProps: {..}=?,
  ~margin: margin=?,
  ~maxRows: MaxRows.t=?,
  ~minRows: MinRows.t=?,
  ~multiline: bool=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~placeholder: string=?,
  ~readOnly: bool=?,
  ~required: bool=?,
  ~rows: Rows.t=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~startAdornment: React.element=?,
  ~sx: Sx.t=?,
  ~\"type": string=?,
  ~value: Any.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Input"
