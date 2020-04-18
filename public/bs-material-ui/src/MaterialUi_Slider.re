module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    colorPrimary: string,
    [@bs.optional]
    colorSecondary: string,
    [@bs.optional]
    marked: string,
    [@bs.optional]
    vertical: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    rail: string,
    [@bs.optional]
    track: string,
    [@bs.optional]
    trackFalse: string,
    [@bs.optional]
    trackInverted: string,
    [@bs.optional]
    thumb: string,
    [@bs.optional]
    thumbColorPrimary: string,
    [@bs.optional]
    thumbColorSecondary: string,
    [@bs.optional]
    active: string,
    [@bs.optional]
    focusVisible: string,
    [@bs.optional]
    valueLabel: string,
    [@bs.optional]
    mark: string,
    [@bs.optional]
    markActive: string,
    [@bs.optional]
    markLabel: string,
    [@bs.optional]
    markLabelActive: string,
  };
  let make = t;
};

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module DefaultValue: {
  type t;
  let int: int => t;
  let float: float => t;
  let arrayOf: array(MaterialUi_Types.Number.t) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let arrayOf = (v: array(MaterialUi_Types.Number.t)) => Any(v);
};

module Marks: {
  type t;
  let bool: bool => t;
  let array: array(MaterialUi_Types.any) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let bool = (v: bool) => Any(v);
  let array = (v: array(MaterialUi_Types.any)) => Any(v);
};

module ThumbComponent: {
  type t;
  let string: string => t;
  let thumbComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let thumbComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module Value: {
  type t;
  let int: int => t;
  let float: float => t;
  let arrayOf: array(MaterialUi_Types.Number.t) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let arrayOf = (v: array(MaterialUi_Types.Number.t)) => Any(v);
};

module ValueLabelComponent: {
  type t;
  let string: string => t;
  let valueLabelComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let valueLabelComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module ValueLabelFormat: {
  type t;
  let string: string => t;
  let valueLabelFormat_func: MaterialUi_Types.any => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let valueLabelFormat_func = (v: MaterialUi_Types.any) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~aria_labelledby: option(string)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~defaultValue: option(DefaultValue.t)=?,
    ~disabled: option(bool)=?,
    ~getAriaLabel: option(int => string)=?,
    ~getAriaValueText: option((int, int) => string)=?,
    ~marks: option(Marks.t)=?,
    ~max: option(MaterialUi_Types.Number.t)=?,
    ~min: option(MaterialUi_Types.Number.t)=?,
    ~name: option(string)=?,
    ~onChange: option((ReactEvent.Form.t, int) => unit)=?,
    ~onChangeCommitted: option((ReactEvent.Form.t, int) => unit)=?,
    ~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "horizontal"] `Horizontal
                      | [@bs.as "vertical"] `Vertical
                    ],
                  )
                    =?,
    ~scale: option(MaterialUi_Types.any)=?,
    ~step: option(MaterialUi_Types.Number.t)=?,
    ~_ThumbComponent: option(ThumbComponent.t)=?,
    ~track: option(
              [@bs.string] [
                | [@bs.as "normal"] `Normal
                | [@bs.as "false"] `False
                | [@bs.as "inverted"] `Inverted
              ],
            )
              =?,
    ~value: option(Value.t)=?,
    ~_ValueLabelComponent: option(ValueLabelComponent.t)=?,
    ~valueLabelDisplay: option(
                          [@bs.string] [
                            | [@bs.as "on"] `On
                            | [@bs.as "auto"] `Auto
                            | [@bs.as "off"] `Off
                          ],
                        )
                          =?,
    ~valueLabelFormat: option(ValueLabelFormat.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Slider";