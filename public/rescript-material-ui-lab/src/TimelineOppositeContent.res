module Classes = {
  type t = {"root": option<string>, "alignRight": option<string>}
  @obj external make: (~root: string=?, ~alignRight: string=?, unit) => t = ""
}

@react.component @module("@material-ui/lab")
external make: (
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TimelineOppositeContent"
