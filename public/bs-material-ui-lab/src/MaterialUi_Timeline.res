type align = [#alternate | #left | #right]

module Classes = {
  type t = {
    "root": option<string>,
    "alignLeft": option<string>,
    "alignRight": option<string>,
    "alignAlternate": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~alignLeft: string=?,
    ~alignRight: string=?,
    ~alignAlternate: string=?,
    unit,
  ) => t = ""
}

@react.component @module("@material-ui/lab")
external make: (
  ~align: align=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Timeline"
