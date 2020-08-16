module Classes = {
  type t = {
    .
    "root": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "marked": option(string),
    "vertical": option(string),
    "disabled": option(string),
    "rail": option(string),
    "track": option(string),
    "trackFalse": option(string),
    "trackInverted": option(string),
    "thumb": option(string),
    "thumbColorPrimary": option(string),
    "thumbColorSecondary": option(string),
    "active": option(string),
    "focusVisible": option(string),
    "valueLabel": option(string),
    "mark": option(string),
    "markActive": option(string),
    "markLabel": option(string),
    "markLabelActive": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~marked: string=?,
      ~vertical: string=?,
      ~disabled: string=?,
      ~rail: string=?,
      ~track: string=?,
      ~trackFalse: string=?,
      ~trackInverted: string=?,
      ~thumb: string=?,
      ~thumbColorPrimary: string=?,
      ~thumbColorSecondary: string=?,
      ~active: string=?,
      ~focusVisible: string=?,
      ~valueLabel: string=?,
      ~mark: string=?,
      ~markActive: string=?,
      ~markLabel: string=?,
      ~markLabelActive: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Primary | `Secondary];

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

type orientation = [ | `Horizontal | `Vertical];

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

module Track: {
  type t;
  let normal: t;
  let _false: t;
  let inverted: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let normal = Any("normal");
  let _false = Any(false);
  let inverted = Any("inverted");
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

type valueLabelDisplay = [ | `On | `Auto | `Off];

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
    ~aria_labelledby: string=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~color: [@bs.string] [
              | [@bs.as "primary"] `Primary
              | [@bs.as "secondary"] `Secondary
            ]
              =?,
    ~component: Component.t=?,
    ~defaultValue: DefaultValue.t=?,
    ~disabled: bool=?,
    ~getAriaLabel: int => string=?,
    ~getAriaValueText: (int, int) => string=?,
    ~marks: Marks.t=?,
    ~max: MaterialUi_Types.Number.t=?,
    ~min: MaterialUi_Types.Number.t=?,
    ~name: string=?,
    ~onChange: (ReactEvent.Form.t, int) => unit=?,
    ~onChangeCommitted: (ReactEvent.Form.t, int) => unit=?,
    ~onMouseDown: ReactEvent.Mouse.t => unit=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ]
                    =?,
    ~scale: MaterialUi_Types.any=?,
    ~step: MaterialUi_Types.Number.t=?,
    ~_ThumbComponent: ThumbComponent.t=?,
    ~track: Track.t=?,
    ~value: Value.t=?,
    ~_ValueLabelComponent: ValueLabelComponent.t=?,
    ~valueLabelDisplay: [@bs.string] [
                          | [@bs.as "on"] `On
                          | [@bs.as "auto"] `Auto
                          | [@bs.as "off"] `Off
                        ]
                          =?,
    ~valueLabelFormat: ValueLabelFormat.t=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Slider";
