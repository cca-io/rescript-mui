module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    selected: string,
    [@bs.optional]
    label: string,
    [@bs.optional]
    sizeSmall: string,
    [@bs.optional]
    sizeLarge: string,
  };
  let make = t;
};

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
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ToggleButton";
