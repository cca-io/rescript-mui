module Classes = {
  type t = {
    "root": option<string>,
    "disabled": option<string>,
    "selected": option<string>,
    "label": option<string>,
    "sizeSmall": option<string>,
    "sizeLarge": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~disabled: string=?,
    ~selected: string=?,
    ~label: string=?,
    ~sizeSmall: string=?,
    ~sizeLarge: string=?,
    unit,
  ) => t = ""
}

type size = [#small | #medium | #large]

@react.component @module("@material-ui/lab")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disabled: bool=?,
  ~disableFocusRipple: bool=?,
  ~disableRipple: bool=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~onClick: ReactEvent.Mouse.t => unit=?,
  ~selected: bool=?,
  ~size: size=?,
  ~value: MaterialUi.Any.t,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ToggleButton"
