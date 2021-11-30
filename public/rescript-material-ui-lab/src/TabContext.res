@react.component @module("@material-ui/lab")
external make: (
  ~children: React.element=?,
  ~value: string,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TabContext"
