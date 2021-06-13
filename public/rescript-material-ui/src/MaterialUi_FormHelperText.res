module Classes = {
  type t = {
    "root": option<string>,
    "error": option<string>,
    "disabled": option<string>,
    "marginDense": option<string>,
    "contained": option<string>,
    "focused": option<string>,
    "filled": option<string>,
    "required": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~error: string=?,
    ~disabled: string=?,
    ~marginDense: string=?,
    ~contained: string=?,
    ~focused: string=?,
    ~filled: string=?,
    ~required: string=?,
    unit,
  ) => t = ""
}

module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

type margin = [#dense]

type variant = [#filled | #outlined | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~filled: bool=?,
  ~focused: bool=?,
  ~margin: margin=?,
  ~required: bool=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "FormHelperText"
