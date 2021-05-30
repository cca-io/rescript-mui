module AnchorEl: {
  type t
  let obj: {..} => t
  let anchorEl_func: MaterialUi_Types.any => t
} = {
  @unboxed
  type rec t = Any('a): t
  let obj = (v: {..}) => Any(v)
  let anchorEl_func = (v: MaterialUi_Types.any) => Any(v)
}

module Children: {
  type t
  let element: React.element => t
  let children_func: MaterialUi_Types.any => t
} = {
  @unboxed
  type rec t = Any('a): t
  let element = (v: React.element) => Any(v)
  let children_func = (v: MaterialUi_Types.any) => Any(v)
}

module Container: {
  type t
  let custom: Dom.element => t
  let element: React.element => t
  let container_func: MaterialUi_Types.any => t
} = {
  @unboxed
  type rec t = Any('a): t
  let custom = (v: Dom.element) => Any(v)
  let element = (v: React.element) => Any(v)
  let container_func = (v: MaterialUi_Types.any) => Any(v)
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
  ~children: 'children=?,
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
