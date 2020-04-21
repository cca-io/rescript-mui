module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "disabled": option(option(string)),
    "selected": option(option(string)),
    "label": option(option(string)),
    "sizeSmall": option(option(string)),
    "sizeLarge": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~disabled: string=?,
      ~selected: string=?,
      ~label: string=?,
      ~sizeSmall: string=?,
      ~sizeLarge: string=?,
      unit
    ) =>
    t;
};

type size = [ | `Small | `Medium | `Large];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~disabled: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~onClick: option(ReactEvent.Mouse.t => unit)=?,
    ~selected: option(bool)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "small"] `Small
               | [@bs.as "medium"] `Medium
               | [@bs.as "large"] `Large
             ],
           )
             =?,
    ~value: MaterialUi_Types.any,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ToggleButton";
