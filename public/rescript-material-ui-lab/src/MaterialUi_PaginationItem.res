module Classes = {
  type t = {
    "root": option<string>,
    "page": option<string>,
    "sizeSmall": option<string>,
    "sizeLarge": option<string>,
    "textPrimary": option<string>,
    "textSecondary": option<string>,
    "outlined": option<string>,
    "outlinedPrimary": option<string>,
    "outlinedSecondary": option<string>,
    "rounded": option<string>,
    "ellipsis": option<string>,
    "focusVisible": option<string>,
    "disabled": option<string>,
    "selected": option<string>,
    "icon": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~page: string=?,
    ~sizeSmall: string=?,
    ~sizeLarge: string=?,
    ~textPrimary: string=?,
    ~textSecondary: string=?,
    ~outlined: string=?,
    ~outlinedPrimary: string=?,
    ~outlinedSecondary: string=?,
    ~rounded: string=?,
    ~ellipsis: string=?,
    ~focusVisible: string=?,
    ~disabled: string=?,
    ~selected: string=?,
    ~icon: string=?,
    unit,
  ) => t = ""
}

type color = [#standard | #primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type shape = [#round | #rounded]

type size = [#small | #medium | #large]

type \"type" = [#page | #first | #last | #next | #previous | #"start-ellipsis" | #"end-ellipsis"]

type variant = [#text | #outlined]

@react.component @module("@material-ui/lab")
external make: (
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~disabled: bool=?,
  ~page: MaterialUi_Types.Number.t=?,
  ~selected: bool=?,
  ~shape: shape=?,
  ~size: size=?,
  ~\"type": \"type"=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "PaginationItem"
