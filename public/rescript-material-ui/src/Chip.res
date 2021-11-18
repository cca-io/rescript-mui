module Classes = {
  type t = {
    "root": option<string>,
    "sizeSmall": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "disabled": option<string>,
    "clickable": option<string>,
    "clickableColorPrimary": option<string>,
    "clickableColorSecondary": option<string>,
    "deletable": option<string>,
    "deletableColorPrimary": option<string>,
    "deletableColorSecondary": option<string>,
    "outlined": option<string>,
    "outlinedPrimary": option<string>,
    "outlinedSecondary": option<string>,
    "avatar": option<string>,
    "avatarSmall": option<string>,
    "avatarColorPrimary": option<string>,
    "avatarColorSecondary": option<string>,
    "icon": option<string>,
    "iconSmall": option<string>,
    "iconColorPrimary": option<string>,
    "iconColorSecondary": option<string>,
    "label": option<string>,
    "labelSmall": option<string>,
    "deleteIcon": option<string>,
    "deleteIconSmall": option<string>,
    "deleteIconColorPrimary": option<string>,
    "deleteIconColorSecondary": option<string>,
    "deleteIconOutlinedColorPrimary": option<string>,
    "deleteIconOutlinedColorSecondary": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~sizeSmall: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~disabled: string=?,
    ~clickable: string=?,
    ~clickableColorPrimary: string=?,
    ~clickableColorSecondary: string=?,
    ~deletable: string=?,
    ~deletableColorPrimary: string=?,
    ~deletableColorSecondary: string=?,
    ~outlined: string=?,
    ~outlinedPrimary: string=?,
    ~outlinedSecondary: string=?,
    ~avatar: string=?,
    ~avatarSmall: string=?,
    ~avatarColorPrimary: string=?,
    ~avatarColorSecondary: string=?,
    ~icon: string=?,
    ~iconSmall: string=?,
    ~iconColorPrimary: string=?,
    ~iconColorSecondary: string=?,
    ~label: string=?,
    ~labelSmall: string=?,
    ~deleteIcon: string=?,
    ~deleteIconSmall: string=?,
    ~deleteIconColorPrimary: string=?,
    ~deleteIconColorSecondary: string=?,
    ~deleteIconOutlinedColorPrimary: string=?,
    ~deleteIconOutlinedColorSecondary: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type size = [#medium | #small]

type variant = [#default | #outlined]

@react.component @module("@material-ui/core")
external make: (
  ~avatar: React.element=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~clickable: bool=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~deleteIcon: React.element=?,
  ~disabled: bool=?,
  ~icon: React.element=?,
  ~label: React.element=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~onDelete: ReactEvent.Synthetic.t => unit=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~onKeyUp: ReactEvent.Keyboard.t => unit=?,
  ~size: size=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Chip"
