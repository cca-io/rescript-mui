type align = [#center | #inherit | #justify | #left | #right]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

type underline = [#always | #hover | #none]

type variant_enum = [
  | #body1
  | #body2
  | #button
  | #caption
  | #h1
  | #h2
  | #h3
  | #h4
  | #h5
  | #h6
  | #inherit
  | #overline
  | #subtitle1
  | #subtitle2
]

module Variant = {
  type t
  external enum: variant_enum => t = "%identity"
  external string: string => t = "%identity"
}

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

@react.component @module("@mui/material")
external make: (
  ~align: align=?,
  ~gutterBottom: bool=?,
  ~noWrap: bool=?,
  ~paragraph: bool=?,
  ~variantMapping: {..}=?,
  ~children: React.element=?,
  ~className: string=?,
  ~color: Any.t=?,
  ~component: Component.t=?,
  ~onBlur: ReactEvent.Focus.t => unit=?,
  ~onFocus: ReactEvent.Focus.t => unit=?,
  ~sx: Sx.t=?,
  ~\"TypographyClasses": {..}=?,
  ~underline: underline=?,
  ~variant: Variant.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~href: string=?,
  ~target: string=?,
  ~rel: rel=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Link"
