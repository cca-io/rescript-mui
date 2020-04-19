module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    labelPlacementStart: string,
    [@bs.optional]
    labelPlacementTop: string,
    [@bs.optional]
    labelPlacementBottom: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    label: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~checked: option(bool)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~control: React.element,
    ~disabled: option(bool)=?,
    ~label: option(React.element)=?,
    ~labelPlacement: option(
                       [@bs.string] [
                         | [@bs.as "bottom"] `Bottom
                         | [@bs.as "end"] `End
                         | [@bs.as "start"] `Start
                         | [@bs.as "top"] `Top
                       ],
                     )
                       =?,
    ~name: option(string)=?,
    ~onChange: option(ReactEvent.Form.t => unit)=?,
    ~value: option(MaterialUi_Types.any)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "FormControlLabel";
