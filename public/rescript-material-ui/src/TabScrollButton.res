module Classes = {
  type t = {"root": option<string>, "vertical": option<string>, "disabled": option<string>}
  @obj external make: (~root: string=?, ~vertical: string=?, ~disabled: string=?, unit) => t = ""
}

type direction = [#left | #right]

type orientation = [#horizontal | #vertical]

@react.component @module("@material-ui/core")
external make: (
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~direction: direction,
  ~disabled: bool=?,
  ~orientation: orientation,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TabScrollButton"
