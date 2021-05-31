module Classes = {
  type t = {"root": option<string>, "ul": option<string>}
  @obj external make: (~root: string=?, ~ul: string=?, unit) => t = ""
}

type color = [#primary | #secondary | #standard]

module Color: {
  type t
  let primary: t
  let secondary: t
  let standard: t
} = {
  @unboxed
  type rec t = Any('a): t

  let primary = Any("primary")
  let secondary = Any("secondary")
  let standard = Any("standard")
}

module Shape: {
  type t
  let round: t
  let rounded: t
} = {
  @unboxed
  type rec t = Any('a): t

  let round = Any("round")
  let rounded = Any("rounded")
}

module Size: {
  type t
  let large: t
  let medium: t
  let small: t
} = {
  @unboxed
  type rec t = Any('a): t

  let large = Any("large")
  let medium = Any("medium")
  let small = Any("small")
}

module Variant: {
  type t
  let outlined: t
  let text: t
} = {
  @unboxed
  type rec t = Any('a): t

  let outlined = Any("outlined")
  let text = Any("text")
}

type shape = [#round | #rounded]

type size = [#large | #medium | #small]

type variant = [#outlined | #text]

@react.component @module("@material-ui/lab")
external make: (
  ~boundaryCount: MaterialUi_Types.Number.t=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~count: MaterialUi_Types.Number.t=?,
  ~defaultPage: MaterialUi_Types.Number.t=?,
  ~disabled: bool=?,
  ~getItemAriaLabel: (string, int, bool) => string=?,
  ~hideNextButton: bool=?,
  ~hidePrevButton: bool=?,
  ~onChange: (ReactEvent.Form.t, int) => unit=?,
  ~page: MaterialUi_Types.Number.t=?,
  ~renderItem: {
    "color": Color.t,
    "shape": Shape.t,
    "size": Size.t,
    "variant": Variant.t,
    "page": int,
    "selected": bool,
    "disabled": bool,
  } => React.element=?,
  ~shape: shape=?,
  ~showFirstButton: bool=?,
  ~showLastButton: bool=?,
  ~siblingCount: MaterialUi_Types.Number.t=?,
  ~size: size=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Pagination"
