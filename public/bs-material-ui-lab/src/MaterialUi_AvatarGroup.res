module Classes = {
  type t = {"root": option<string>, "avatar": option<string>}
  @obj external make: (~root: string=?, ~avatar: string=?, unit) => t = ""
}

module Spacing_enum: {
  type t
  let medium: t
  let small: t
} = {
  @unboxed
  type rec t = Any('a): t

  let medium = Any("medium")
  let small = Any("small")
}

module Spacing: {
  type t
  let enum: Spacing_enum.t => t
  let int: int => t
  let float: float => t
} = {
  @unboxed
  type rec t = Any('a): t
  let enum = (v: Spacing_enum.t) => Any(v)
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
}

@react.component @module("@material-ui/lab")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~max: MaterialUi_Types.Number.t=?,
  ~spacing: Spacing.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "AvatarGroup"
