module Classes = {
  type t = {
    "root": option<string>,
    "colorDefault": option<string>,
    "circle": option<string>,
    "circular": option<string>,
    "rounded": option<string>,
    "square": option<string>,
    "img": option<string>,
    "fallback": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~colorDefault: string=?,
    ~circle: string=?,
    ~circular: string=?,
    ~rounded: string=?,
    ~square: string=?,
    ~img: string=?,
    ~fallback: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type variant = [#circle | #circular | #rounded | #square]

@react.component @module("@material-ui/core")
external make: (
  ~alt: string=?,
  ~children: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~imgProps: {..}=?,
  ~sizes: string=?,
  ~src: string=?,
  ~srcSet: string=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Avatar"
