module Component = {
  type t
  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "focused": option<string>,
    "disabled": option<string>,
    "error": option<string>,
    "required": option<string>,
    "asterisk": option<string>,
    "formControl": option<string>,
    "marginDense": option<string>,
    "shrink": option<string>,
    "animated": option<string>,
    "filled": option<string>,
    "outlined": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~focused: string=?,
    ~disabled: string=?,
    ~error: string=?,
    ~required: string=?,
    ~asterisk: string=?,
    ~formControl: string=?,
    ~marginDense: string=?,
    ~shrink: string=?,
    ~animated: string=?,
    ~filled: string=?,
    ~outlined: string=?,
    unit,
  ) => t = ""
}

type color = [#primary | #secondary]

type margin = [#dense]

type variant = [#filled | #outlined | #standard]

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~filled: bool=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~disableAnimation: bool=?,
  ~disabled: bool=?,
  ~error: bool=?,
  ~focused: bool=?,
  ~margin: margin=?,
  ~required: bool=?,
  ~shrink: bool=?,
  ~variant: variant=?,
  ~htmlFor: string,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "InputLabel"
