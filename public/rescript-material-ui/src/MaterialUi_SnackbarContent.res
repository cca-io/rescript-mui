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
  type t = {"root": option<string>, "message": option<string>, "action": option<string>}
  @obj external make: (~root: string=?, ~message: string=?, ~action: string=?, unit) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~component: Component.t=?,
  ~elevation: MaterialUi_Types.Number.t=?,
  ~square: bool=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~action: React.element=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~message: React.element=?,
  ~role: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "SnackbarContent"
