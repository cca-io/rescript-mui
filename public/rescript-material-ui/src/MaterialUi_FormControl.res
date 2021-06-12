module Classes = {
  type t = {
    "root": option<string>,
    "marginNormal": option<string>,
    "marginDense": option<string>,
    "fullWidth": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~marginNormal: string=?,
    ~marginDense: string=?,
    ~fullWidth: string=?,
    unit,
  ) => t = ""
}

type color = [#primary | #secondary]

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type margin = [#dense | #none | #normal]

type size = [#medium | #small]

type variant = [#filled | #outlined | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~component: Component.t=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~focused: bool=?,
  ~fullWidth: bool=?,
  ~hiddenLabel: bool=?,
  ~margin: margin=?,
  ~required: bool=?,
  ~size: size=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "FormControl"
