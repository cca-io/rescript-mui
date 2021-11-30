module Animation: {
  type t
  let pulse: t
  let wave: t
  let \"false": t
} = {
  @unboxed
  type rec t = Any('a): t

  let pulse = Any("pulse")
  let wave = Any("wave")
  let \"false" = Any(false)
}

module Classes = {
  type t = {
    "root": option<string>,
    "text": option<string>,
    "rect": option<string>,
    "circle": option<string>,
    "pulse": option<string>,
    "wave": option<string>,
    "withChildren": option<string>,
    "fitContent": option<string>,
    "heightAuto": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~text: string=?,
    ~rect: string=?,
    ~circle: string=?,
    ~pulse: string=?,
    ~wave: string=?,
    ~withChildren: string=?,
    ~fitContent: string=?,
    ~heightAuto: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Height = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

type variant = [#text | #rect | #circle]

module Width = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@material-ui/lab")
external make: (
  ~animation: Animation.t=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~height: Height.t=?,
  ~variant: variant=?,
  ~width: Width.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Skeleton"
