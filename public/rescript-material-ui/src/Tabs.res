type indicatorColor_enum = [#primary | #secondary]

module IndicatorColor = {
  type t
  external enum: indicatorColor_enum => t = "%identity"
  external string: string => t = "%identity"
}

type orientation = [#horizontal | #vertical]

module ScrollButtons: {
  type t
  let auto: t
  let \"false": t
  let \"true": t
} = {
  @unboxed
  type rec t = Any('a): t

  let auto = Any("auto")
  let \"false" = Any(false)
  let \"true" = Any(true)
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

type textColor = [#inherit | #primary | #secondary]

type variant = [#fullWidth | #scrollable | #standard]

@react.component @module("@mui/material")
external make: (
  ~allowScrollButtonsMobile: bool=?,
  ~\"aria-label": string=?,
  ~\"aria-labelledby": string=?,
  ~centered: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~component: React.element=?,
  ~indicatorColor: IndicatorColor.t=?,
  ~onChange: (ReactEvent.Form.t, Any.t) => unit=?,
  ~orientation: orientation=?,
  ~\"ScrollButtonComponent": React.element=?,
  ~scrollButtons: ScrollButtons.t=?,
  ~selectionFollowsFocus: bool=?,
  ~sx: Sx.t=?,
  ~\"TabIndicatorProps": {..}=?,
  ~\"TabScrollButtonProps": {..}=?,
  ~textColor: textColor=?,
  ~value: Any.t=?,
  ~variant: variant=?,
  ~visibleScrollbar: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Tabs"
