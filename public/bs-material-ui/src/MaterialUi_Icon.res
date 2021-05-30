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

type color = [#inherit | #primary | #secondary | #action | #error | #disabled]

module Component: {
  type t
  let string: string => t
  let callback: (unit => React.element) => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let callback = (v: unit => React.element) => Any(v)
  let element = (v: React.element) => Any(v)
}

type fontSize = [#inherit | #default | #small | #large]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~fontSize: fontSize=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Icon"
