module Classes = {
  type t = {
    "root": option<string>,
    "expanded": option<string>,
    "selected": option<string>,
    "group": option<string>,
    "content": option<string>,
    "iconContainer": option<string>,
    "label": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~expanded: string=?,
    ~selected: string=?,
    ~group: string=?,
    ~content: string=?,
    ~iconContainer: string=?,
    ~label: string=?,
    unit,
  ) => t = ""
}

module TransitionComponent = {
  type t
  external string: string => t = "%identity"
  external transitionComponent_func: MaterialUi.Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

@react.component @module("@material-ui/lab")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~collapseIcon: React.element=?,
  ~endIcon: React.element=?,
  ~expandIcon: React.element=?,
  ~icon: React.element=?,
  ~label: React.element=?,
  ~nodeId: string,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~onIconClick: MaterialUi.Types.any=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onLabelClick: MaterialUi.Types.any=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~\"TransitionComponent": TransitionComponent.t=?,
  ~\"TransitionProps": {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TreeItem"
