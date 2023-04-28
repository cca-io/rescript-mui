type color = [#primary | #secondary]

module Color = {
  type t
  external enum: color => t = "%identity"
  external string: string => t = "%identity"
}

module Components = {
  type t = {
    "Input": option<React.element>,
    "Mark": option<React.element>,
    "MarkLabel": option<React.element>,
    "Rail": option<React.element>,
    "Root": option<React.element>,
    "Thumb": option<React.element>,
    "Track": option<React.element>,
    "ValueLabel": option<React.element>,
  }
  @obj
  external make: (
    ~\"Input": React.element=?,
    ~\"Mark": React.element=?,
    ~\"MarkLabel": React.element=?,
    ~\"Rail": React.element=?,
    ~\"Root": React.element=?,
    ~\"Thumb": React.element=?,
    ~\"Track": React.element=?,
    ~\"ValueLabel": React.element=?,
    unit,
  ) => t = ""
}

module Input = {
  type t
  external input_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Mark = {
  type t
  external mark_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module MarkLabel = {
  type t
  external markLabel_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Rail = {
  type t
  external rail_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Root = {
  type t
  external root_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Thumb = {
  type t
  external thumb_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

module Track = {
  type t
  external track_func: Any.t => t = "%identity"
  external any: Any.t => t = "%identity"
}

type valueLabelDisplay = [#auto | #off | #on]

module ValueLabel_shape = {
  type t = {
    "children": option<React.element>,
    "className": option<string>,
    "open": option<bool>,
    "style": option<Any.t>,
    "value": option<Number.t>,
    "valueLabelDisplay": option<valueLabelDisplay>,
  }
  @obj
  external make: (
    ~children: React.element=?,
    ~className: string=?,
    ~\"open": bool=?,
    ~style: Any.t=?,
    ~value: Number.t=?,
    ~valueLabelDisplay: valueLabelDisplay=?,
    unit,
  ) => t = ""
}

module ValueLabel = {
  type t
  external valueLabel_func: Any.t => t = "%identity"
  external shape: ValueLabel_shape.t => t = "%identity"
}

module ComponentsProps = {
  type t = {
    "input": option<Input.t>,
    "mark": option<Mark.t>,
    "markLabel": option<MarkLabel.t>,
    "rail": option<Rail.t>,
    "root": option<Root.t>,
    "thumb": option<Thumb.t>,
    "track": option<Track.t>,
    "valueLabel": option<ValueLabel.t>,
  }
  @obj
  external make: (
    ~input: Input.t=?,
    ~mark: Mark.t=?,
    ~markLabel: MarkLabel.t=?,
    ~rail: Rail.t=?,
    ~root: Root.t=?,
    ~thumb: Thumb.t=?,
    ~track: Track.t=?,
    ~valueLabel: ValueLabel.t=?,
    unit,
  ) => t = ""
}

module DefaultValue = {
  type t
  external arrayOf: array<Number.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

module Marks_arrayOf = {
  type t = {"label": option<React.element>, "value": option<Number.t>}
  @obj external make: (~label: React.element=?, ~value: Number.t=?, unit) => t = ""
}

module Marks = {
  type t
  external arrayOf: array<Marks_arrayOf.t> => t = "%identity"
  external bool: bool => t = "%identity"
}

type orientation = [#horizontal | #vertical]

type size_enum = [#small | #medium]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

module SlotProps = {
  type t = {
    "input": option<Input.t>,
    "mark": option<Mark.t>,
    "markLabel": option<MarkLabel.t>,
    "rail": option<Rail.t>,
    "root": option<Root.t>,
    "thumb": option<Thumb.t>,
    "track": option<Track.t>,
    "valueLabel": option<ValueLabel.t>,
  }
  @obj
  external make: (
    ~input: Input.t=?,
    ~mark: Mark.t=?,
    ~markLabel: MarkLabel.t=?,
    ~rail: Rail.t=?,
    ~root: Root.t=?,
    ~thumb: Thumb.t=?,
    ~track: Track.t=?,
    ~valueLabel: ValueLabel.t=?,
    unit,
  ) => t = ""
}

module Slots = {
  type t = {
    "input": option<React.element>,
    "mark": option<React.element>,
    "markLabel": option<React.element>,
    "rail": option<React.element>,
    "root": option<React.element>,
    "thumb": option<React.element>,
    "track": option<React.element>,
    "valueLabel": option<React.element>,
  }
  @obj
  external make: (
    ~input: React.element=?,
    ~mark: React.element=?,
    ~markLabel: React.element=?,
    ~rail: React.element=?,
    ~root: React.element=?,
    ~thumb: React.element=?,
    ~track: React.element=?,
    ~valueLabel: React.element=?,
    unit,
  ) => t = ""
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

module TrackPresentation: {
  type t
  let inverted: t
  let normal: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let inverted = Any("inverted")
  let normal = Any("normal")
  let \"false" = Any(false)
}

module Value = {
  type t
  external arrayOf: array<Number.t> => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
}

module ValueLabelFormat = {
  type t
  external valueLabelFormat_func: Any.t => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~\"aria-labelledby": string=?,
  ~children: React.element=?,
  ~color: Color.t=?,
  ~components: Components.t=?,
  ~componentsProps: ComponentsProps.t=?,
  ~defaultValue: DefaultValue.t=?,
  ~disabled: bool=?,
  ~disableSwap: bool=?,
  ~getAriaLabel: int => string=?,
  ~getAriaValueText: (int, int) => string=?,
  ~marks: Marks.t=?,
  ~max: Number.t=?,
  ~min: Number.t=?,
  ~name: string=?,
  ~onChange: (ReactEvent.Form.t, int) => unit=?,
  ~onChangeCommitted: (ReactEvent.Form.t, int) => unit=?,
  ~orientation: orientation=?,
  ~scale: Any.t=?,
  ~size: Size.t=?,
  ~slotProps: SlotProps.t=?,
  ~slots: Slots.t=?,
  ~step: Number.t=?,
  ~sx: Sx.t=?,
  ~tabIndex: Number.t=?,
  ~track: TrackPresentation.t=?,
  ~value: Value.t=?,
  ~valueLabelDisplay: valueLabelDisplay=?,
  ~valueLabelFormat: ValueLabelFormat.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Slider"
