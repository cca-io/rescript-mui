type align = [#inherit | #left | #center | #right | #justify]

type display = [#initial | #block | #inline]

module Classes = {
  type t = {
    "root": option<string>,
    "underlineNone": option<string>,
    "underlineHover": option<string>,
    "underlineAlways": option<string>,
    "button": option<string>,
    "focusVisible": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~underlineNone: string=?,
    ~underlineHover: string=?,
    ~underlineAlways: string=?,
    ~button: string=?,
    ~focusVisible: string=?,
    unit,
  ) => t = ""
}

type color = [#initial | #inherit | #primary | #secondary | #textPrimary | #textSecondary | #error]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type underline = [#none | #hover | #always]

type rel = [
  | #alternate
  | #author
  | #bookmark
  | #"external"
  | #help
  | #license
  | #next
  | #nofollow
  | #noreferrer
  | #noopener
  | #prev
  | #search
  | #tag
]

@react.component @module("@material-ui/core")
external make: (
  ~align: align=?,
  ~display: display=?,
  ~gutterBottom: bool=?,
  ~noWrap: bool=?,
  ~paragraph: bool=?,
  ~variantMapping: {..}=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~\"TypographyClasses": {..}=?,
  ~underline: underline=?,
  ~variant: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~href: string=?,
  ~target: string=?,
  ~rel: rel=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Link"
