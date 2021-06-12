module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
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
