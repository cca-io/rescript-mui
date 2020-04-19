module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    standardSuccess: string,
    [@bs.optional]
    standardInfo: string,
    [@bs.optional]
    standardWarning: string,
    [@bs.optional]
    standardError: string,
    [@bs.optional]
    outlinedSuccess: string,
    [@bs.optional]
    outlinedInfo: string,
    [@bs.optional]
    outlinedWarning: string,
    [@bs.optional]
    outlinedError: string,
    [@bs.optional]
    filledSuccess: string,
    [@bs.optional]
    filledInfo: string,
    [@bs.optional]
    filledWarning: string,
    [@bs.optional]
    filledError: string,
    [@bs.optional]
    icon: string,
    [@bs.optional]
    message: string,
    [@bs.optional]
    action: string,
  };
  let make = t;
};

module IconMapping = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    error: React.element,
    [@bs.optional]
    info: React.element,
    [@bs.optional]
    success: React.element,
    [@bs.optional]
    warning: React.element,
  };
  let make = t;
};

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
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Alert";
