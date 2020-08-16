module Classes = {
  type t = {
    .
    "root": option(string),
    "disabled": option(string),
    "selected": option(string),
    "label": option(string),
    "sizeSmall": option(string),
    "sizeLarge": option(string),
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
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~disabled: bool=?,
    ~disableFocusRipple: bool=?,
    ~disableRipple: bool=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~selected: bool=?,
    ~size: [@bs.string] [
             | [@bs.as "small"] `Small
             | [@bs.as "medium"] `Medium
             | [@bs.as "large"] `Large
           ]
             =?,
    ~value: MaterialUi_Types.any,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ToggleButton";
