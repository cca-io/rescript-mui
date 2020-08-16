module Classes = {
  type t = {
    .
    "root": option(string),
    "vertical": option(string),
    "grouped": option(string),
    "groupedHorizontal": option(string),
    "groupedVertical": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~vertical: string=?,
      ~grouped: string=?,
      ~groupedHorizontal: string=?,
      ~groupedVertical: string=?,
      unit
    ) =>
    t;
};

type orientation = [ | `Horizontal | `Vertical];

type size = [ | `Large | `Medium | `Small];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~exclusive: bool=?,
    ~onChange: (ReactEvent.Form.t, MaterialUi_Types.any) => unit=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ]
                    =?,
    ~size: [@bs.string] [
             | [@bs.as "large"] `Large
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~value: MaterialUi_Types.any=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "ToggleButtonGroup";
