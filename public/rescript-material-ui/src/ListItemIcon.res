module Classes = {
  type t = {"root": option<string>, "alignItemsFlexStart": option<string>}
  @obj external make: (~root: string=?, ~alignItemsFlexStart: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ListItemIcon"
