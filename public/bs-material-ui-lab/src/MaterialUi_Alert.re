module Classes = {
  type t = {
    .
    "root": option(string),
    "standardSuccess": option(string),
    "standardInfo": option(string),
    "standardWarning": option(string),
    "standardError": option(string),
    "outlinedSuccess": option(string),
    "outlinedInfo": option(string),
    "outlinedWarning": option(string),
    "outlinedError": option(string),
    "filledSuccess": option(string),
    "filledInfo": option(string),
    "filledWarning": option(string),
    "filledError": option(string),
    "icon": option(string),
    "message": option(string),
    "action": option(string),
  };
  [@bs.obj]
  external make:
    (
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
      unit
    ) =>
    t;
};

type color = [ | `Error | `Info | `Success | `Warning];

module IconMapping = {
  type t = {
    .
    "error": option(React.element),
    "info": option(React.element),
    "success": option(React.element),
    "warning": option(React.element),
  };
  [@bs.obj]
  external make:
    (
      ~error: React.element=?,
      ~info: React.element=?,
      ~success: React.element=?,
      ~warning: React.element=?,
      unit
    ) =>
    t;
};

type severity = [ | `Error | `Info | `Success | `Warning];

type variant = [ | `Filled | `Outlined | `Standard];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~action: React.element=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~closeText: string=?,
    ~color: [@bs.string] [
              | [@bs.as "error"] `Error
              | [@bs.as "info"] `Info
              | [@bs.as "success"] `Success
              | [@bs.as "warning"] `Warning
            ]
              =?,
    ~icon: React.element=?,
    ~iconMapping: IconMapping.t=?,
    ~onClose: ReactEvent.Synthetic.t => unit=?,
    ~role: string=?,
    ~severity: [@bs.string] [
                 | [@bs.as "error"] `Error
                 | [@bs.as "info"] `Info
                 | [@bs.as "success"] `Success
                 | [@bs.as "warning"] `Warning
               ]
                 =?,
    ~variant: [@bs.string] [
                | [@bs.as "filled"] `Filled
                | [@bs.as "outlined"] `Outlined
                | [@bs.as "standard"] `Standard
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Alert";
