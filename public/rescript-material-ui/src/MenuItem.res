type alignItems = [#"flex-start" | #center]

module ContainerComponent = {
  type t
  external string: string => t = "%identity"
  external containerComponent_func: Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "gutters": option<string>,
    "selected": option<string>,
    "dense": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~gutters: string=?,
    ~selected: string=?,
    ~dense: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Value = {
  type t
  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external arrayOf: array<string> => t = "%identity"
}

@react.component @module("@material-ui/core")
external make: (
  ~alignItems: alignItems=?,
  ~autoFocus: bool=?,
  ~button: bool=?,
  ~\"ContainerComponent": ContainerComponent.t=?,
  ~\"ContainerProps": {..}=?,
  ~divider: bool=?,
  ~focusVisibleClassName: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~dense: bool=?,
  ~disabled: bool=?,
  ~disableGutters: bool=?,
  ~\"ListItemClasses": {..}=?,
  ~role: string=?,
  ~selected: bool=?,
  ~tabIndex: Number.t=?,
  ~value: Value.t=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "MenuItem"
