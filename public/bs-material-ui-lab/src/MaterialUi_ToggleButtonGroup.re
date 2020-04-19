module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    grouped: string,
    [@bs.optional]
    groupedSizeSmall: string,
    [@bs.optional]
    groupedSizeLarge: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~exclusive: option(bool)=?,
    ~onChange: option((ReactEvent.Form.t, MaterialUi_Types.any) => unit)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "large"] `Large
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~value: option(MaterialUi_Types.any)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ToggleButtonGroup";
