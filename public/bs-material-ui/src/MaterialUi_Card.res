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

type variant = [#elevation | #outlined]

module Classes = {
  type t = {"root": option<string>}
  @obj external make: (~root: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~square: bool=?,
  ~variant: variant=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~raised: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Card"
