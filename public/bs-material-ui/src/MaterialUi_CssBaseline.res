module Classes = {
  type t = {"@global": option<string>}
  @obj external make: (~\"@global": string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "CssBaseline"
