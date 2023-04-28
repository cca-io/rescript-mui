type color_enum = [#primary | #secondary | #standard]

module Color = {
  type t
  external enum: color_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Components = {
  type t = {
    "first": option<React.element>,
    "last": option<React.element>,
    "next": option<React.element>,
    "previous": option<React.element>,
  }
  @obj
  external make: (
    ~first: React.element=?,
    ~last: React.element=?,
    ~next: React.element=?,
    ~previous: React.element=?,
    unit,
  ) => t = ""
}

type shape = [#circular | #rounded]

type size_enum = [#small | #medium | #large]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

module Slots = {
  type t = {
    "first": option<React.element>,
    "last": option<React.element>,
    "next": option<React.element>,
    "previous": option<React.element>,
  }
  @obj
  external make: (
    ~first: React.element=?,
    ~last: React.element=?,
    ~next: React.element=?,
    ~previous: React.element=?,
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

type \"type" = [#"end-ellipsis" | #first | #last | #next | #page | #previous | #"start-ellipsis"]

type variant_enum = [#outlined | #text]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~color: Color.t=?,
  ~component: React.element=?,
  ~components: Components.t=?,
  ~disabled: bool=?,
  ~page: React.element=?,
  ~selected: bool=?,
  ~shape: shape=?,
  ~size: Size.t=?,
  ~slots: Slots.t=?,
  ~sx: Sx.t=?,
  ~\"type": \"type"=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "PaginationItem"
