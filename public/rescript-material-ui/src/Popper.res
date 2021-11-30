module AnchorEl = {
  type t
  external obj: {..} => t = "%identity"
  external anchorEl_func: Any.t => t = "%identity"
}

module Children = {
  type t
  external element: React.element => t = "%identity"
  external children_func: Any.t => t = "%identity"
}

module Container = {
  type t
  external custom: Dom.element => t = "%identity"
  external element: React.element => t = "%identity"
  external container_func: Any.t => t = "%identity"
}

type placement = [
  | #"bottom-end"
  | #"bottom-start"
  | #bottom
  | #"left-end"
  | #"left-start"
  | #left
  | #"right-end"
  | #"right-start"
  | #right
  | #"top-end"
  | #"top-start"
  | #top
]

@react.component @module("@material-ui/core")
external make: (
  ~anchorEl: AnchorEl.t=?,
  ~children: React.element=?,
  ~container: Container.t=?,
  ~disablePortal: bool=?,
  ~keepMounted: bool=?,
  ~modifiers: {..}=?,
  ~\"open": bool,
  ~placement: placement=?,
  ~popperOptions: {..}=?,
  ~style: ReactDOM.Style.t=?,
  ~transition: bool=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Popper"
