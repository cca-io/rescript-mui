module Classes = {
  type t = {
    "root": option<string>,
    "static": option<string>,
    "indeterminate": option<string>,
    "determinate": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "svg": option<string>,
    "circle": option<string>,
    "circleStatic": option<string>,
    "circleIndeterminate": option<string>,
    "circleDeterminate": option<string>,
    "circleDisableShrink": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~static: string=?,
    ~indeterminate: string=?,
    ~determinate: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~svg: string=?,
    ~circle: string=?,
    ~circleStatic: string=?,
    ~circleIndeterminate: string=?,
    ~circleDeterminate: string=?,
    ~circleDisableShrink: string=?,
    unit,
  ) => t = ""
}

type color = [#inherit | #primary | #secondary]

module Size = {
  type t
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external string: string => t = "%identity"
}

type variant = [#determinate | #indeterminate | #static]

@react.component @module("@material-ui/core")
external make: (
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~disableShrink: bool=?,
  ~size: Size.t=?,
  ~style: ReactDOM.Style.t=?,
  ~thickness: Number.t=?,
  ~value: Number.t=?,
  ~variant: variant=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "CircularProgress"
