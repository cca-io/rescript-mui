module Classes = {
  type t = {
    "root": option<string>,
    "sizeSmall": option<string>,
    "sizeLarge": option<string>,
    "readOnly": option<string>,
    "disabled": option<string>,
    "focusVisible": option<string>,
    "visuallyhidden": option<string>,
    "pristine": option<string>,
    "label": option<string>,
    "icon": option<string>,
    "iconEmpty": option<string>,
    "iconFilled": option<string>,
    "iconHover": option<string>,
    "iconFocus": option<string>,
    "iconActive": option<string>,
    "decimal": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~sizeSmall: string=?,
    ~sizeLarge: string=?,
    ~readOnly: string=?,
    ~disabled: string=?,
    ~focusVisible: string=?,
    ~visuallyhidden: string=?,
    ~pristine: string=?,
    ~label: string=?,
    ~icon: string=?,
    ~iconEmpty: string=?,
    ~iconFilled: string=?,
    ~iconHover: string=?,
    ~iconFocus: string=?,
    ~iconActive: string=?,
    ~decimal: string=?,
    unit,
  ) => t = ""
}

module IconContainerComponent = {
  type t
  external string: string => t = "%identity"
  external iconContainerComponent_func: Mui.Any.t => t = "%identity"
  external element: React.element => t = "%identity"
}

type size = [#large | #medium | #small]

@react.component @module("@material-ui/lab")
external make: (
  ~classes: Classes.t=?,
  ~className: string=?,
  ~defaultValue: Mui.Number.t=?,
  ~disabled: bool=?,
  ~emptyIcon: React.element=?,
  ~emptyLabelText: React.element=?,
  ~getLabelText: int => string=?,
  ~icon: React.element=?,
  ~\"IconContainerComponent": IconContainerComponent.t=?,
  ~max: Mui.Number.t=?,
  ~name: string=?,
  ~onChange: (ReactEvent.Form.t, int) => unit=?,
  ~onChangeActive: ({..}, int) => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~precision: Mui.Number.t=?,
  ~readOnly: bool=?,
  ~size: size=?,
  ~value: Mui.Number.t=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Rating"
