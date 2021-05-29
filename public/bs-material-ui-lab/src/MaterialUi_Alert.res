module Classes = {
  type t = {
    "root": option<string>,
    "standardSuccess": option<string>,
    "standardInfo": option<string>,
    "standardWarning": option<string>,
    "standardError": option<string>,
    "outlinedSuccess": option<string>,
    "outlinedInfo": option<string>,
    "outlinedWarning": option<string>,
    "outlinedError": option<string>,
    "filledSuccess": option<string>,
    "filledInfo": option<string>,
    "filledWarning": option<string>,
    "filledError": option<string>,
    "icon": option<string>,
    "message": option<string>,
    "action": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~standardSuccess: string=?,
    ~standardInfo: string=?,
    ~standardWarning: string=?,
    ~standardError: string=?,
    ~outlinedSuccess: string=?,
    ~outlinedInfo: string=?,
    ~outlinedWarning: string=?,
    ~outlinedError: string=?,
    ~filledSuccess: string=?,
    ~filledInfo: string=?,
    ~filledWarning: string=?,
    ~filledError: string=?,
    ~icon: string=?,
    ~message: string=?,
    ~action: string=?,
    unit,
  ) => t = ""
}

type color = [#error | #info | #success | #warning]

module IconMapping = {
  type t = {
    "error": option<React.element>,
    "info": option<React.element>,
    "success": option<React.element>,
    "warning": option<React.element>,
  }
  @obj
  external make: (
    ~error: React.element=?,
    ~info: React.element=?,
    ~success: React.element=?,
    ~warning: React.element=?,
    unit,
  ) => t = ""
}

type severity = [#error | #info | #success | #warning]

type variant = [#filled | #outlined | #standard]

@react.component @module("@material-ui/lab")
external make: (
  ~action: React.element=?,
  ~children: 'children=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~closeText: string=?,
  ~color: color=?,
  ~icon: React.element=?,
  ~iconMapping: IconMapping.t=?,
  ~onClose: ReactEvent.Synthetic.t => unit=?,
  ~role: string=?,
  ~severity: severity=?,
  ~variant: variant=?,
  ~id: string=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Alert"
