module Classes = {
  type t = {
    "root": option<string>,
    "labelPlacementStart": option<string>,
    "labelPlacementTop": option<string>,
    "labelPlacementBottom": option<string>,
    "disabled": option<string>,
    "label": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~labelPlacementStart: string=?,
    ~labelPlacementTop: string=?,
    ~labelPlacementBottom: string=?,
    ~disabled: string=?,
    ~label: string=?,
    unit,
  ) => t = ""
}

type labelPlacement = [#bottom | #end | #start | #top]

@react.component @module("@material-ui/core")
external make: (
  ~checked: bool=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~control: React.element,
  ~disabled: bool=?,
  ~label: React.element=?,
  ~labelPlacement: labelPlacement=?,
  ~name: string=?,
  ~onChange: ReactEvent.Form.t => unit=?,
  ~value: Types.any=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "FormControlLabel"
