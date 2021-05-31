@react.component @module("@material-ui/lab")
external make: (
  ~children: 'children=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TabList"
