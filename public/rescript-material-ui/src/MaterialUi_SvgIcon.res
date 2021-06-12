module Classes = {
  type t = {
    "root": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "colorAction": option<string>,
    "colorError": option<string>,
    "colorDisabled": option<string>,
    "fontSizeInherit": option<string>,
    "fontSizeSmall": option<string>,
    "fontSizeLarge": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~colorAction: string=?,
    ~colorError: string=?,
    ~colorDisabled: string=?,
    ~fontSizeInherit: string=?,
    ~fontSizeSmall: string=?,
    ~fontSizeLarge: string=?,
    unit,
  ) => t = ""
}

type color = [#action | #disabled | #error | #inherit | #primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type fontSize = [#default | #inherit | #large | #small]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~fontSize: fontSize=?,
  ~htmlColor: string=?,
  ~shapeRendering: string=?,
  ~titleAccess: string=?,
  ~viewBox: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SvgIcon"
