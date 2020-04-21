module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "grouped": option(option(string)),
    "groupedSizeSmall": option(option(string)),
    "groupedSizeLarge": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~grouped: string=?,
      ~groupedSizeSmall: string=?,
      ~groupedSizeLarge: string=?,
      unit
    ) =>
    t;
};

type size = [ | `Large | `Medium | `Small];

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
