module Classes = {
  type t = {"root": option<string>, "avatar": option<string>}
  @obj external make: (~root: string=?, ~avatar: string=?, unit) => t = ""
}

type spacing_enum = [#medium | #small]

module Spacing = {
  type t
  external enum: spacing_enum => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
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
