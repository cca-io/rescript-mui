module Classes = {
  type t = {
    "root": option<string>,
    "filled": option<string>,
    "positionStart": option<string>,
    "positionEnd": option<string>,
    "disablePointerEvents": option<string>,
    "hiddenLabel": option<string>,
    "marginDense": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~filled: string=?,
    ~positionStart: string=?,
    ~positionEnd: string=?,
    ~disablePointerEvents: string=?,
    ~hiddenLabel: string=?,
    ~marginDense: string=?,
    unit,
  ) => t = ""
}

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

type position = [#start | #end]

type variant = [#standard | #outlined | #filled]

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~component: Component.t=?,
  ~disablePointerEvents: bool=?,
  ~disableTypography: bool=?,
  ~muiFormControl: {..}=?,
  ~position: position=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "InputAdornment"
