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
  ~children: 'children=?,
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
