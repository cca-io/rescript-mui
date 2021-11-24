module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external element: React.element => t = "%identity"
  external container_func: Any.t => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~container: Container.t=?,
  ~disablePortal: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Portal"
