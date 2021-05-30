type align = [#inherit | #left | #center | #right | #justify]

module Classes = {
  type t = {
    "root": option<string>,
    "body2": option<string>,
    "body1": option<string>,
    "caption": option<string>,
    "button": option<string>,
    "h1": option<string>,
    "h2": option<string>,
    "h3": option<string>,
    "h4": option<string>,
    "h5": option<string>,
    "h6": option<string>,
    "subtitle1": option<string>,
    "subtitle2": option<string>,
    "overline": option<string>,
    "srOnly": option<string>,
    "alignLeft": option<string>,
    "alignCenter": option<string>,
    "alignRight": option<string>,
    "alignJustify": option<string>,
    "noWrap": option<string>,
    "gutterBottom": option<string>,
    "paragraph": option<string>,
    "colorInherit": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "colorTextPrimary": option<string>,
    "colorTextSecondary": option<string>,
    "colorError": option<string>,
    "displayInline": option<string>,
    "displayBlock": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~body2: string=?,
    ~body1: string=?,
    ~caption: string=?,
    ~button: string=?,
    ~h1: string=?,
    ~h2: string=?,
    ~h3: string=?,
    ~h4: string=?,
    ~h5: string=?,
    ~h6: string=?,
    ~subtitle1: string=?,
    ~subtitle2: string=?,
    ~overline: string=?,
    ~srOnly: string=?,
    ~alignLeft: string=?,
    ~alignCenter: string=?,
    ~alignRight: string=?,
    ~alignJustify: string=?,
    ~noWrap: string=?,
    ~gutterBottom: string=?,
    ~paragraph: string=?,
    ~colorInherit: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~colorTextPrimary: string=?,
    ~colorTextSecondary: string=?,
    ~colorError: string=?,
    ~displayInline: string=?,
    ~displayBlock: string=?,
    unit,
  ) => t = ""
}

type color = [#initial | #inherit | #primary | #secondary | #textPrimary | #textSecondary | #error]

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

type display = [#initial | #block | #inline]

type variant = [
  | #h1
  | #h2
  | #h3
  | #h4
  | #h5
  | #h6
  | #subtitle1
  | #subtitle2
  | #body1
  | #body2
  | #caption
  | #button
  | #overline
  | #srOnly
  | #inherit
]

@react.component @module("@material-ui/core")
external make: (
  ~align: align=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~display: display=?,
  ~gutterBottom: bool=?,
  ~noWrap: bool=?,
  ~paragraph: bool=?,
  ~variant: variant=?,
  ~variantMapping: {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Typography"
