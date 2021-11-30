module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type variant = [#elevation | #outlined]

module Classes = {
  type t = {
    "root": option<string>,
    "positionFixed": option<string>,
    "positionAbsolute": option<string>,
    "positionSticky": option<string>,
    "positionStatic": option<string>,
    "positionRelative": option<string>,
    "colorDefault": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "colorInherit": option<string>,
    "colorTransparent": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~positionFixed: string=?,
    ~positionAbsolute: string=?,
    ~positionSticky: string=?,
    ~positionStatic: string=?,
    ~positionRelative: string=?,
    ~colorDefault: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~colorInherit: string=?,
    ~colorTransparent: string=?,
    unit,
  ) => t = ""
}

type color = [#default | #inherit | #primary | #secondary | #transparent]

type position = [#absolute | #fixed | #relative | #static | #sticky]

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~elevation: Number.t=?,
  ~square: bool=?,
  ~variant: variant=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~position: position=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "AppBar"
