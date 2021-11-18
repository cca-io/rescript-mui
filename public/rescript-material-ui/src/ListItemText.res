module Classes = {
  type t = {
    "root": option<string>,
    "multiline": option<string>,
    "dense": option<string>,
    "inset": option<string>,
    "primary": option<string>,
    "secondary": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~multiline: string=?,
    ~dense: string=?,
    ~inset: string=?,
    ~primary: string=?,
    ~secondary: string=?,
    unit,
  ) => t = ""
}

@react.component @module("@material-ui/core")
external make: (
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~disableTypography: bool=?,
  ~inset: bool=?,
  ~primary: React.element=?,
  ~primaryTypographyProps: {..}=?,
  ~secondary: React.element=?,
  ~secondaryTypographyProps: {..}=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "ListItemText"
