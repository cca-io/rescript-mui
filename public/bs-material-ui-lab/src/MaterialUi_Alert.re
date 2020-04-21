module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "standardSuccess": option(option(string)),
    "standardInfo": option(option(string)),
    "standardWarning": option(option(string)),
    "standardError": option(option(string)),
    "outlinedSuccess": option(option(string)),
    "outlinedInfo": option(option(string)),
    "outlinedWarning": option(option(string)),
    "outlinedError": option(option(string)),
    "filledSuccess": option(option(string)),
    "filledInfo": option(option(string)),
    "filledWarning": option(option(string)),
    "filledError": option(option(string)),
    "icon": option(option(string)),
    "message": option(option(string)),
    "action": option(option(string)),
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
    "error": option(option(React.element)),
    "info": option(option(React.element)),
    "success": option(option(React.element)),
    "warning": option(option(React.element)),
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
    ~action: option(React.element)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~closeText: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "error"] `Error
                | [@bs.as "info"] `Info
                | [@bs.as "success"] `Success
                | [@bs.as "warning"] `Warning
              ],
            )
              =?,
    ~icon: option(React.element)=?,
    ~iconMapping: option(IconMapping.t)=?,
    ~onClose: option(ReactEvent.Synthetic.t => unit)=?,
    ~role: option(string)=?,
    ~severity: option(
                 [@bs.string] [
                   | [@bs.as "error"] `Error
                   | [@bs.as "info"] `Info
                   | [@bs.as "success"] `Success
                   | [@bs.as "warning"] `Warning
                 ],
               )
                 =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "filled"] `Filled
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "standard"] `Standard
                ],
              )
                =?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Alert";
