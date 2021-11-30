module Classes = {
  type t = {"root": option<string>, "dividers": option<string>}
  @obj external make: (~root: string=?, ~dividers: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~dividers: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "DialogContent"
