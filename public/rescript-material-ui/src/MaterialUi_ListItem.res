type alignItems = [#"flex-start" | #center]

module Classes = {
  type t = {
    "root": option<string>,
    "container": option<string>,
    "focusVisible": option<string>,
    "dense": option<string>,
    "alignItemsFlexStart": option<string>,
    "disabled": option<string>,
    "divider": option<string>,
    "gutters": option<string>,
    "button": option<string>,
    "secondaryAction": option<string>,
    "selected": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~container: string=?,
    ~focusVisible: string=?,
    ~dense: string=?,
    ~alignItemsFlexStart: string=?,
    ~disabled: string=?,
    ~divider: string=?,
    ~gutters: string=?,
    ~button: string=?,
    ~secondaryAction: string=?,
    ~selected: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module ContainerComponent = {
  type t
  external string: string => t = "%identity"
  external containerComponent_func: MaterialUi_Types.any => t = "%identity"
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
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~\"ContainerComponent": ContainerComponent.t=?,
  ~\"ContainerProps": {..}=?,
  ~dense: bool=?,
  ~disabled: bool=?,
  ~disableGutters: bool=?,
  ~divider: bool=?,
  ~focusVisibleClassName: string=?,
  ~selected: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~value: Value.t=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ListItem"
