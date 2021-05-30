module Classes = {
  type t = {"root": option<string>, "spacing": option<string>}
  @obj external make: (~root: string=?, ~spacing: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disableSpacing: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ExpansionPanelActions"
