module Classes = {
  type t = {
    "root": option<string>,
    "padding": option<string>,
    "dense": option<string>,
    "subheader": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~padding: string=?,
    ~dense: string=?,
    ~subheader: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type variant = [#menu | #selectedMenu]

@react.component @module("@material-ui/core")
external make: (
  ~classes: Classes.t=?,
  ~component: Component.t=?,
  ~dense: bool=?,
  ~disablePadding: bool=?,
  ~subheader: React.element=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~autoFocus: bool=?,
  ~autoFocusItem: bool=?,
  ~children: React.element=?,
  ~className: string=?,
  ~disabledItemsFocusable: bool=?,
  ~disableListWrap: bool=?,
  ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
  ~variant: variant=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "MenuList"
