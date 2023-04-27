module ContentComponent = {
  type t
  external string: string => t = "%identity"
  external contentComponent_func: Mui.Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Mui.Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

@react.component @module("@mui/lab")
external make: (
  ~children: React.element=?,
  ~className: string=?,
  ~collapseIcon: React.element=?,
  ~\"ContentComponent": ContentComponent.t=?,
  ~\"ContentProps": {..}=?,
  ~disabled: bool=?,
  ~endIcon: React.element=?,
  ~expandIcon: React.element=?,
  ~icon: React.element=?,
  ~id: string=?,
  ~label: React.element=?,
  ~nodeId: string,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~sx: Sx.t=?,
  ~\"TransitionComponent": React.element=?,
  ~\"TransitionProps": {..}=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TreeItem"
