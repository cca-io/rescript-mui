type alignContent = [
  | #stretch
  | #center
  | #"flex-start"
  | #"flex-end"
  | #"space-between"
  | #"space-around"
]

type alignItems = [#"flex-start" | #center | #"flex-end" | #stretch | #baseline]

module Classes = {
  type t = {
    "root": option<string>,
    "container": option<string>,
    "item": option<string>,
    "zeroMinWidth": option<string>,
    "direction-xs-column": option<string>,
    "direction-xs-column-reverse": option<string>,
    "direction-xs-row-reverse": option<string>,
    "wrap-xs-nowrap": option<string>,
    "wrap-xs-wrap-reverse": option<string>,
    "align-items-xs-center": option<string>,
    "align-items-xs-flex-start": option<string>,
    "align-items-xs-flex-end": option<string>,
    "align-items-xs-baseline": option<string>,
    "align-content-xs-center": option<string>,
    "align-content-xs-flex-start": option<string>,
    "align-content-xs-flex-end": option<string>,
    "align-content-xs-space-between": option<string>,
    "align-content-xs-space-around": option<string>,
    "justify-content-xs-center": option<string>,
    "justify-content-xs-flex-end": option<string>,
    "justify-content-xs-space-between": option<string>,
    "justify-content-xs-space-around": option<string>,
    "justify-content-xs-space-evenly": option<string>,
    "spacing-xs-1": option<string>,
    "spacing-xs-2": option<string>,
    "spacing-xs-3": option<string>,
    "spacing-xs-4": option<string>,
    "spacing-xs-5": option<string>,
    "spacing-xs-6": option<string>,
    "spacing-xs-7": option<string>,
    "spacing-xs-8": option<string>,
    "spacing-xs-9": option<string>,
    "spacing-xs-10": option<string>,
    "grid-xs-auto": option<string>,
    "grid-xs-true": option<string>,
    "grid-xs-1": option<string>,
    "grid-xs-2": option<string>,
    "grid-xs-3": option<string>,
    "grid-xs-4": option<string>,
    "grid-xs-5": option<string>,
    "grid-xs-6": option<string>,
    "grid-xs-7": option<string>,
    "grid-xs-8": option<string>,
    "grid-xs-9": option<string>,
    "grid-xs-10": option<string>,
    "grid-xs-11": option<string>,
    "grid-xs-12": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~container: string=?,
    ~item: string=?,
    ~zeroMinWidth: string=?,
    ~\"direction-xs-column": string=?,
    ~\"direction-xs-column-reverse": string=?,
    ~\"direction-xs-row-reverse": string=?,
    ~\"wrap-xs-nowrap": string=?,
    ~\"wrap-xs-wrap-reverse": string=?,
    ~\"align-items-xs-center": string=?,
    ~\"align-items-xs-flex-start": string=?,
    ~\"align-items-xs-flex-end": string=?,
    ~\"align-items-xs-baseline": string=?,
    ~\"align-content-xs-center": string=?,
    ~\"align-content-xs-flex-start": string=?,
    ~\"align-content-xs-flex-end": string=?,
    ~\"align-content-xs-space-between": string=?,
    ~\"align-content-xs-space-around": string=?,
    ~\"justify-content-xs-center": string=?,
    ~\"justify-content-xs-flex-end": string=?,
    ~\"justify-content-xs-space-between": string=?,
    ~\"justify-content-xs-space-around": string=?,
    ~\"justify-content-xs-space-evenly": string=?,
    ~\"spacing-xs-1": string=?,
    ~\"spacing-xs-2": string=?,
    ~\"spacing-xs-3": string=?,
    ~\"spacing-xs-4": string=?,
    ~\"spacing-xs-5": string=?,
    ~\"spacing-xs-6": string=?,
    ~\"spacing-xs-7": string=?,
    ~\"spacing-xs-8": string=?,
    ~\"spacing-xs-9": string=?,
    ~\"spacing-xs-10": string=?,
    ~\"grid-xs-auto": string=?,
    ~\"grid-xs-true": string=?,
    ~\"grid-xs-1": string=?,
    ~\"grid-xs-2": string=?,
    ~\"grid-xs-3": string=?,
    ~\"grid-xs-4": string=?,
    ~\"grid-xs-5": string=?,
    ~\"grid-xs-6": string=?,
    ~\"grid-xs-7": string=?,
    ~\"grid-xs-8": string=?,
    ~\"grid-xs-9": string=?,
    ~\"grid-xs-10": string=?,
    ~\"grid-xs-11": string=?,
    ~\"grid-xs-12": string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type direction = [#row | #"row-reverse" | #column | #"column-reverse"]

type justify = [
  | #"flex-start"
  | #center
  | #"flex-end"
  | #"space-between"
  | #"space-around"
  | #"space-evenly"
]

type justifyContent = [
  | #"flex-start"
  | #center
  | #"flex-end"
  | #"space-between"
  | #"space-around"
  | #"space-evenly"
]

module Lg: {
  type t
  let \"false": t
  let auto: t
  let \"true": t
  let \"1": t
  let \"2": t
  let \"3": t
  let \"4": t
  let \"5": t
  let \"6": t
  let \"7": t
  let \"8": t
  let \"9": t
  let \"10": t
  let \"11": t
  let \"12": t
} = {
  @unboxed
  type rec t = Any('a): t

  let \"false" = Any(false)
  let auto = Any("auto")
  let \"true" = Any(true)
  let \"1" = Any(1)
  let \"2" = Any(2)
  let \"3" = Any(3)
  let \"4" = Any(4)
  let \"5" = Any(5)
  let \"6" = Any(6)
  let \"7" = Any(7)
  let \"8" = Any(8)
  let \"9" = Any(9)
  let \"10" = Any(10)
  let \"11" = Any(11)
  let \"12" = Any(12)
}

module Md: {
  type t
  let \"false": t
  let auto: t
  let \"true": t
  let \"1": t
  let \"2": t
  let \"3": t
  let \"4": t
  let \"5": t
  let \"6": t
  let \"7": t
  let \"8": t
  let \"9": t
  let \"10": t
  let \"11": t
  let \"12": t
} = {
  @unboxed
  type rec t = Any('a): t

  let \"false" = Any(false)
  let auto = Any("auto")
  let \"true" = Any(true)
  let \"1" = Any(1)
  let \"2" = Any(2)
  let \"3" = Any(3)
  let \"4" = Any(4)
  let \"5" = Any(5)
  let \"6" = Any(6)
  let \"7" = Any(7)
  let \"8" = Any(8)
  let \"9" = Any(9)
  let \"10" = Any(10)
  let \"11" = Any(11)
  let \"12" = Any(12)
}

module Sm: {
  type t
  let \"false": t
  let auto: t
  let \"true": t
  let \"1": t
  let \"2": t
  let \"3": t
  let \"4": t
  let \"5": t
  let \"6": t
  let \"7": t
  let \"8": t
  let \"9": t
  let \"10": t
  let \"11": t
  let \"12": t
} = {
  @unboxed
  type rec t = Any('a): t

  let \"false" = Any(false)
  let auto = Any("auto")
  let \"true" = Any(true)
  let \"1" = Any(1)
  let \"2" = Any(2)
  let \"3" = Any(3)
  let \"4" = Any(4)
  let \"5" = Any(5)
  let \"6" = Any(6)
  let \"7" = Any(7)
  let \"8" = Any(8)
  let \"9" = Any(9)
  let \"10" = Any(10)
  let \"11" = Any(11)
  let \"12" = Any(12)
}

type spacing = [#0 | #1 | #2 | #3 | #4 | #5 | #6 | #7 | #8 | #9 | #10]

type wrap = [#nowrap | #wrap | #"wrap-reverse"]

module Xl: {
  type t
  let \"false": t
  let auto: t
  let \"true": t
  let \"1": t
  let \"2": t
  let \"3": t
  let \"4": t
  let \"5": t
  let \"6": t
  let \"7": t
  let \"8": t
  let \"9": t
  let \"10": t
  let \"11": t
  let \"12": t
} = {
  @unboxed
  type rec t = Any('a): t

  let \"false" = Any(false)
  let auto = Any("auto")
  let \"true" = Any(true)
  let \"1" = Any(1)
  let \"2" = Any(2)
  let \"3" = Any(3)
  let \"4" = Any(4)
  let \"5" = Any(5)
  let \"6" = Any(6)
  let \"7" = Any(7)
  let \"8" = Any(8)
  let \"9" = Any(9)
  let \"10" = Any(10)
  let \"11" = Any(11)
  let \"12" = Any(12)
}

module Xs: {
  type t
  let \"false": t
  let auto: t
  let \"true": t
  let \"1": t
  let \"2": t
  let \"3": t
  let \"4": t
  let \"5": t
  let \"6": t
  let \"7": t
  let \"8": t
  let \"9": t
  let \"10": t
  let \"11": t
  let \"12": t
} = {
  @unboxed
  type rec t = Any('a): t

  let \"false" = Any(false)
  let auto = Any("auto")
  let \"true" = Any(true)
  let \"1" = Any(1)
  let \"2" = Any(2)
  let \"3" = Any(3)
  let \"4" = Any(4)
  let \"5" = Any(5)
  let \"6" = Any(6)
  let \"7" = Any(7)
  let \"8" = Any(8)
  let \"9" = Any(9)
  let \"10" = Any(10)
  let \"11" = Any(11)
  let \"12" = Any(12)
}

@react.component @module("@material-ui/core")
external make: (
  ~alignContent: alignContent=?,
  ~alignItems: alignItems=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~container: bool=?,
  ~direction: direction=?,
  ~item: bool=?,
  ~justify: justify=?,
  ~justifyContent: justifyContent=?,
  ~lg: Lg.t=?,
  ~md: Md.t=?,
  ~sm: Sm.t=?,
  ~spacing: @int
  [
    | @as(0) #0
    | @as(1) #1
    | @as(2) #2
    | @as(3) #3
    | @as(4) #4
    | @as(5) #5
    | @as(6) #6
    | @as(7) #7
    | @as(8) #8
    | @as(9) #9
    | @as(10) #10
  ]=?,
  ~wrap: wrap=?,
  ~xl: Xl.t=?,
  ~xs: Xs.t=?,
  ~zeroMinWidth: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Grid"
