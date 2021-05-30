module Classes = {
  type t = {
    "root": option<string>,
    "defaultGrey": option<string>,
    "outlinedGrey": option<string>,
    "defaultPrimary": option<string>,
    "outlinedPrimary": option<string>,
    "defaultSecondary": option<string>,
    "outlinedSecondary": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~defaultGrey: string=?,
    ~outlinedGrey: string=?,
    ~defaultPrimary: string=?,
    ~outlinedPrimary: string=?,
    ~defaultSecondary: string=?,
    ~outlinedSecondary: string=?,
    unit,
  ) => t = ""
}

type color = [#grey | #inherit | #primary | #secondary]

type variant = [#default | #outlined]

@react.component @module("@material-ui/lab")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~color: color=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "TimelineDot"
