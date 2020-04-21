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
    "root": option(option(string)),
    "rounded": option(option(string)),
    "expanded": option(option(string)),
    "disabled": option(option(string)),
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
    ~component: option(Component.t)=?,
    ~elevation: option(MaterialUi_Types.Number.t)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "elevation"] `Elevation
                  | [@bs.as "outlined"] `Outlined
                ],
              )
                =?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~defaultExpanded: option(bool)=?,
    ~disabled: option(bool)=?,
    ~expanded: option(bool)=?,
    ~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
    ~square: option(bool)=?,
    ~_TransitionComponent: option(TransitionComponent.t)=?,
    ~_TransitionProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~id: option(string)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ExpansionPanel";
