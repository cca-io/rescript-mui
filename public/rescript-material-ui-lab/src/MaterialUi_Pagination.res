module Classes = {
  type t = {"root": option<string>, "ul": option<string>}
  @obj external make: (~root: string=?, ~ul: string=?, unit) => t = ""
}

type color = [#primary | #secondary | #standard]

type shape = [#round | #rounded]

type size = [#large | #medium | #small]

type variant = [#outlined | #text]

@react.component @module("@material-ui/lab")
external make: (
  ~boundaryCount: MaterialUi_Types.Number.t=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~count: MaterialUi_Types.Number.t=?,
  ~defaultPage: MaterialUi_Types.Number.t=?,
  ~disabled: bool=?,
  ~getItemAriaLabel: (string, int, bool) => string=?,
  ~hideNextButton: bool=?,
  ~hidePrevButton: bool=?,
  ~onChange: (ReactEvent.Form.t, int) => unit=?,
  ~page: MaterialUi_Types.Number.t=?,
  ~renderItem: {
    "color": color,
    "shape": shape,
    "size": size,
    "variant": variant,
    "page": int,
    "selected": bool,
    "disabled": bool,
  } => React.element=?,
  ~shape: shape=?,
  ~showFirstButton: bool=?,
  ~showLastButton: bool=?,
  ~siblingCount: MaterialUi_Types.Number.t=?,
  ~size: size=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Pagination"
