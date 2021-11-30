@react.component @module("@material-ui/core")
external make: (
  ~children: React.element=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "RootRef"
