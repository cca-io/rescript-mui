module Classes = {
  type t = {
    "root": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "marked": option<string>,
    "vertical": option<string>,
    "disabled": option<string>,
    "rail": option<string>,
    "track": option<string>,
    "trackFalse": option<string>,
    "trackInverted": option<string>,
    "thumb": option<string>,
    "thumbColorPrimary": option<string>,
    "thumbColorSecondary": option<string>,
    "active": option<string>,
    "focusVisible": option<string>,
    "valueLabel": option<string>,
    "mark": option<string>,
    "markActive": option<string>,
    "markLabel": option<string>,
    "markLabelActive": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~marked: string=?,
    ~vertical: string=?,
    ~disabled: string=?,
    ~rail: string=?,
    ~track: string=?,
    ~trackFalse: string=?,
    ~trackInverted: string=?,
    ~thumb: string=?,
    ~thumbColorPrimary: string=?,
    ~thumbColorSecondary: string=?,
    ~active: string=?,
    ~focusVisible: string=?,
    ~valueLabel: string=?,
    ~mark: string=?,
    ~markActive: string=?,
    ~markLabel: string=?,
    ~markLabelActive: string=?,
    unit,
  ) => t = ""
}

type color = [#primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module DefaultValue = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external arrayOf: array<Number.t> => t = "%identity"
}

module Marks = {
  type t
  external bool: bool => t = "%identity"
  external array: array<Any.t> => t = "%identity"
}

type orientation = [#horizontal | #vertical]

module ThumbComponent = {
  type t
  external string: string => t = "%identity"
  external thumbComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module Track: {
  type t
  let normal: t
  let \"false": t
  let inverted: t
} = {
  @unboxed
  type rec t = Any('a): t

  let normal = Any("normal")
  let \"false" = Any(false)
  let inverted = Any("inverted")
}

module Value = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external arrayOf: array<Number.t> => t = "%identity"
}

module ValueLabelComponent = {
  type t
  external string: string => t = "%identity"
  external valueLabelComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

type valueLabelDisplay = [#on | #auto | #off]

module ValueLabelFormat = {
  type t
  external string: string => t = "%identity"
  external valueLabelFormat_func: Any.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~\"aria-labelledby": string=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~defaultValue: DefaultValue.t=?,
  ~disabled: bool=?,
  ~getAriaLabel: int => string=?,
  ~getAriaValueText: (int, int) => string=?,
  ~marks: Marks.t=?,
  ~max: Number.t=?,
  ~min: Number.t=?,
  ~name: string=?,
  ~onChange: (ReactEvent.Form.t, int) => unit=?,
  ~onChangeCommitted: (ReactEvent.Form.t, int) => unit=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~orientation: orientation=?,
  ~scale: Any.t=?,
  ~step: Number.t=?,
  ~\"ThumbComponent": ThumbComponent.t=?,
  ~track: Track.t=?,
  ~value: Value.t=?,
  ~\"ValueLabelComponent": ValueLabelComponent.t=?,
  ~valueLabelDisplay: valueLabelDisplay=?,
  ~valueLabelFormat: ValueLabelFormat.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Slider"
