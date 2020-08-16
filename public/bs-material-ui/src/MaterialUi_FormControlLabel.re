module Classes = {
  type t = {
    .
    "root": option(string),
    "labelPlacementStart": option(string),
    "labelPlacementTop": option(string),
    "labelPlacementBottom": option(string),
    "disabled": option(string),
    "label": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~labelPlacementStart: string=?,
      ~labelPlacementTop: string=?,
      ~labelPlacementBottom: string=?,
      ~disabled: string=?,
      ~label: string=?,
      unit
    ) =>
    t;
};

type labelPlacement = [ | `Bottom | `End | `Start | `Top];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~checked: bool=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~control: React.element,
    ~disabled: bool=?,
    ~label: React.element=?,
    ~labelPlacement: [@bs.string] [
                       | [@bs.as "bottom"] `Bottom
                       | [@bs.as "end"] `End
                       | [@bs.as "start"] `Start
                       | [@bs.as "top"] `Top
                     ]
                       =?,
    ~name: string=?,
    ~onChange: ReactEvent.Form.t => unit=?,
    ~value: MaterialUi_Types.any=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "FormControlLabel";
