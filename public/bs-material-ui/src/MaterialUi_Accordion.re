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
    "rounded": option(string),
    "expanded": option(string),
    "disabled": option(string),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~rounded: string=?,
      ~expanded: string=?,
      ~disabled: string=?,
      unit
    ) =>
    t;
};

module TransitionComponent: {
  type t;
  let string: string => t;
  let transitionComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let transitionComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: Component.t=?,
    ~elevation: MaterialUi_Types.Number.t=?,
    ~variant: [@bs.string] [
                | [@bs.as "elevation"] `Elevation
                | [@bs.as "outlined"] `Outlined
              ]
                =?,
    ~children: 'children=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~defaultExpanded: bool=?,
    ~disabled: bool=?,
    ~expanded: bool=?,
    ~onChange: (ReactEvent.Form.t, bool) => unit=?,
    ~square: bool=?,
    ~_TransitionComponent: TransitionComponent.t=?,
    ~_TransitionProps: Js.t({..})=?,
    ~id: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Accordion";
