module Classes = {
  type t = {
    "root": option<string>,
    "absolute": option<string>,
    "inset": option<string>,
    "light": option<string>,
    "middle": option<string>,
    "vertical": option<string>,
    "flexItem": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~absolute: string=?,
    ~inset: string=?,
    ~light: string=?,
    ~middle: string=?,
    ~vertical: string=?,
    ~flexItem: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type orientation = [#horizontal | #vertical]

type variant = [#fullWidth | #inset | #middle]

@react.component @module("@material-ui/core")
external make: (
  ~absolute: bool=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~flexItem: bool=?,
  ~light: bool=?,
  ~orientation: orientation=?,
  ~role: string=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Divider"
