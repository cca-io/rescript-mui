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

type variant = [ | `Elevation | `Outlined];

module Classes = {
  type t = {
    .
    "root": option(string),
    "horizontal": option(string),
    "vertical": option(string),
    "alternativeLabel": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~horizontal: string=?,
      ~vertical: string=?,
      ~alternativeLabel: string=?,
      unit
    ) =>
    t;
};

type orientation = [ | `Horizontal | `Vertical];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: Component.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~square: bool=?,
    ~variant: [@bs.string] [
                | [@bs.as "elevation"] `Elevation
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~activeStep: MaterialUi_Types.Number.t=?,
    ~alternativeLabel: bool=?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~connector: React.element=?,
    ~nonLinear: bool=?,
    ~orientation: [@bs.string] [
                    | [@bs.as "horizontal"] `Horizontal
                    | [@bs.as "vertical"] `Vertical
                  ]
                    =?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Stepper";
